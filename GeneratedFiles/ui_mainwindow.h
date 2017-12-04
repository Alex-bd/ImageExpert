/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <cimagelabel.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Open;
    QAction *action_SaveAs;
    QAction *action_Exit;
    QAction *actionEnglish;
    QAction *actionChinese;
    QAction *actionEnglish_2;
    QAction *actionFileAssistant;
    QAction *actionInverse;
    QAction *actionLog_Transformations;
    QAction *actionGamma_Transformations;
    QAction *actionPiecewise_Liear_Transformation_Functions;
    QAction *actionHistogram_Equalization;
    QAction *actionHistogram_Matching;
    QAction *actionLocal_Histogram_Processing;
    QAction *actionHistogram_Image_Enhancement;
    QAction *actionSmoothing_Spatial_Filters;
    QAction *actionSharpening_Spatial_Filters;
    QAction *actionGray_Strach;
    QAction *actionDifference;
    QAction *actionFusing;
    QAction *actionCorrelation;
    QAction *action_miu_delta_Equalization;
    QAction *actionBinary_Operation;
    QAction *actionImage_Enhance;
    QAction *actiong_Fuzzy_Techniques;
    QAction *actionSmoothing;
    QAction *actionSharpening;
    QAction *actionSelective_Filtering;
    QAction *actionNoise_Models;
    QAction *actionMorphological_Image_Processing;
    QAction *actionImage_Segmentation;
    QAction *actiontestFunction;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitH;
    QTableWidget *tableWidgetHistory;
    QScrollArea *scrollAreaMainDisplay;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    CImageLabel *pictureBox;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menuImageProcessing;
    QMenu *menuPointOperation;
    QMenu *menuSpatial_Filtering;
    QMenu *menuFrequency_Domain;
    QMenu *menuImage_Restoration_and_Reconstruction;
    QMenu *menuSettings;
    QMenu *menuLanguages_2;
    QMenu *menuVideoProcessing;
    QMenu *menu_MachineLearning;
    QMenu *menu3_D_Surfaces;
    QMenu *menu_Tools;
    QMenu *menu_View;
    QMenu *menutest;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidgetHistorgram;
    QWidget *dockWidgetContentsHistorgram;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBoxHistorgram;
    CImageLabel *labelHistorgram;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonHistSaveImg;
    QPushButton *pushButtonHistSaveData;
    QSpacerItem *verticalSpacer;
    QDockWidget *dockWidgetAppInfo;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tableWidgetLogInfo;
    QDockWidget *dockWidget_3;
    QWidget *dockWidgetContents_3;
    QPushButton *pushButton;
    QDockWidget *dockWidget_4;
    QWidget *dockWidgetContents_4;
    QDockWidget *dockWidgetVPHist;
    QWidget *dockWidgetContentsVPHist;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(865, 632);
        MainWindow->setStyleSheet(QStringLiteral(""));
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/imgs/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon);
        action_SaveAs = new QAction(MainWindow);
        action_SaveAs->setObjectName(QStringLiteral("action_SaveAs"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/imgs/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_SaveAs->setIcon(icon1);
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName(QStringLiteral("actionEnglish"));
        actionChinese = new QAction(MainWindow);
        actionChinese->setObjectName(QStringLiteral("actionChinese"));
        actionChinese->setCheckable(true);
        actionEnglish_2 = new QAction(MainWindow);
        actionEnglish_2->setObjectName(QStringLiteral("actionEnglish_2"));
        actionEnglish_2->setCheckable(true);
        actionEnglish_2->setChecked(true);
        actionFileAssistant = new QAction(MainWindow);
        actionFileAssistant->setObjectName(QStringLiteral("actionFileAssistant"));
        actionInverse = new QAction(MainWindow);
        actionInverse->setObjectName(QStringLiteral("actionInverse"));
        actionLog_Transformations = new QAction(MainWindow);
        actionLog_Transformations->setObjectName(QStringLiteral("actionLog_Transformations"));
        actionGamma_Transformations = new QAction(MainWindow);
        actionGamma_Transformations->setObjectName(QStringLiteral("actionGamma_Transformations"));
        actionPiecewise_Liear_Transformation_Functions = new QAction(MainWindow);
        actionPiecewise_Liear_Transformation_Functions->setObjectName(QStringLiteral("actionPiecewise_Liear_Transformation_Functions"));
        actionHistogram_Equalization = new QAction(MainWindow);
        actionHistogram_Equalization->setObjectName(QStringLiteral("actionHistogram_Equalization"));
        actionHistogram_Matching = new QAction(MainWindow);
        actionHistogram_Matching->setObjectName(QStringLiteral("actionHistogram_Matching"));
        actionLocal_Histogram_Processing = new QAction(MainWindow);
        actionLocal_Histogram_Processing->setObjectName(QStringLiteral("actionLocal_Histogram_Processing"));
        actionHistogram_Image_Enhancement = new QAction(MainWindow);
        actionHistogram_Image_Enhancement->setObjectName(QStringLiteral("actionHistogram_Image_Enhancement"));
        actionSmoothing_Spatial_Filters = new QAction(MainWindow);
        actionSmoothing_Spatial_Filters->setObjectName(QStringLiteral("actionSmoothing_Spatial_Filters"));
        actionSharpening_Spatial_Filters = new QAction(MainWindow);
        actionSharpening_Spatial_Filters->setObjectName(QStringLiteral("actionSharpening_Spatial_Filters"));
        actionGray_Strach = new QAction(MainWindow);
        actionGray_Strach->setObjectName(QStringLiteral("actionGray_Strach"));
        actionDifference = new QAction(MainWindow);
        actionDifference->setObjectName(QStringLiteral("actionDifference"));
        actionFusing = new QAction(MainWindow);
        actionFusing->setObjectName(QStringLiteral("actionFusing"));
        actionCorrelation = new QAction(MainWindow);
        actionCorrelation->setObjectName(QStringLiteral("actionCorrelation"));
        action_miu_delta_Equalization = new QAction(MainWindow);
        action_miu_delta_Equalization->setObjectName(QStringLiteral("action_miu_delta_Equalization"));
        actionBinary_Operation = new QAction(MainWindow);
        actionBinary_Operation->setObjectName(QStringLiteral("actionBinary_Operation"));
        actionImage_Enhance = new QAction(MainWindow);
        actionImage_Enhance->setObjectName(QStringLiteral("actionImage_Enhance"));
        actiong_Fuzzy_Techniques = new QAction(MainWindow);
        actiong_Fuzzy_Techniques->setObjectName(QStringLiteral("actiong_Fuzzy_Techniques"));
        actionSmoothing = new QAction(MainWindow);
        actionSmoothing->setObjectName(QStringLiteral("actionSmoothing"));
        actionSharpening = new QAction(MainWindow);
        actionSharpening->setObjectName(QStringLiteral("actionSharpening"));
        actionSelective_Filtering = new QAction(MainWindow);
        actionSelective_Filtering->setObjectName(QStringLiteral("actionSelective_Filtering"));
        actionNoise_Models = new QAction(MainWindow);
        actionNoise_Models->setObjectName(QStringLiteral("actionNoise_Models"));
        actionMorphological_Image_Processing = new QAction(MainWindow);
        actionMorphological_Image_Processing->setObjectName(QStringLiteral("actionMorphological_Image_Processing"));
        actionImage_Segmentation = new QAction(MainWindow);
        actionImage_Segmentation->setObjectName(QStringLiteral("actionImage_Segmentation"));
        actiontestFunction = new QAction(MainWindow);
        actiontestFunction->setObjectName(QStringLiteral("actiontestFunction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(633, 200));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        splitH = new QSplitter(centralWidget);
        splitH->setObjectName(QStringLiteral("splitH"));
        splitH->setOrientation(Qt::Horizontal);
        tableWidgetHistory = new QTableWidget(splitH);
        if (tableWidgetHistory->columnCount() < 4)
            tableWidgetHistory->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeading|Qt::AlignBottom);
        tableWidgetHistory->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignLeading|Qt::AlignBottom);
        tableWidgetHistory->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetHistory->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetHistory->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidgetHistory->setObjectName(QStringLiteral("tableWidgetHistory"));
        tableWidgetHistory->setAcceptDrops(true);
        tableWidgetHistory->setEditTriggers(QAbstractItemView::NoEditTriggers);
        splitH->addWidget(tableWidgetHistory);
        tableWidgetHistory->horizontalHeader()->setVisible(false);
        tableWidgetHistory->verticalHeader()->setVisible(false);
        tableWidgetHistory->verticalHeader()->setCascadingSectionResizes(true);
        tableWidgetHistory->verticalHeader()->setDefaultSectionSize(20);
        tableWidgetHistory->verticalHeader()->setMinimumSectionSize(17);
        tableWidgetHistory->verticalHeader()->setStretchLastSection(false);
        scrollAreaMainDisplay = new QScrollArea(splitH);
        scrollAreaMainDisplay->setObjectName(QStringLiteral("scrollAreaMainDisplay"));
        scrollAreaMainDisplay->setMinimumSize(QSize(360, 240));
        scrollAreaMainDisplay->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 358, 300));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pictureBox = new CImageLabel(scrollAreaWidgetContents);
        pictureBox->setObjectName(QStringLiteral("pictureBox"));
        pictureBox->setMinimumSize(QSize(0, 0));
        pictureBox->setCursor(QCursor(Qt::CrossCursor));
        pictureBox->setMouseTracking(true);

        horizontalLayout_2->addWidget(pictureBox);

        scrollAreaMainDisplay->setWidget(scrollAreaWidgetContents);
        splitH->addWidget(scrollAreaMainDisplay);

        horizontalLayout->addWidget(splitH);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 865, 23));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_File->setTearOffEnabled(false);
        menu_File->setToolTipsVisible(true);
        menuImageProcessing = new QMenu(menuBar);
        menuImageProcessing->setObjectName(QStringLiteral("menuImageProcessing"));
        menuPointOperation = new QMenu(menuImageProcessing);
        menuPointOperation->setObjectName(QStringLiteral("menuPointOperation"));
        menuSpatial_Filtering = new QMenu(menuImageProcessing);
        menuSpatial_Filtering->setObjectName(QStringLiteral("menuSpatial_Filtering"));
        menuFrequency_Domain = new QMenu(menuImageProcessing);
        menuFrequency_Domain->setObjectName(QStringLiteral("menuFrequency_Domain"));
        menuImage_Restoration_and_Reconstruction = new QMenu(menuImageProcessing);
        menuImage_Restoration_and_Reconstruction->setObjectName(QStringLiteral("menuImage_Restoration_and_Reconstruction"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuLanguages_2 = new QMenu(menuSettings);
        menuLanguages_2->setObjectName(QStringLiteral("menuLanguages_2"));
        menuVideoProcessing = new QMenu(menuBar);
        menuVideoProcessing->setObjectName(QStringLiteral("menuVideoProcessing"));
        menu_MachineLearning = new QMenu(menuBar);
        menu_MachineLearning->setObjectName(QStringLiteral("menu_MachineLearning"));
        menu3_D_Surfaces = new QMenu(menuBar);
        menu3_D_Surfaces->setObjectName(QStringLiteral("menu3_D_Surfaces"));
        menu_Tools = new QMenu(menuBar);
        menu_Tools->setObjectName(QStringLiteral("menu_Tools"));
        menu_View = new QMenu(menuBar);
        menu_View->setObjectName(QStringLiteral("menu_View"));
        menutest = new QMenu(menuBar);
        menutest->setObjectName(QStringLiteral("menutest"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidgetHistorgram = new QDockWidget(MainWindow);
        dockWidgetHistorgram->setObjectName(QStringLiteral("dockWidgetHistorgram"));
        dockWidgetHistorgram->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetHistorgram->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContentsHistorgram = new QWidget();
        dockWidgetContentsHistorgram->setObjectName(QStringLiteral("dockWidgetContentsHistorgram"));
        dockWidgetContentsHistorgram->setStyleSheet(QStringLiteral("border:1px solid gray;"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContentsHistorgram);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comboBoxHistorgram = new QComboBox(dockWidgetContentsHistorgram);
        comboBoxHistorgram->setObjectName(QStringLiteral("comboBoxHistorgram"));
        comboBoxHistorgram->setMaximumSize(QSize(16777215, 16777215));
        comboBoxHistorgram->setMaxVisibleItems(4);

        verticalLayout->addWidget(comboBoxHistorgram);

        labelHistorgram = new CImageLabel(dockWidgetContentsHistorgram);
        labelHistorgram->setObjectName(QStringLiteral("labelHistorgram"));
        labelHistorgram->setMinimumSize(QSize(128, 100));
        labelHistorgram->setMaximumSize(QSize(16777215, 150));

        verticalLayout->addWidget(labelHistorgram);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButtonHistSaveImg = new QPushButton(dockWidgetContentsHistorgram);
        pushButtonHistSaveImg->setObjectName(QStringLiteral("pushButtonHistSaveImg"));
        pushButtonHistSaveImg->setMinimumSize(QSize(0, 20));
        pushButtonHistSaveImg->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_5->addWidget(pushButtonHistSaveImg);

        pushButtonHistSaveData = new QPushButton(dockWidgetContentsHistorgram);
        pushButtonHistSaveData->setObjectName(QStringLiteral("pushButtonHistSaveData"));
        pushButtonHistSaveData->setMinimumSize(QSize(0, 20));
        pushButtonHistSaveData->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_5->addWidget(pushButtonHistSaveData);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout_3->addLayout(verticalLayout_2);

        dockWidgetHistorgram->setWidget(dockWidgetContentsHistorgram);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidgetHistorgram);
        dockWidgetAppInfo = new QDockWidget(MainWindow);
        dockWidgetAppInfo->setObjectName(QStringLiteral("dockWidgetAppInfo"));
        dockWidgetAppInfo->setStyleSheet(QStringLiteral("*{border: 1px solid gray;}"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tableWidgetLogInfo = new QTableWidget(dockWidgetContents);
        if (tableWidgetLogInfo->columnCount() < 3)
            tableWidgetLogInfo->setColumnCount(3);
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tableWidgetLogInfo->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tableWidgetLogInfo->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tableWidgetLogInfo->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        tableWidgetLogInfo->setObjectName(QStringLiteral("tableWidgetLogInfo"));
        tableWidgetLogInfo->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidgetLogInfo->sizePolicy().hasHeightForWidth());
        tableWidgetLogInfo->setSizePolicy(sizePolicy);
        tableWidgetLogInfo->setMinimumSize(QSize(0, 100));
        tableWidgetLogInfo->setMaximumSize(QSize(16777215, 16777215));
        tableWidgetLogInfo->setSizeIncrement(QSize(0, 150));
        tableWidgetLogInfo->setFrameShape(QFrame::StyledPanel);
        tableWidgetLogInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetLogInfo->setGridStyle(Qt::NoPen);
        tableWidgetLogInfo->setColumnCount(3);
        tableWidgetLogInfo->horizontalHeader()->setVisible(false);
        tableWidgetLogInfo->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidgetLogInfo->horizontalHeader()->setMinimumSectionSize(10);
        tableWidgetLogInfo->horizontalHeader()->setStretchLastSection(true);
        tableWidgetLogInfo->verticalHeader()->setCascadingSectionResizes(true);
        tableWidgetLogInfo->verticalHeader()->setDefaultSectionSize(20);
        tableWidgetLogInfo->verticalHeader()->setMinimumSectionSize(17);

        verticalLayout_4->addWidget(tableWidgetLogInfo);

        dockWidgetAppInfo->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidgetAppInfo);
        dockWidget_3 = new QDockWidget(MainWindow);
        dockWidget_3->setObjectName(QStringLiteral("dockWidget_3"));
        dockWidget_3->setStyleSheet(QStringLiteral("*{border: 1px solid gray;}"));
        dockWidget_3->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        pushButton = new QPushButton(dockWidgetContents_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 75, 23));
        dockWidget_3->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_3);
        dockWidget_4 = new QDockWidget(MainWindow);
        dockWidget_4->setObjectName(QStringLiteral("dockWidget_4"));
        dockWidget_4->setStyleSheet(QStringLiteral("*{border: 1px solid gray;}"));
        dockWidget_4->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        dockWidget_4->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_4);
        dockWidgetVPHist = new QDockWidget(MainWindow);
        dockWidgetVPHist->setObjectName(QStringLiteral("dockWidgetVPHist"));
        dockWidgetVPHist->setStyleSheet(QStringLiteral("*{border: 1px solid gray;}"));
        dockWidgetVPHist->setAllowedAreas(Qt::BottomDockWidgetArea);
        dockWidgetContentsVPHist = new QWidget();
        dockWidgetContentsVPHist->setObjectName(QStringLiteral("dockWidgetContentsVPHist"));
        horizontalLayout_3 = new QHBoxLayout(dockWidgetContentsVPHist);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(dockWidgetContentsVPHist);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 100));
        label->setStyleSheet(QStringLiteral("*{border: 1px solid gray;}"));

        horizontalLayout_3->addWidget(label);

        dockWidgetVPHist->setWidget(dockWidgetContentsVPHist);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidgetVPHist);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menuImageProcessing->menuAction());
        menuBar->addAction(menuVideoProcessing->menuAction());
        menuBar->addAction(menu_MachineLearning->menuAction());
        menuBar->addAction(menu3_D_Surfaces->menuAction());
        menuBar->addAction(menu_Tools->menuAction());
        menuBar->addAction(menu_View->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menutest->menuAction());
        menu_File->addAction(action_Open);
        menu_File->addAction(action_SaveAs);
        menu_File->addSeparator();
        menu_File->addAction(action_Exit);
        menuImageProcessing->addAction(menuPointOperation->menuAction());
        menuImageProcessing->addAction(actionNoise_Models);
        menuImageProcessing->addAction(menuSpatial_Filtering->menuAction());
        menuImageProcessing->addAction(actiong_Fuzzy_Techniques);
        menuImageProcessing->addSeparator();
        menuImageProcessing->addAction(menuFrequency_Domain->menuAction());
        menuImageProcessing->addSeparator();
        menuImageProcessing->addAction(menuImage_Restoration_and_Reconstruction->menuAction());
        menuImageProcessing->addSeparator();
        menuImageProcessing->addAction(actionMorphological_Image_Processing);
        menuImageProcessing->addSeparator();
        menuImageProcessing->addAction(actionImage_Segmentation);
        menuPointOperation->addAction(actionInverse);
        menuPointOperation->addAction(actionLog_Transformations);
        menuPointOperation->addAction(actionGamma_Transformations);
        menuPointOperation->addAction(actionPiecewise_Liear_Transformation_Functions);
        menuPointOperation->addSeparator();
        menuPointOperation->addAction(actionHistogram_Equalization);
        menuPointOperation->addAction(actionHistogram_Matching);
        menuPointOperation->addAction(actionLocal_Histogram_Processing);
        menuPointOperation->addAction(actionHistogram_Image_Enhancement);
        menuPointOperation->addSeparator();
        menuPointOperation->addAction(actionGray_Strach);
        menuPointOperation->addAction(actionDifference);
        menuPointOperation->addAction(actionFusing);
        menuPointOperation->addAction(actionCorrelation);
        menuPointOperation->addAction(action_miu_delta_Equalization);
        menuPointOperation->addAction(actionBinary_Operation);
        menuSpatial_Filtering->addAction(actionSmoothing_Spatial_Filters);
        menuSpatial_Filtering->addAction(actionSharpening_Spatial_Filters);
        menuSpatial_Filtering->addAction(actionImage_Enhance);
        menuFrequency_Domain->addAction(actionSmoothing);
        menuFrequency_Domain->addAction(actionSharpening);
        menuFrequency_Domain->addAction(actionSelective_Filtering);
        menuSettings->addAction(menuLanguages_2->menuAction());
        menuLanguages_2->addAction(actionChinese);
        menuLanguages_2->addAction(actionEnglish_2);
        menu_Tools->addAction(actionFileAssistant);
        menutest->addAction(actiontestFunction);
        mainToolBar->addAction(action_Open);
        mainToolBar->addAction(action_SaveAs);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        comboBoxHistorgram->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Image Expert", Q_NULLPTR));
        action_Open->setText(QApplication::translate("MainWindow", "&Open...", Q_NULLPTR));
        action_Open->setIconText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_Open->setToolTip(QApplication::translate("MainWindow", "Open Image Files", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        action_Open->setWhatsThis(QApplication::translate("MainWindow", "Open Image Files", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        action_Open->setShortcut(QApplication::translate("MainWindow", "Alt+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_SaveAs->setText(QApplication::translate("MainWindow", "Save &As...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_SaveAs->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Save As</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        action_SaveAs->setWhatsThis(QApplication::translate("MainWindow", "Save As", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        action_SaveAs->setShortcut(QApplication::translate("MainWindow", "Alt+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_Exit->setText(QApplication::translate("MainWindow", "&Exit", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_Exit->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Exit</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionEnglish->setText(QApplication::translate("MainWindow", "English", Q_NULLPTR));
        actionChinese->setText(QApplication::translate("MainWindow", "Chinese", Q_NULLPTR));
        actionEnglish_2->setText(QApplication::translate("MainWindow", "English", Q_NULLPTR));
        actionFileAssistant->setText(QApplication::translate("MainWindow", "FileAssistant", Q_NULLPTR));
        actionInverse->setText(QApplication::translate("MainWindow", "Negatives", Q_NULLPTR));
        actionLog_Transformations->setText(QApplication::translate("MainWindow", "Log Transformations", Q_NULLPTR));
        actionGamma_Transformations->setText(QApplication::translate("MainWindow", "Gamma Transformations", Q_NULLPTR));
        actionPiecewise_Liear_Transformation_Functions->setText(QApplication::translate("MainWindow", "Piecewise-Liear Transformation Functions", Q_NULLPTR));
        actionHistogram_Equalization->setText(QApplication::translate("MainWindow", "Histogram Equalization", Q_NULLPTR));
        actionHistogram_Matching->setText(QApplication::translate("MainWindow", "Histogram Matching", Q_NULLPTR));
        actionLocal_Histogram_Processing->setText(QApplication::translate("MainWindow", "Local Histogram Processing", Q_NULLPTR));
        actionHistogram_Image_Enhancement->setText(QApplication::translate("MainWindow", "Histogram Image Enhancement", Q_NULLPTR));
        actionSmoothing_Spatial_Filters->setText(QApplication::translate("MainWindow", "Smoothing Spatial Filters...", Q_NULLPTR));
        actionSharpening_Spatial_Filters->setText(QApplication::translate("MainWindow", "Sharpening Spatial Filters...", Q_NULLPTR));
        actionGray_Strach->setText(QApplication::translate("MainWindow", "Gray Strach", Q_NULLPTR));
        actionDifference->setText(QApplication::translate("MainWindow", "Difference", Q_NULLPTR));
        actionFusing->setText(QApplication::translate("MainWindow", "Fusing", Q_NULLPTR));
        actionCorrelation->setText(QApplication::translate("MainWindow", "Correlation", Q_NULLPTR));
        action_miu_delta_Equalization->setText(QApplication::translate("MainWindow", "(miu-delta)Equalization", Q_NULLPTR));
        actionBinary_Operation->setText(QApplication::translate("MainWindow", "Binary Operation", Q_NULLPTR));
        actionImage_Enhance->setText(QApplication::translate("MainWindow", "Image Enhancement", Q_NULLPTR));
        actiong_Fuzzy_Techniques->setText(QApplication::translate("MainWindow", "Fuzzy Techniques", Q_NULLPTR));
        actionSmoothing->setText(QApplication::translate("MainWindow", "Smoothing Filters", Q_NULLPTR));
        actionSharpening->setText(QApplication::translate("MainWindow", "Sharpening Filters", Q_NULLPTR));
        actionSelective_Filtering->setText(QApplication::translate("MainWindow", "Selective Filters", Q_NULLPTR));
        actionNoise_Models->setText(QApplication::translate("MainWindow", "Noise Models", Q_NULLPTR));
        actionMorphological_Image_Processing->setText(QApplication::translate("MainWindow", "Morphological Image Processing", Q_NULLPTR));
        actionImage_Segmentation->setText(QApplication::translate("MainWindow", "Image Segmentation", Q_NULLPTR));
        actiontestFunction->setText(QApplication::translate("MainWindow", "testFunction", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetHistory->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Image", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetHistory->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Size", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetHistory->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Info", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetHistory->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "PathinWorkspace", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tableWidgetHistory->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\345\216\206\345\217\262\346\226\207\344\273\266\344\277\241\346\201\257</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pictureBox->setText(QString());
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", Q_NULLPTR));
        menuImageProcessing->setTitle(QApplication::translate("MainWindow", "&ImageProcessing", Q_NULLPTR));
        menuPointOperation->setTitle(QApplication::translate("MainWindow", "Intensity Transformations ", Q_NULLPTR));
        menuSpatial_Filtering->setTitle(QApplication::translate("MainWindow", "Spatial Filtering", Q_NULLPTR));
        menuFrequency_Domain->setTitle(QApplication::translate("MainWindow", "Frequency Domain", Q_NULLPTR));
        menuImage_Restoration_and_Reconstruction->setTitle(QApplication::translate("MainWindow", "Color Image Processing", Q_NULLPTR));
        menuSettings->setTitle(QApplication::translate("MainWindow", "&Settings", Q_NULLPTR));
        menuLanguages_2->setTitle(QApplication::translate("MainWindow", "Languages", Q_NULLPTR));
        menuVideoProcessing->setTitle(QApplication::translate("MainWindow", "&VideoProcessing", Q_NULLPTR));
        menu_MachineLearning->setTitle(QApplication::translate("MainWindow", "&MachineLearning", Q_NULLPTR));
        menu3_D_Surfaces->setTitle(QApplication::translate("MainWindow", "3&D-Surfaces", Q_NULLPTR));
        menu_Tools->setTitle(QApplication::translate("MainWindow", "&Tools", Q_NULLPTR));
        menu_View->setTitle(QApplication::translate("MainWindow", "&View", Q_NULLPTR));
        menutest->setTitle(QApplication::translate("MainWindow", "test", Q_NULLPTR));
        dockWidgetHistorgram->setWindowTitle(QApplication::translate("MainWindow", "Histogram", Q_NULLPTR));
        comboBoxHistorgram->setCurrentText(QString());
        labelHistorgram->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonHistSaveImg->setToolTip(QApplication::translate("MainWindow", "save current historgram as image", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonHistSaveImg->setText(QApplication::translate("MainWindow", "SaveImage", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButtonHistSaveData->setToolTip(QApplication::translate("MainWindow", "Save current historgram to file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonHistSaveData->setText(QApplication::translate("MainWindow", "SaveData", Q_NULLPTR));
        dockWidgetAppInfo->setWindowTitle(QApplication::translate("MainWindow", "Applicaton Log", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetLogInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Time", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetLogInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Command", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetLogInfo->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Arguments", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        dockWidgetVPHist->setWindowTitle(QApplication::translate("MainWindow", "Vertical Project Historgram", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
