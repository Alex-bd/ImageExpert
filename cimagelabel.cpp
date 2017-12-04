#include "cimagelabel.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

static const int IMAGE_WIDTH = 1;
static const int IMAGE_HEIGHT = 1;
static const QSize IMAGE_SIZE = QSize(IMAGE_WIDTH, IMAGE_HEIGHT);

CImageLabel::CImageLabel(QWidget *parent) : QLabel(parent)
{
    m_pixmap = QPixmap(IMAGE_SIZE);
    m_pixmap.fill(QColor(240,240,240));
    m_mode = AUTO_ZOOM;
    m_brush = QBrush(QColor(240,240,240));

    m_scrollAreaParents = NULL;
    m_labelParents = NULL;
    m_sliderBar = NULL;
    m_zoomInBtn = NULL;
    m_zoomOutBtn = NULL;
    m_scaleVector = NULL;
    m_scaleLabel = NULL;
}

void CImageLabel::setBackground(QBrush brush)
{
    m_brush = brush;
    update();
}

void CImageLabel::setMode(PB_MODE mode)
{
    m_mode = mode;
    if(m_mode == AUTO_SIZE)
    {
        setFixedSize(m_pixmap.size());
    }
    else if(m_mode == AUTO_ZOOM)
    {
        setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
        setMinimumSize(0, 0);
    }else if(m_mode == FREE_ZOOM)
    {
        int v = m_sliderBar->value();
        m_scale = m_scaleVector->at(v)/100;
        m_newSize = m_pixmap.size()*m_scale;
        setFixedSize(m_newSize);
    }
    update();
}

void CImageLabel::resizeImage()
{
    //TODO: add resize code
    int v = m_sliderBar->value();
    m_scale = m_scaleVector->at(v)/100;
    m_newSize = m_pixmap.size()*m_scale;
    setFixedSize(m_newSize);

    paintEvent(new QPaintEvent(QRect(0,0,0,0)));
}

void CImageLabel::setParameters(QScrollArea *srollArea, QLabel *label,QSlider* sliderBar
                                ,QPushButton* zoomInBtn,QPushButton* zoomOutBtn
                                ,QVector<double>& scaleVector,QLabel* scaleLabel)
{
    m_scrollAreaParents = srollArea;
    m_labelParents = label;
    m_sliderBar = sliderBar;
    m_zoomInBtn = zoomInBtn;
    m_zoomOutBtn = zoomOutBtn;
    m_scaleVector = &scaleVector;
    m_scaleLabel = scaleLabel;
}

bool CImageLabel::setImage(QImage &image, double scale)
{
    if(image.isNull())
    {
        return false;
    }
    m_pixmap = QPixmap::fromImage(image);
    m_scale = qBound(0.01, scale, 100.0);
    if(m_mode == AUTO_SIZE)
    {
        setFixedSize(m_pixmap.size() * m_scale);
    }
    update();
    return true;
}

void CImageLabel::paintEvent(QPaintEvent * event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    if(!painter.isActive()) return;

    painter.setBackground(m_brush);
    painter.eraseRect(rect());

    double window_width, window_height;
    double image_width, image_height;
    double r1, r2;
    double m_offsetX, m_offsetY;
    switch (m_mode)
    {
    case FIXED_SIZE:
    case AUTO_SIZE://actrue size
        painter.drawPixmap(0, 0, m_pixmap);
        m_scaleLabel->setText("100%");
        m_sliderBar->setEnabled(false);
        m_zoomInBtn->setEnabled(false);
        m_zoomOutBtn->setEnabled(false);
        break;
    case FIX_SIZE_CENTRED:
        window_width = width();
        window_height = height();
        image_width = m_pixmap.width();
        image_height = m_pixmap.height();
        m_offsetX = (window_width - m_scale * image_width) / 2;
        m_offsetY = (window_height - m_scale * image_height) / 2;
        painter.translate(m_offsetX, m_offsetY);
        painter.scale(m_scale, m_scale);
        painter.drawPixmap(0, 0, m_pixmap);
        break;
    case AUTO_ZOOM://fit screen
        window_width = width();
        window_height = height();
        image_width = m_pixmap.width();
        image_height = m_pixmap.height();
        r1 = window_width / image_width;
        r2 = window_height / image_height;
        m_scaleAUTOZOOM = qMin(r1, r2);
        m_rectAUTOZOOM.setWidth(m_scaleAUTOZOOM * image_width);
        m_rectAUTOZOOM.setHeight(m_scaleAUTOZOOM * image_height);
        m_rectAUTOZOOM.setX((window_width - m_rectAUTOZOOM.width()) / 2);
        m_rectAUTOZOOM.setY((window_height - m_rectAUTOZOOM.height()) / 2);
        painter.translate(m_rectAUTOZOOM.x(), m_rectAUTOZOOM.y());
        painter.scale(m_scaleAUTOZOOM,m_scaleAUTOZOOM);
        painter.drawPixmap(0, 0, m_pixmap);
        if(m_scaleLabel!=NULL)
        {
            m_scaleLabel->setText(QString("%1%").arg(QString::number(m_scaleAUTOZOOM*100, 'f', 1)));
            m_sliderBar->setEnabled(false);
            m_zoomInBtn->setEnabled(false);
            m_zoomOutBtn->setEnabled(false);
        }
        break;
    case FREE_ZOOM:
        QPixmap pix = m_pixmap.scaled(m_newSize);
        painter.drawPixmap(0, 0, pix);
        m_scaleLabel->setText(QString("%1%").arg(QString::number(m_scale*100,'f',1)));
        m_sliderBar->setEnabled(true);
        m_zoomInBtn->setEnabled(true);
        m_zoomOutBtn->setEnabled(true);
        break;
    }
}

void CImageLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QPoint p;
    switch (m_mode)
    {
    case AUTO_SIZE://actrue size
        p=ev->pos();
        break;
    case AUTO_ZOOM://fit screen

        if(m_rectAUTOZOOM.contains(ev->pos()))
        {
            p = QPoint((ev->pos().x()-m_rectAUTOZOOM.x())/m_scaleAUTOZOOM,
                       (ev->pos().y()-m_rectAUTOZOOM.y())/m_scaleAUTOZOOM);
        }else
        {
            p = QPoint(0,0);
        }
        break;
    case FREE_ZOOM://free zoom
        p = QPoint(ev->pos().x()/m_scale,
                   ev->pos().y()/m_scale);
        break;
    default:
        break;
    }
    if(m_labelParents!=NULL)
        m_labelParents->setText(QString("%1,%2").arg(p.x()).arg(p.y()));
    QLabel::mouseMoveEvent(ev);
}


void CImageLabel::resizeEvent(QResizeEvent *event)
{
    paintEvent(new QPaintEvent(QRect(0,0,0,0)));
    QLabel::resizeEvent(event);
}

CImageLabel::~CImageLabel()
{

}

