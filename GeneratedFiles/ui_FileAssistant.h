/********************************************************************************
** Form generated from reading UI file 'FileAssistant.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEASSISTANT_H
#define UI_FILEASSISTANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileAssistant
{
public:
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_SourceFloder;
    QToolButton *toolButton_SourceFolder;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioButton_Copy;
    QRadioButton *radioButton_Move;
    QRadioButton *radioButton_Delete;
    QCheckBox *checkBox_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineEdit_Filter;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_TargetFolder;
    QToolButton *toolButton_TargetFolder;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_NameingConflicts;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_Info;
    QPushButton *pushButton_OK;
    QWidget *tab2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEdit_Floder;
    QToolButton *toolButton_Folder;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QLineEdit *lineEdit_Filter_3;
    QLabel *label_9;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_Rt;
    QPushButton *pushButton_Generate;
    QWidget *tab;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QLineEdit *lineEdit_FileList;
    QToolButton *toolButton_FileList;
    QHBoxLayout *horizontalLayout_11;
    QRadioButton *radioButton_Copy_2;
    QRadioButton *radioButton_Move_2;
    QRadioButton *radioButton_Delete_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_11;
    QLineEdit *lineEdit_TargetFolder_2;
    QToolButton *toolButton_TargetFolder_2;
    QHBoxLayout *horizontalLayout_15;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_NameingConflicts_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QLineEdit *lineEdit_sourceFolder_2;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_Info_2;
    QPushButton *pushButton_OK_2;

    void setupUi(QDialog *FileAssistant)
    {
        if (FileAssistant->objectName().isEmpty())
            FileAssistant->setObjectName(QStringLiteral("FileAssistant"));
        FileAssistant->resize(547, 224);
        verticalLayout_3 = new QVBoxLayout(FileAssistant);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tabWidget = new QTabWidget(FileAssistant);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        layoutWidget = new QWidget(tab1);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 506, 165));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit_SourceFloder = new QLineEdit(layoutWidget);
        lineEdit_SourceFloder->setObjectName(QStringLiteral("lineEdit_SourceFloder"));

        horizontalLayout_2->addWidget(lineEdit_SourceFloder);

        toolButton_SourceFolder = new QToolButton(layoutWidget);
        toolButton_SourceFolder->setObjectName(QStringLiteral("toolButton_SourceFolder"));

        horizontalLayout_2->addWidget(toolButton_SourceFolder);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        radioButton_Copy = new QRadioButton(layoutWidget);
        radioButton_Copy->setObjectName(QStringLiteral("radioButton_Copy"));
        radioButton_Copy->setChecked(true);

        horizontalLayout_5->addWidget(radioButton_Copy);

        radioButton_Move = new QRadioButton(layoutWidget);
        radioButton_Move->setObjectName(QStringLiteral("radioButton_Move"));

        horizontalLayout_5->addWidget(radioButton_Move);

        radioButton_Delete = new QRadioButton(layoutWidget);
        radioButton_Delete->setObjectName(QStringLiteral("radioButton_Delete"));

        horizontalLayout_5->addWidget(radioButton_Delete);

        checkBox_2 = new QCheckBox(layoutWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout_5->addWidget(checkBox_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        lineEdit_Filter = new QLineEdit(layoutWidget);
        lineEdit_Filter->setObjectName(QStringLiteral("lineEdit_Filter"));
        lineEdit_Filter->setMaxLength(32767);

        horizontalLayout_4->addWidget(lineEdit_Filter);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_TargetFolder = new QLineEdit(layoutWidget);
        lineEdit_TargetFolder->setObjectName(QStringLiteral("lineEdit_TargetFolder"));

        horizontalLayout_3->addWidget(lineEdit_TargetFolder);

        toolButton_TargetFolder = new QToolButton(layoutWidget);
        toolButton_TargetFolder->setObjectName(QStringLiteral("toolButton_TargetFolder"));

        horizontalLayout_3->addWidget(toolButton_TargetFolder);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        checkBox_3 = new QCheckBox(layoutWidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        horizontalLayout_12->addWidget(checkBox_3);

        checkBox_NameingConflicts = new QCheckBox(layoutWidget);
        checkBox_NameingConflicts->setObjectName(QStringLiteral("checkBox_NameingConflicts"));

        horizontalLayout_12->addWidget(checkBox_NameingConflicts);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_Info = new QLabel(layoutWidget);
        label_Info->setObjectName(QStringLiteral("label_Info"));

        horizontalLayout_6->addWidget(label_Info);

        pushButton_OK = new QPushButton(layoutWidget);
        pushButton_OK->setObjectName(QStringLiteral("pushButton_OK"));
        pushButton_OK->setMaximumSize(QSize(70, 50));

        horizontalLayout_6->addWidget(pushButton_OK);


        verticalLayout_2->addLayout(horizontalLayout_6);

        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        layoutWidget1 = new QWidget(tab2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 501, 129));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_7->addWidget(label_5);

        lineEdit_Floder = new QLineEdit(layoutWidget1);
        lineEdit_Floder->setObjectName(QStringLiteral("lineEdit_Floder"));

        horizontalLayout_7->addWidget(lineEdit_Floder);

        toolButton_Folder = new QToolButton(layoutWidget1);
        toolButton_Folder->setObjectName(QStringLiteral("toolButton_Folder"));

        horizontalLayout_7->addWidget(toolButton_Folder);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_10->addWidget(label_8);

        lineEdit_Filter_3 = new QLineEdit(layoutWidget1);
        lineEdit_Filter_3->setObjectName(QStringLiteral("lineEdit_Filter_3"));
        lineEdit_Filter_3->setMaxLength(32767);

        horizontalLayout_10->addWidget(lineEdit_Filter_3);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_10->addWidget(label_9);


        verticalLayout_4->addLayout(horizontalLayout_10);

        checkBox = new QCheckBox(layoutWidget1);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_4->addWidget(checkBox);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_Rt = new QLabel(layoutWidget1);
        label_Rt->setObjectName(QStringLiteral("label_Rt"));

        horizontalLayout_8->addWidget(label_Rt);

        pushButton_Generate = new QPushButton(layoutWidget1);
        pushButton_Generate->setObjectName(QStringLiteral("pushButton_Generate"));
        pushButton_Generate->setMaximumSize(QSize(70, 50));

        horizontalLayout_8->addWidget(pushButton_Generate);


        verticalLayout_4->addLayout(horizontalLayout_8);

        tabWidget->addTab(tab2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget2 = new QWidget(tab);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(11, 11, 508, 165));
        verticalLayout_5 = new QVBoxLayout(layoutWidget2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_9->addWidget(label_6);

        lineEdit_FileList = new QLineEdit(layoutWidget2);
        lineEdit_FileList->setObjectName(QStringLiteral("lineEdit_FileList"));

        horizontalLayout_9->addWidget(lineEdit_FileList);

        toolButton_FileList = new QToolButton(layoutWidget2);
        toolButton_FileList->setObjectName(QStringLiteral("toolButton_FileList"));

        horizontalLayout_9->addWidget(toolButton_FileList);


        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        radioButton_Copy_2 = new QRadioButton(layoutWidget2);
        radioButton_Copy_2->setObjectName(QStringLiteral("radioButton_Copy_2"));
        radioButton_Copy_2->setChecked(true);

        horizontalLayout_11->addWidget(radioButton_Copy_2);

        radioButton_Move_2 = new QRadioButton(layoutWidget2);
        radioButton_Move_2->setObjectName(QStringLiteral("radioButton_Move_2"));

        horizontalLayout_11->addWidget(radioButton_Move_2);

        radioButton_Delete_2 = new QRadioButton(layoutWidget2);
        radioButton_Delete_2->setObjectName(QStringLiteral("radioButton_Delete_2"));

        horizontalLayout_11->addWidget(radioButton_Delete_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout_11);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_13->addWidget(label_11);

        lineEdit_TargetFolder_2 = new QLineEdit(layoutWidget2);
        lineEdit_TargetFolder_2->setObjectName(QStringLiteral("lineEdit_TargetFolder_2"));

        horizontalLayout_13->addWidget(lineEdit_TargetFolder_2);

        toolButton_TargetFolder_2 = new QToolButton(layoutWidget2);
        toolButton_TargetFolder_2->setObjectName(QStringLiteral("toolButton_TargetFolder_2"));

        horizontalLayout_13->addWidget(toolButton_TargetFolder_2);


        verticalLayout_6->addLayout(horizontalLayout_13);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        checkBox_4 = new QCheckBox(layoutWidget2);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        horizontalLayout_15->addWidget(checkBox_4);

        checkBox_NameingConflicts_2 = new QCheckBox(layoutWidget2);
        checkBox_NameingConflicts_2->setObjectName(QStringLiteral("checkBox_NameingConflicts_2"));

        horizontalLayout_15->addWidget(checkBox_NameingConflicts_2);


        verticalLayout_6->addLayout(horizontalLayout_15);


        verticalLayout_5->addLayout(verticalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        lineEdit_sourceFolder_2 = new QLineEdit(layoutWidget2);
        lineEdit_sourceFolder_2->setObjectName(QStringLiteral("lineEdit_sourceFolder_2"));

        horizontalLayout->addWidget(lineEdit_sourceFolder_2);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_Info_2 = new QLabel(layoutWidget2);
        label_Info_2->setObjectName(QStringLiteral("label_Info_2"));

        horizontalLayout_14->addWidget(label_Info_2);

        pushButton_OK_2 = new QPushButton(layoutWidget2);
        pushButton_OK_2->setObjectName(QStringLiteral("pushButton_OK_2"));
        pushButton_OK_2->setMaximumSize(QSize(70, 50));

        horizontalLayout_14->addWidget(pushButton_OK_2);


        verticalLayout_5->addLayout(horizontalLayout_14);

        tabWidget->addTab(tab, QString());

        verticalLayout_3->addWidget(tabWidget);


        retranslateUi(FileAssistant);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FileAssistant);
    } // setupUi

    void retranslateUi(QDialog *FileAssistant)
    {
        FileAssistant->setWindowTitle(QApplication::translate("FileAssistant", "ImageExpert-File Assistant", Q_NULLPTR));
        label->setText(QApplication::translate("FileAssistant", "Source Folder:", Q_NULLPTR));
        toolButton_SourceFolder->setText(QApplication::translate("FileAssistant", "...", Q_NULLPTR));
        radioButton_Copy->setText(QApplication::translate("FileAssistant", "Copy", Q_NULLPTR));
        radioButton_Move->setText(QApplication::translate("FileAssistant", "Move", Q_NULLPTR));
        radioButton_Delete->setText(QApplication::translate("FileAssistant", "Delete", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("FileAssistant", "Contain Subdirectories", Q_NULLPTR));
        label_3->setText(QApplication::translate("FileAssistant", "Filter", Q_NULLPTR));
        lineEdit_Filter->setText(QApplication::translate("FileAssistant", "*.*", Q_NULLPTR));
        label_4->setText(QApplication::translate("FileAssistant", "Example: *.bmp;*_test.jpg", Q_NULLPTR));
        label_2->setText(QApplication::translate("FileAssistant", "Target Folder:", Q_NULLPTR));
        toolButton_TargetFolder->setText(QApplication::translate("FileAssistant", "...", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("FileAssistant", "Create Subdirectires in target folder", Q_NULLPTR));
        checkBox_NameingConflicts->setText(QApplication::translate("FileAssistant", "Automatically resolve naming conflicts", Q_NULLPTR));
        pushButton_OK->setText(QApplication::translate("FileAssistant", "OK", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("FileAssistant", "Manage Files", Q_NULLPTR));
        label_5->setText(QApplication::translate("FileAssistant", "Source Folder:", Q_NULLPTR));
        toolButton_Folder->setText(QApplication::translate("FileAssistant", "...", Q_NULLPTR));
        label_8->setText(QApplication::translate("FileAssistant", "Filter:", Q_NULLPTR));
        lineEdit_Filter_3->setText(QApplication::translate("FileAssistant", "*.*", Q_NULLPTR));
        label_9->setText(QApplication::translate("FileAssistant", "Example: *.bmp;*_test.jpg", Q_NULLPTR));
        checkBox->setText(QApplication::translate("FileAssistant", "Contain Subdirectories", Q_NULLPTR));
        pushButton_Generate->setText(QApplication::translate("FileAssistant", "Generate", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("FileAssistant", "Generate File List", Q_NULLPTR));
        label_6->setText(QApplication::translate("FileAssistant", "File List (txt):", Q_NULLPTR));
        toolButton_FileList->setText(QApplication::translate("FileAssistant", "...", Q_NULLPTR));
        radioButton_Copy_2->setText(QApplication::translate("FileAssistant", "Copy", Q_NULLPTR));
        radioButton_Move_2->setText(QApplication::translate("FileAssistant", "Move", Q_NULLPTR));
        radioButton_Delete_2->setText(QApplication::translate("FileAssistant", "Delete", Q_NULLPTR));
        label_11->setText(QApplication::translate("FileAssistant", "Target  Folder:", Q_NULLPTR));
        toolButton_TargetFolder_2->setText(QApplication::translate("FileAssistant", "...", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("FileAssistant", "Create Subdirectires in target folder", Q_NULLPTR));
        checkBox_NameingConflicts_2->setText(QApplication::translate("FileAssistant", "Automatically resolve naming conflicts", Q_NULLPTR));
        label_7->setText(QApplication::translate("FileAssistant", "Source Folder:", Q_NULLPTR));
        pushButton_OK_2->setText(QApplication::translate("FileAssistant", "OK", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("FileAssistant", "File List Operates", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FileAssistant: public Ui_FileAssistant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEASSISTANT_H
