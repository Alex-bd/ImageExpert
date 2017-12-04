#ifndef CIMAGELABEL_H
#define CIMAGELABEL_H
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QScrollArea>
#include <QSlider>
#include <QPushButton>
#include <QVector>
class CImageLabel :public QLabel
{
    Q_OBJECT
public:
    explicit CImageLabel(QWidget *parent = 0);
    enum PB_MODE {FIXED_SIZE, FIX_SIZE_CENTRED, FREE_ZOOM, AUTO_ZOOM, AUTO_SIZE};
    void setMode(PB_MODE mode);
    void resizeImage();
    void setParameters(QScrollArea* scrollArea,QLabel* label,
                       QSlider* slider,QPushButton* zoomInBtn,
                       QPushButton* zoomOutBtn,QVector<double>& scaleVector
                       ,QLabel* scaleLabel);
    ~CImageLabel();
private:
    QPixmap m_pixmap;
    double m_scale;
    PB_MODE m_mode;
    QBrush m_brush;
    QVector<double>* m_scaleVector;
    QScrollArea* m_scrollAreaParents;
    QLabel* m_labelParents;
    QLabel* m_scaleLabel;
    QSlider* m_sliderBar;
    QPushButton* m_zoomOutBtn;
    QPushButton* m_zoomInBtn;
    double m_scaleAUTOZOOM;
    QRect m_rectAUTOZOOM;
    QSize m_newSize;

protected:
    void paintEvent(QPaintEvent * event);
    void mouseMoveEvent(QMouseEvent *ev) override;
    void resizeEvent(QResizeEvent *event) override;

public slots:
    bool setImage(QImage &image, double scale = 1.0);
    void setBackground(QBrush brush);
};

#endif // CIMAGELABEL_H
