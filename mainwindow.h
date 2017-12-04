#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <opencv.hpp>
#include <opencv/cv.h>
#include <QMainWindow>
#include <QMouseEvent>
#include <QTranslator>
#include <QMenu>
#include <QAction>
#include <QList>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QProgressBar>
#include "systemconfigs.h"
using namespace cv;
typedef enum{
    UI_ZH,
    UI_EN
}LANGUAGE;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(qint64 appID,QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QString m_currentImgName;
    SystemConfigs m_systemParmeters;
    QString m_workSpace;//工作空间（临时文件夹）
    QString m_workSpaceFloder;//工作空间的文件夹
    int m_scaleInidex;//显示比例的索引
    int m_language;//界面语言 0:中文；1:英文
    Mat m_img;
    bool m_lbuttonDown;
    qint64 m_pid;
    QVector<double> m_scales; //缩放比例
    QMenu* m_tableWidget_popMenu;//鼠标右键弹出菜单
    QAction* m_export_action;//导出菜单选项
    QAction* m_delete_action;//删除菜单选项
    QAction* m_saveAs_action;//另存菜单选项
    QAction* m_reload_action;//重载菜单选项
    QAction* m_view_action;  //查看菜单选项
    QAction* m_edit_action;  //编辑菜单选项
    QMenu* m_picturebox_popMenu;//鼠标右键弹出菜单
    QAction* m_auto_size_Action;//实际大小显示图像
    QAction* m_auto_zoom_Action;//适应屏幕大小显示图像
    QAction* m_free_zoom_Action;//自由缩放显示图像
    //Widget in Status

public:
    QWidget* m_zoomWidget;
    QLabel* m_zoomScaleLabel;
    QPushButton* m_zoomInButton;
    QPushButton* m_zoomOutButton;
    QSlider* m_zoomSlider;
    QLabel* m_sizeInStatusBarLabel;
    QLabel* m_currentCursorPosLabel;
    QPushButton* m_appInfoButton;
    QPushButton* m_vProjectHistButton;
    QProgressBar* m_statusBarProcessBar;
private:
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void initTableWidgetContexMenus();
    void initPictureBoxContexMenus();
    void initStatusBar();
    void initLanguage();
    void addLogInformation(QString command, QString logInfo);
    void addItem2History(QString img, QString size,QString info, QString path="");
    QImage cvMat2QImage(const cv::Mat& mat);
    Mat QImage2cvMat(QImage& image);
    void showImage(QString imageName);
    void createWorkSpace();
    void deleteWorkSpace();
    void initScales();
    void initPictureBox();

private slots:
    void on_action_Open_triggered();
    void on_action_SaveAs_triggered();
    void on_actionChinese_triggered();
    void on_actionEnglish_2_triggered();
    void on_tableWidgetHistory_customContextMenuRequested(const QPoint &pos);
    void on_m_export_action();
    void on_m_delete_action();
    void on_m_saveAs_action();
    void on_m_reload_action();
    void on_m_view_action();
    void on_m_edit_action();
    void on_pictureBox_customContextMenuRequested(const QPoint &pos);
    void on_m_auto_size_Action();
    void on_m_auto_zoom_Action();
    void on_m_free_zoom_Action();
    void on_m_appInfoButton_clicked();
    void on_m_vProjectHistButton_clicked();
    void on_m_zoomInButton_clicked();
    void on_m_zoomOutButton_clicked();
    void on_m_zoomSlider_changed();
    void on_tableWidgetHistory_doubleClicked(const QModelIndex &idx);
    void on_actionFileAssistant_triggered();
    void on_actionInverse_triggered();
    void on_actiontestFunction_triggered();
};

#endif // MAINWINDOW_H
