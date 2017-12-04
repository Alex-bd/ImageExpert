//2017年6月20日
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTranslator>
#include <QTableWidgetItem>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QTime>
#include <QColor>
#include <QBrush>
#include <QPainter>
#include <QProgressBar>
#include <QLayout>
#include <QProcess>
#include <QModelIndex>
#include "FileAssistant.h"
using namespace cv;
MainWindow::MainWindow(qint64 pid,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pid(pid)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_AlwaysShowToolTips,true);
    //加载系统变量
    m_systemParmeters.loadConfig();
    //init split parameter
    ui->splitH->setStretchFactor(0,1);
    ui->splitH->setStretchFactor(1,50);
    ui->action_SaveAs->setEnabled(false);
    ui->tableWidgetHistory->setSelectionBehavior(QAbstractItemView::SelectRows);
    //ui->tableWidgetHistory->setColumnHidden(3,true);
    ui->tableWidgetLogInfo->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetLogInfo->setFont(QFont("Consolas"));
    tabifyDockWidget(ui->dockWidgetAppInfo,ui->dockWidgetVPHist);
    ui->dockWidgetVPHist->setVisible(false);



    ui->centralWidget->layout()->setContentsMargins(1,1,1,0);
    ui->scrollAreaWidgetContents->layout()->setContentsMargins(0,0,0,0);
    ui->dockWidgetContents->layout()->setContentsMargins(0,0,0,0);
    ui->dockWidgetContentsHistorgram->layout()->setContentsMargins(2,0,2,0);
    ui->dockWidgetContentsVPHist->layout()->setContentsMargins(0,0,0,0);
    //变量初始化
    m_scaleInidex = 3;
    m_lbuttonDown = false;
    m_workSpace = "";


    initTableWidgetContexMenus();

    initStatusBar();
    initLanguage();
    initPictureBox();
    initScales();
    createWorkSpace();


    ui->comboBoxHistorgram->addItem("RGB");
    ui->comboBoxHistorgram->addItem("R");
    ui->comboBoxHistorgram->addItem("G");
    ui->comboBoxHistorgram->addItem("B");
}

MainWindow::~MainWindow()
{
    deleteWorkSpace();
    m_systemParmeters.writeConfig();
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {

    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    //ui->label->setText(QString("double click:%1,%2").arg(event->x()).arg(event->y()));

}

///
/// \brief MainWindow::createContexMenus
///创建右键菜单
void MainWindow::initTableWidgetContexMenus()
{
    ui->tableWidgetHistory->setContextMenuPolicy(Qt::CustomContextMenu);
    m_tableWidget_popMenu = new QMenu(ui->tableWidgetHistory);
    m_export_action = new QAction(tr("Export..."),ui->tableWidgetHistory);
    m_delete_action = new QAction(tr("Delete"),ui->tableWidgetHistory);
    m_saveAs_action = new QAction(tr("Save As..."),ui->tableWidgetHistory);
    m_reload_action = new QAction(tr("Reload"),ui->tableWidgetHistory);
    m_view_action = new QAction(tr("View"),ui->tableWidgetHistory);
    m_edit_action = new QAction(tr("Edit"),ui->tableWidgetHistory);

    m_tableWidget_popMenu->addAction(m_export_action);
    m_tableWidget_popMenu->addAction(m_delete_action);
    m_tableWidget_popMenu->addAction(m_saveAs_action);
    m_tableWidget_popMenu->addAction(m_reload_action);
    m_tableWidget_popMenu->addAction(m_view_action);
    m_tableWidget_popMenu->addAction(m_edit_action);

    //绑定每个信号的槽
    connect(m_export_action,&QAction::triggered,this,&MainWindow::on_m_export_action);
    connect(m_delete_action,&QAction::triggered,this,&MainWindow::on_m_delete_action);
    connect(m_saveAs_action,&QAction::triggered,this,&MainWindow::on_m_saveAs_action);
    connect(m_reload_action,&QAction::triggered,this,&MainWindow::on_m_reload_action);
    connect(m_view_action,&QAction::triggered,this,&MainWindow::on_m_view_action);
    connect(m_edit_action,&QAction::triggered,this,&MainWindow::on_m_edit_action);
}

void MainWindow::initPictureBoxContexMenus()
{
    ui->pictureBox->setContextMenuPolicy(Qt::CustomContextMenu);
    m_picturebox_popMenu = new QMenu(ui->pictureBox);
    m_auto_size_Action = new QAction(tr("Actual size"),ui->pictureBox);
    m_auto_zoom_Action = new QAction(tr("Fit to screen"),ui->pictureBox);
    m_free_zoom_Action = new QAction(tr("Free Zoom model"),ui->pictureBox);
    m_auto_size_Action->setCheckable(true);
    m_auto_zoom_Action->setCheckable(true);
    m_free_zoom_Action->setCheckable(true);

    m_picturebox_popMenu->addAction(m_auto_size_Action);
    m_picturebox_popMenu->addAction(m_auto_zoom_Action);
    m_picturebox_popMenu->addAction(m_free_zoom_Action);
    m_auto_zoom_Action->setChecked(true);

    connect(m_auto_size_Action,&QAction::triggered,this,&MainWindow::on_m_auto_size_Action);
    connect(m_auto_zoom_Action,&QAction::triggered,this,&MainWindow::on_m_auto_zoom_Action);
    connect(m_free_zoom_Action,&QAction::triggered,this,&MainWindow::on_m_free_zoom_Action);
}

void MainWindow::initStatusBar()
{
    m_statusBarProcessBar = new QProgressBar(this);
    m_statusBarProcessBar->setMaximumSize(150,20);
    m_statusBarProcessBar->setValue(52);
    m_statusBarProcessBar->setTextVisible(true);
    ui->statusBar->addWidget(m_statusBarProcessBar,1);
    //button area
    QWidget* btnWidget = new QWidget(this);
    btnWidget->setMaximumSize(250,23);
    QGridLayout* btnLayout = new QGridLayout(btnWidget);
    m_appInfoButton = new QPushButton("App Output",btnWidget);
    m_appInfoButton->setCheckable(true);
    m_appInfoButton->setChecked(true);
    m_vProjectHistButton = new QPushButton("VPHistorgram",btnWidget);
    m_vProjectHistButton->setCheckable(true);
    btnLayout->setContentsMargins(0,0,0,0);
    btnLayout->addWidget(m_appInfoButton,0,0,Qt::AlignLeft);
    btnLayout->addWidget(m_vProjectHistButton,0,1,Qt::AlignLeft);
    ui->statusBar->addPermanentWidget(btnWidget,0);

    m_sizeInStatusBarLabel = new QLabel("        ",this);
    m_sizeInStatusBarLabel->setMaximumWidth(100);
    m_currentCursorPosLabel = new QLabel("        ",this);
    m_currentCursorPosLabel->setMaximumWidth(80);

    ui->statusBar->addPermanentWidget(m_currentCursorPosLabel,1);
    ui->statusBar->addPermanentWidget(m_sizeInStatusBarLabel,1);

    //zoomArea
    m_zoomWidget = new QWidget(this);
    m_zoomScaleLabel = new QLabel("100%");
    m_zoomInButton = new QPushButton("-",m_zoomWidget);
    m_zoomOutButton = new QPushButton("+",m_zoomWidget);
    m_zoomSlider  =  new QSlider(Qt::Orientation::Horizontal,m_zoomWidget);
    QGridLayout* layout =  new QGridLayout(m_zoomWidget);
    m_zoomScaleLabel->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    m_zoomScaleLabel->setMaximumSize(42,23);
    m_zoomScaleLabel->setMinimumSize(42,23);
    m_zoomWidget->setMaximumWidth(180);
    m_zoomInButton->setMaximumSize(23,23);
    m_zoomSlider->setMaximumSize(100,20);
    m_zoomOutButton->setMaximumSize(23,23);
    m_zoomSlider->setRange(0,10);
    m_zoomSlider->setValue(3);


    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(m_zoomScaleLabel,0,0,Qt::AlignRight);
    layout->addWidget(m_zoomInButton,0,1,Qt::AlignRight);
    layout->addWidget(m_zoomSlider,0,2,Qt::AlignRight);
    layout->addWidget(m_zoomOutButton,0,3,Qt::AlignRight);
    ui->statusBar->addPermanentWidget(m_zoomWidget,1);

    //connect
    connect(m_appInfoButton,&QPushButton::clicked,this,&MainWindow::on_m_appInfoButton_clicked);
    connect(m_vProjectHistButton,&QPushButton::clicked,this,&MainWindow::on_m_vProjectHistButton_clicked);
    connect(m_zoomSlider,&QSlider::valueChanged,this,&MainWindow::on_m_zoomSlider_changed);
    connect(m_zoomInButton,&QPushButton::clicked,this,&MainWindow::on_m_zoomInButton_clicked);
    connect(m_zoomOutButton,&QPushButton::clicked,this,&MainWindow::on_m_zoomOutButton_clicked);
}

void MainWindow::initLanguage()
{
    if(m_systemParmeters.m_language==0)
    {
        on_actionChinese_triggered();
    }else
    {
        on_actionEnglish_2_triggered();
    }

}

///
/// \brief MainWindow::addLogInformation
/// \param logInfo 日志信息
///
void MainWindow::addLogInformation(QString command,QString logInfo)
{

    QString times = QTime::currentTime().toString("hh:mm:ss ");
    int row = ui->tableWidgetLogInfo->rowCount();
    ui->tableWidgetLogInfo->insertRow(row);
    ui->tableWidgetLogInfo->setItem(row,0,new QTableWidgetItem(times));
    ui->tableWidgetLogInfo->setItem(row,1,new QTableWidgetItem(QString("[%1] ").arg(command)));
    ui->tableWidgetLogInfo->setItem(row,2,new QTableWidgetItem(logInfo));
}

///
/// \brief MainWindow::addItem2History
/// \param img 图像名
/// \param size 大小
/// \param info 信息
/// \param path 图像的全路径
///
void MainWindow::addItem2History(QString imgName, QString size, QString info, QString path)
{
    QString saveFile;
    int row = ui->tableWidgetHistory->rowCount();
    ui->tableWidgetHistory->insertRow(row);
    ui->tableWidgetHistory->setItem(row,0,new QTableWidgetItem(imgName));
    ui->tableWidgetHistory->setItem(row,1,new QTableWidgetItem(size));
    ui->tableWidgetHistory->setItem(row,2,new QTableWidgetItem(info));
    //将此文件复制一份
    saveFile = QString("%1%2.bmp").arg(m_workSpace).arg(imgName);
    imwrite(saveFile.toLocal8Bit().data(),m_img);
    ui->tableWidgetHistory->setItem(row,3,new QTableWidgetItem(saveFile));
    ui->tableWidgetHistory->scrollToBottom();
}

///
/// \brief MainWindow::cvMat2QImage
/// \param mat
/// \return
///
QImage MainWindow::cvMat2QImage(const Mat &mat)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {

        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        //qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}

///
/// \brief MainWindow::QImage2cvMat
/// \param image
/// \return
///
Mat MainWindow::QImage2cvMat(QImage &image)
{
    cv::Mat mat;
    //qDebug() << image.format();
    switch(image.format())
    {
    case QImage::Format_ARGB32:
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32_Premultiplied:
        mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
        break;
    case QImage::Format_RGB888:
        mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        cv::cvtColor(mat, mat, CV_BGR2RGB);
        break;
    case QImage::Format_Indexed8:
        mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
        break;
    }
    return mat;
}

void MainWindow::showImage(QString imageName)
{
    m_currentImgName = imageName;
    QImage img = cvMat2QImage(m_img);
    m_sizeInStatusBarLabel->setText(QString("%1×%2×%3").arg(m_img.cols).arg(m_img.rows).arg(m_img.channels()));
    ui->pictureBox->setImage(img);
}

///
/// \brief 创建临时工作空间（临时文件夹）
///
void MainWindow::createWorkSpace()
{
    QString date = QDate::currentDate().toString("yyyyMMdd");
    QString time = QTime::currentTime().toString("HHmmss");
    QChar c = m_systemParmeters.m_workSpaceFloder[m_systemParmeters.m_workSpaceFloder.length()-1];
    if(c=='\\'||c=='/')
    {
        m_workSpace = QString("%1%2%3%4/").arg(m_systemParmeters.m_workSpaceFloder).arg(date).arg(time).arg(m_pid);
    }
    else
    {
        m_workSpace = QString("%1/%2%3%4/").arg(m_systemParmeters.m_workSpaceFloder).arg(date).arg(time).arg(m_pid);
    }
    QDir dir;
    if(!dir.exists(m_workSpace))
    {
        if(!dir.mkpath(m_workSpace))
        {
            QMessageBox::warning(this,tr("Create floder"),tr("Create floder Failed!"));
        }
    }
}

void MainWindow::deleteWorkSpace()
{
    QDir dir(m_workSpace);
    dir.removeRecursively();
}

void MainWindow::initScales()
{
    m_scales.push_back(12.5);
    m_scales.push_back(25);
    m_scales.push_back(50);
    m_scales.push_back(100);
    m_scales.push_back(200);
    m_scales.push_back(300);
    m_scales.push_back(400);
    m_scales.push_back(500);
    m_scales.push_back(600);
    m_scales.push_back(700);
    m_scales.push_back(800);
}

void MainWindow::initPictureBox()
{
    initPictureBoxContexMenus();
    ui->pictureBox->setParameters(ui->scrollAreaMainDisplay,m_currentCursorPosLabel
                                  ,m_zoomSlider,m_zoomInButton,m_zoomOutButton
                                  ,m_scales,m_zoomScaleLabel);
}

///
/// \brief MainWindow::on_action_Open_triggered
///打开文件
void MainWindow::on_action_Open_triggered()
{
    ui->action_SaveAs->setEnabled(true);
    QString filter = "All Image File (*.bmp *.dib *.jpg *.jpeg *.jpe *.tiff *.tif ";
    filter += "*.png *.gif *.tga *.pbm *.pgm *.ppm *.sr *.ras);;";
    filter += "bmp (*.bmp);;";
    filter += "jpg (*.jpg;*.jpeg;*.jpe);;";
    filter += "png (*.png);;";
    filter += "gif (*.gif);;";
    filter += "sun rasters (*.sr;*.ras);;";
    filter += "TIFF files (*.tiff;*.tif)";
    QFileDialog *fileDialog = new QFileDialog(this,QString(tr("Open File")),m_systemParmeters.m_lastOpenFileFloder,filter);

    if(fileDialog->exec() == QDialog::Accepted)
    {
        QString path = fileDialog->selectedFiles()[0];
        int st = path.lastIndexOf('/')+1;
        int ed = path.lastIndexOf('.');
        QString fileName = path.mid(st,ed-st);
        m_img = imread(path.toLocal8Bit().data(),1);//

        showImage(fileName);
        m_systemParmeters.m_lastOpenFileFloder = path.left(st);
        addItem2History(fileName,QString("%1×%2").arg(m_img.cols).arg(m_img.rows),
                        QString("Open:\"%1\"").arg(path));
        addLogInformation("Open",QString("\"%1\"").arg(path));
    }
}

void MainWindow::on_action_SaveAs_triggered()
{
    //2017年7月9日00:52:25
    QString filter = "bmp (*.bmp);;";
    filter += "jpg (*.jpg);;";
    filter += "png (*.png);;";
    filter += "sun rasters (*.sr);;";
    filter += "TIFF files (*.tiff)";

    QString fileName = QFileDialog::getSaveFileName(this,tr("Save as"),QString("%1/%2.bmp").arg(m_systemParmeters.m_lastSaveFloder).arg(m_currentImgName),filter);

    if (!fileName.isEmpty())
    {
        int st = fileName.lastIndexOf('/')+1;
        QString saveFloder = fileName.left(st);
        m_systemParmeters.m_lastSaveFloder = saveFloder;

        imwrite(fileName.toLocal8Bit().data(),m_img);
        this->addLogInformation("Save",QString("\"%1\"").arg(fileName));
    }
}

///
/// \brief MainWindow::on_actionChinese_triggered
///更改语言为中文
void MainWindow::on_actionChinese_triggered()
{
    QTranslator* translator = new QTranslator();
    QApplication::installTranslator(translator);
    translator->load(QString(":/qm/cn"));
    ui->retranslateUi(this);
    translator->deleteLater();
    ui->actionChinese->setChecked(true);
    ui->actionEnglish_2->setChecked(false);
    m_systemParmeters.m_language = 0;
}

///
/// \brief MainWindow::on_actionEnglish_2_triggered
///更改语言为英文
void MainWindow::on_actionEnglish_2_triggered()
{
    QTranslator* translator = new QTranslator();
    QApplication::installTranslator(translator);
    translator->load(QString(":/qm/en"));
    ui->retranslateUi(this);
    translator->deleteLater();
    ui->actionChinese->setChecked(false);
    ui->actionEnglish_2->setChecked(true);
    m_systemParmeters.m_language = 1;

}

///
/// \brief MainWindow::on_tableWidget_customContextMenuRequested
/// \param pos
///显示右键菜单
void MainWindow::on_tableWidgetHistory_customContextMenuRequested(const QPoint &pos)
{
    int selectedNum=ui->tableWidgetHistory->selectedItems().size()/3;
    switch (selectedNum) {
    case 0:
        return;
        break;
    case 1:
        m_saveAs_action->setEnabled(true);
        m_reload_action->setEnabled(true);
        m_view_action->setEnabled(true);
        m_edit_action->setEnabled(true);
        break;
    default:
        m_saveAs_action->setEnabled(false);
        m_reload_action->setEnabled(false);
        m_view_action->setEnabled(false);
        m_edit_action->setEnabled(false);
        break;
    }
    pos;
    m_tableWidget_popMenu->exec(QCursor::pos());
}

///
/// \brief MainWindow::on_m_export_action
///右键菜单中导出命令的槽
void MainWindow::on_m_export_action()
{
    //右键菜单导出命令
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Export Directory"),
                                                 m_systemParmeters.m_lastSelectdExportFloder,
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
   if(!dir.isNull())
   {
        m_systemParmeters.m_lastSelectdExportFloder = dir;
        QList<QTableWidgetItem*> selectedItems = ui->tableWidgetHistory->selectedItems();
        bool yestoall= false;
        for(int i=0;i<selectedItems.size()/4;i++)
        {
            QString srcFile = selectedItems[i*4+3]->text();
            QString fileName = selectedItems[i*4]->text();
            QString toDir = QString("%1/%2.bmp").arg(dir).arg(fileName);
            QDir *createfile  = new QDir;
            bool exist = createfile->exists(toDir);
            if (exist)
            {
                if(yestoall)
                {
                    createfile->remove(toDir);
                }
                else
                {
                    int ret = QMessageBox::warning(this, tr("Image Expert"),
                                                   tr("Cover the exist file?")+QString("\n \"%1\"").arg(toDir),
                                                   QMessageBox::Yes | QMessageBox::No|QMessageBox::YesToAll);
                    if(ret==QMessageBox::YesToAll)
                    {
                        yestoall=true;
                        createfile->remove(toDir);
                    }
                    else if(ret==QMessageBox::Yes)
                    {
                        createfile->remove(toDir);
                    }
                    else
                    {
                        continue;
                    }
                }

            }//end if

            if(!QFile::copy(srcFile, toDir))
            {
                QMessageBox msgBox(this);
                msgBox.setIcon(QMessageBox::Warning);
                msgBox.setText(tr("An error occurred when exporting the following files!")+QString("\n \"%1\"").arg(toDir));
                msgBox.exec();
                return;
            }
            else
            {
                //this->addLogInformation("Export",QString("\"%1\",\"%2\"").arg(fileName).arg(toDir));
            }
            delete createfile;
        }
   }
}

///
/// \brief MainWindow::on_m_delete_action
///右键菜单中的删除命令的槽
void MainWindow::on_m_delete_action()
{
	QModelIndexList idx = ui->tableWidgetHistory->selectionModel()->selectedRows();
	QVector<int> rowIdx;
	for (int i = 0; i<idx.size(); i++)
	{
		rowIdx.push_back(idx.at(i).row());
	}
	qSort(rowIdx.begin(), rowIdx.end(), qGreater<int>());
	foreach(int row, rowIdx)
	{
		QString fn = ui->tableWidgetHistory->item(row, 0)->text();
		ui->tableWidgetHistory->removeRow(row);
		//this->addLogInformation("Delete",QString("\"%1\"").arg(fn));
	}
}

///
/// \brief MainWindow::on_m_saveAs_action
///右键菜单中的另存命令的槽
void MainWindow::on_m_saveAs_action()
{
    //2017年7月9日00:53:21
     QModelIndexList idx =  ui->tableWidgetHistory->selectionModel()->selectedRows();
     QString imgName = ui->tableWidgetHistory->item(idx.at(0).row(),0)->text();
     QString oldFileName = ui->tableWidgetHistory->item(idx.at(0).row(),3)->text();
     QString filter = "bmp (*.bmp);;";
     filter += "jpg (*.jpg);;";
     filter += "png (*.png);;";
     filter += "sun rasters (*.sr);;";
     filter += "TIFF files (*.tiff)";

     QString fileName = QFileDialog::getSaveFileName(this,tr("Save as"),QString("%1/%2.bmp").arg(m_systemParmeters.m_lastSaveFloder).arg(imgName),filter);


     if (!fileName.isEmpty())
     {
         Mat img = imread(oldFileName.toLocal8Bit().data(),IMREAD_UNCHANGED);
         imwrite(fileName.toLocal8Bit().data(),img);

         int st = fileName.lastIndexOf('/')+1;
         QString saveFloder = fileName.left(st);
         m_systemParmeters.m_lastSaveFloder = saveFloder;

         //this->addLogInformation("Save",QString("\"%1\"").arg(fileName));
     }
}

///
/// \brief MainWindow::on_m_reload_action
///右键菜单中重载命令的槽
void MainWindow::on_m_reload_action()
{
    //2017年7月9日14:06:39
    QModelIndexList idx =  ui->tableWidgetHistory->selectionModel()->selectedRows();
    QString imgName = ui->tableWidgetHistory->item(idx.at(0).row(),0)->text();
    QString fileName = ui->tableWidgetHistory->item(idx.at(0).row(),3)->text();
    m_img = imread(fileName.toLocal8Bit().data(),IMREAD_UNCHANGED);
    this->showImage(imgName);
    //this->addLogInformation("Reload",QString("\"%1\"").arg(imgName));
}

///
/// \brief MainWindow::on_m_view_action
///右键菜单中查看命令的槽
void MainWindow::on_m_view_action()
{
    //2017年7月9日14:08:40
    QModelIndexList idx =  ui->tableWidgetHistory->selectionModel()->selectedRows();
    QString imgName = ui->tableWidgetHistory->item(idx.at(0).row(),0)->text();
    namedWindow(imgName.toLocal8Bit().data(),0);
    imshow(imgName.toLocal8Bit().data(),m_img);
    waitKey();
    destroyWindow(imgName.toLocal8Bit().data());
    //this->addLogInformation("View",QString("\"%1\"").arg(imgName));
}

///
/// \brief MainWindow::on_m_edit_action
///右键菜单编辑命令的槽
void MainWindow::on_m_edit_action()
{
    //2017年7月9日20:06:19
    QModelIndexList idx =  ui->tableWidgetHistory->selectionModel()->selectedRows();
    QString imgName = ui->tableWidgetHistory->item(idx.at(0).row(),0)->text();
    QString fileName = ui->tableWidgetHistory->item(idx.at(0).row(),3)->text();
#ifdef Q_OS_WIN32
    QString fileNameNew = fileName.replace('/',"\\\\");
    QStringList arg;
    arg<<fileNameNew;
    QProcess *proc = new QProcess(this);
    proc->start(QString("mspaint.exe"),arg);
#elif Q_OS_LINUX
    QMessageBox.show("Not supported in LINUX OS");
#elif Q_OS_MAC
    QMessageBox.show("Not supported in MAC OS");
#endif
     //this->addLogInformation("Edit",QString("\"%1\"").arg(imgName));
}

void MainWindow::on_pictureBox_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos);
    m_picturebox_popMenu->exec(QCursor::pos());
}

void MainWindow::on_m_auto_size_Action()
{
    ui->pictureBox->setMode(CImageLabel::AUTO_SIZE);
    m_auto_size_Action->setChecked(true);
    m_auto_zoom_Action->setChecked(false);
    m_free_zoom_Action->setChecked(false);
}

void MainWindow::on_m_auto_zoom_Action()
{

    ui->pictureBox->setMode(CImageLabel::AUTO_ZOOM);
    m_auto_size_Action->setChecked(false);
    m_auto_zoom_Action->setChecked(true);
    m_free_zoom_Action->setChecked(false);
}

void MainWindow::on_m_free_zoom_Action()
{
    ui->pictureBox->setMode(CImageLabel::FREE_ZOOM);
    m_free_zoom_Action->setChecked(true);
    m_auto_size_Action->setChecked(false);
    m_auto_zoom_Action->setChecked(false);
}

void MainWindow::on_m_appInfoButton_clicked()
{
    m_appInfoButton->setChecked(!ui->dockWidgetAppInfo->isVisible());
    ui->dockWidgetAppInfo->setVisible(!ui->dockWidgetAppInfo->isVisible());

    m_vProjectHistButton->setChecked(false);
    ui->dockWidgetVPHist->setVisible(false);
}

void MainWindow::on_m_vProjectHistButton_clicked()
{
    m_vProjectHistButton->setChecked(!ui->dockWidgetVPHist->isVisible());
    ui->dockWidgetVPHist->setVisible(!ui->dockWidgetVPHist->isVisible());

    m_appInfoButton->setChecked(false);
    ui->dockWidgetAppInfo->setVisible(false);
}

void MainWindow::on_m_zoomInButton_clicked()
{
    if(m_scaleInidex>0)
    {
        m_scaleInidex -= 1;
        m_zoomSlider->setValue(m_scaleInidex);
        m_zoomScaleLabel->setText(QString("%1%").arg(m_scales[m_scaleInidex]));
        ui->pictureBox->resizeImage();
    }
}

void MainWindow::on_m_zoomOutButton_clicked()
{
    if(m_scaleInidex<m_scales.size()-1)
    {
        m_scaleInidex += 1;
        m_zoomSlider->setValue(m_scaleInidex);
        m_zoomScaleLabel->setText(QString("%1%").arg(m_scales[m_scaleInidex]));
        ui->pictureBox->resizeImage();
    }
}

void MainWindow::on_m_zoomSlider_changed()
{
    m_scaleInidex = m_zoomSlider->value();
    m_zoomScaleLabel->setText(QString("%1%").arg(m_scales[m_scaleInidex]));
    ui->pictureBox->resizeImage();
}

void MainWindow::on_tableWidgetHistory_doubleClicked(const QModelIndex &idx)
{
    //2017年7月9日21:37:37
    QString imgName = ui->tableWidgetHistory->item(idx.row(),0)->text();
    QString fileName = ui->tableWidgetHistory->item(idx.row(),3)->text();
    m_img = imread(fileName.toLocal8Bit().data(),IMREAD_UNCHANGED);
    this->showImage(imgName);
    //this->addLogInformation("Reload",QString("\"%1\"").arg(imgName));
}

void MainWindow::on_actionFileAssistant_triggered()
{
    FileAssistant *dlg = new FileAssistant(this);
    dlg->show();
}


void MainWindow::on_actionInverse_triggered()
{
    //2017年9月4日19:44:23
    QString imageName = "Inverse";
	m_img = Scalar(255,255,255)-m_img;
    this->showImage(imageName);
    addItem2History(imageName,QString("%1×%2").arg(m_img.cols).arg(m_img.rows),
                    QString("Inverse:\"%1\"").arg(m_currentImgName));
    addLogInformation("Inverse",QString("\"%1\"").arg(m_currentImgName));
}

void MainWindow::on_actiontestFunction_triggered()
{
    //2017-10-16 21:11:46
    Mat  src, hsv;
    src = m_img;
    cvtColor(src, hsv, COLOR_BGR2HSV);
    // Quantize the hue to 30 levels
    // and the saturation to 32 levels
    int hbins = 30, sbins = 32;
    int histSize[] = {hbins, sbins};
    // hue varies from 0 to 179, see cvtColor
    float hranges[] = { 0, 180 };
    // saturation varies from 0 (black-gray-white) to
    // 255 (pure spectrum color)
    float sranges[] = { 0, 256 };
    const float* ranges[] = { hranges, sranges };
    MatND hist;
    // we compute the histogram from the 0-th and 1-st channels
    int channels[] = {0, 1};

    calcHist( &hsv, 1, channels, Mat(), // do not use mask
             hist, 2, histSize, ranges,
             true, // the histogram is uniform
             false );
    double maxVal=0;
    minMaxLoc(hist, 0, &maxVal, 0, 0);

    int scale = 10;
    Mat histImg = Mat::zeros(sbins*scale, hbins*10, CV_8UC3);

    for( int h = 0; h < hbins; h++ )
        for( int s = 0; s < sbins; s++ )
        {
            float binVal = hist.at<float>(h, s);
            int intensity = cvRound(binVal*255/maxVal);
            rectangle( histImg, Point(h*scale, s*scale),
                        Point( (h+1)*scale - 1, (s+1)*scale - 1),
                        Scalar::all(intensity),
                        CV_FILLED );
        }

    namedWindow( "Source", 1 );
    imshow( "Source", src );

    namedWindow( "H-S Histogram", 1 );
    imshow( "H-S Histogram", histImg );
    waitKey();




}
