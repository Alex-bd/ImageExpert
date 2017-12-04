#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class FileAssistant;
}

class FileAssistant : public QDialog
{
    Q_OBJECT

public:
    explicit FileAssistant(QWidget *parent = 0);
    ~FileAssistant();

private:
    Ui::FileAssistant *ui;
    int m_opType;
    int m_opType_2;
private slots:
    void on_toolButton_SourceFolder_clicked();
    void on_toolButton_TargetFolder_clicked();
    void on_radioButton_Copy_clicked();
    void on_radioButton_Move_clicked();
    void on_radioButton_Delete_clicked();
    void on_radioButton_Copy_2_clicked();
    void on_radioButton_Move_2_clicked();
    void on_radioButton_Delete_2_clicked();
    void on_pushButton_OK_clicked();
    void on_toolButton_Folder_clicked();
    void on_pushButton_Generate_clicked();
    void on_toolButton_FileList_clicked();
    void on_toolButton_TargetFolder_2_clicked();
    void on_pushButton_OK_2_clicked();
};

#endif // DIALOG_H
