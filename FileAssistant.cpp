#include "FileAssistant.h"
#include "ui_FileAssistant.h"
#include <QFileDialog>
#include <QDirIterator>
#include <QDebug>
#include <QMessageBox>
#include <QCollator>
#include <QMap>
FileAssistant::FileAssistant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileAssistant)
{
    ui->setupUi(this);
    setFixedSize(size());
    //this->layout()->setSizeConstraint( QLayout::SetFixedSize );
    m_opType = 1;
    m_opType_2 = 1;
}

FileAssistant::~FileAssistant()
{
    delete ui;
}

void FileAssistant::on_toolButton_SourceFolder_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Source Directory"),
                                                    QString(),
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    if(!dir.isNull())
    {
        ui->lineEdit_SourceFloder->setText(dir);
    }
}

void FileAssistant::on_toolButton_TargetFolder_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Target Directory"),
                                                    QString(),
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    if(!dir.isNull())
    {
        ui->lineEdit_TargetFolder->setText(dir);
    }
}

void FileAssistant::on_radioButton_Copy_clicked()
{
    if(ui->radioButton_Copy->isChecked())
    {
        m_opType=1;
    }
}

void FileAssistant::on_radioButton_Move_clicked()
{
    if(ui->radioButton_Move->isChecked())
    {
        m_opType=2;
        ui->label_Info->setText(QString("%1").arg(m_opType));
    }
}

void FileAssistant::on_radioButton_Delete_clicked()
{
    if(ui->radioButton_Delete->isChecked())
    {
        m_opType=3;
    }
}

void FileAssistant::on_radioButton_Copy_2_clicked()
{
    if(ui->radioButton_Copy_2->isChecked())
    {
        m_opType_2=1;
    }
}

void FileAssistant::on_radioButton_Move_2_clicked()
{
    if(ui->radioButton_Move_2->isChecked())
    {
        m_opType_2=2;
        ui->label_Info_2->setText(QString("%1").arg(m_opType));
    }
}

void FileAssistant::on_radioButton_Delete_2_clicked()
{
    if(ui->radioButton_Delete_2->isChecked())
    {
        m_opType_2=3;
    }
}

void FileAssistant::on_pushButton_OK_clicked()
{
	if (!ui->lineEdit_SourceFloder->text().isNull() && !ui->lineEdit_SourceFloder->text().trimmed().isEmpty())
	{
        QStringList ft = ui->lineEdit_Filter->text().split(';');
        QDirIterator::IteratorFlags iterf;
        if (ui->checkBox_2->isChecked())
        {
            iterf = QDirIterator::Subdirectories;
        }
        else
        {
            iterf = QDirIterator::NoIteratorFlags;
        }
        QDirIterator it(ui->lineEdit_SourceFloder->text(), ft, QDir::Files, iterf);
        QVector<QFileInfo> fileList;
        while (it.hasNext())
        {
            fileList.push_back(it.next());
        }

        QVector<QFileInfo> targetFilList;
        QMap<QString,int> reduplicatedFile;
        foreach (QFileInfo fileInfo, fileList)
        {
            if (!ui->lineEdit_TargetFolder->text().isNull() && !ui->lineEdit_TargetFolder->text().trimmed().isEmpty())
            {
                QString toFolder;
                if (ui->checkBox_3->isChecked())
                {
                    QString allSourceF = fileInfo.absolutePath();
                    QString sourceFolder = QDir(ui->lineEdit_SourceFloder->text()).absolutePath();
                    QString targetFolder = QDir(ui->lineEdit_TargetFolder->text()).absolutePath();
                    QChar edC = sourceFolder.at(sourceFolder.length()-1);
                    if (edC == '\\' || edC=='/')
                    {
                        sourceFolder = sourceFolder.remove(sourceFolder.length()-1,1);
                    }
                    toFolder = targetFolder + allSourceF;
                    toFolder.replace(sourceFolder, "");
                    if (!QDir(toFolder).exists())
                    {
                        QDir().mkpath(toFolder);
                    }
                }
                else
                {
                    toFolder = ui->lineEdit_TargetFolder->text();
                }

                QFileInfo toFile(QString("%1/%2").arg(toFolder).arg(fileInfo.fileName()));
				if (ui->checkBox_NameingConflicts->isChecked())
				{
					int fnum = reduplicatedFile.value(toFile.absoluteFilePath(), 0);
					if (fnum)
					{
						reduplicatedFile.insert(toFile.absoluteFilePath(), fnum + 1);
						toFile = QFileInfo(QString("%1/%2_(%3).%4").arg(toFolder).arg(fileInfo.completeBaseName()).arg(fnum).arg(fileInfo.suffix()));
					}
					else
					{
						reduplicatedFile.insert(toFile.absoluteFilePath(), fnum + 1);
					}
				}
				targetFilList.push_back(toFile);
                
            }
        }
        int fileCount = -1;
        bool yestoall = false;
        int FileNum = fileList.size();
		if (m_opType == 1)
		{//copy
			if (!ui->lineEdit_TargetFolder->text().isNull() && !ui->lineEdit_TargetFolder->text().trimmed().isEmpty())
			{
				ui->label_Info->setText(QString("Copying..."));



                foreach (QFileInfo targetFileInfo, targetFilList)
                {

                    QFileInfo fileInfo = fileList.at(++fileCount);
                    QDir targetFile = targetFileInfo.absoluteDir();
                    QString toFile = targetFileInfo.absoluteFilePath();
					if (targetFile.exists(toFile))
					{
						if (yestoall)
						{
							targetFile.remove(toFile);
						}
						else
						{
							int ret = QMessageBox::warning(this, tr("Copy File"),
								tr("Cover the exist file?") + QString("\n \"%1\"").arg(toFile),
								QMessageBox::Yes | QMessageBox::No | QMessageBox::YesToAll);
							if (ret == QMessageBox::YesToAll)
							{
								yestoall = true;
								targetFile.remove(toFile);
							}
							else if (ret == QMessageBox::Yes)
							{
								targetFile.remove(toFile);
							}
							else
							{
								continue;
							}
						}
					}
                    if (!QFile::copy(fileInfo.absoluteFilePath(), toFile))
					{
						QMessageBox msgBox(this);
						msgBox.setIcon(QMessageBox::Warning);
						msgBox.setText(tr("An error occurred when exporting the following files!") + QString("\n \"%1\"").arg(toFile));
						msgBox.exec();
						continue;
					}
                    ui->label_Info->setText(QString("%1 / %2 files have been copied.").arg(fileCount+1).arg(FileNum));
					qApp->processEvents();
				}
			}
            ui->label_Info->setText(QString("DONE: %1  / %2 files have been copied!").arg(fileCount+1).arg(FileNum));
			qApp->processEvents();
		}
		else if (m_opType == 2)
		{//move

            foreach (QFileInfo targetFileInfo, targetFilList)
            {
                QFileInfo fileInfo = fileList.at(++fileCount);
                QDir targetFile = targetFileInfo.absoluteDir();
                QString toFile = targetFileInfo.absoluteFilePath();
					if (targetFile.exists(toFile))
					{
						if (yestoall)
						{
							targetFile.remove(toFile);
						}
						else
						{
							int ret = QMessageBox::warning(this, tr("Copy File"),
								tr("Cover the exist file?") + QString("\n \"%1\"").arg(toFile),
								QMessageBox::Yes | QMessageBox::No | QMessageBox::YesToAll);
							if (ret == QMessageBox::YesToAll)
							{
								yestoall = true;
								targetFile.remove(toFile);
							}
							else if (ret == QMessageBox::Yes)
							{
								targetFile.remove(toFile);
							}
							else
							{
								continue;
							}
						}
					}
					bool copySuccess = QFile::copy(fileInfo.absoluteFilePath(), toFile);
					if (copySuccess)
					{
						QDir removeFile;
						removeFile.remove(fileInfo.absoluteFilePath());
					}
					else
					{
						QMessageBox msgBox(this);
						msgBox.setIcon(QMessageBox::Warning);
						msgBox.setText(tr("An error occurred when exporting the following files!") + QString("\n \"%1\"").arg(toFile));
						msgBox.exec();
						continue;
					}
                    ui->label_Info->setText(QString("%1 / %2 files have been moved.").arg(fileCount + 1).arg(FileNum));
					qApp->processEvents();

			}
            ui->label_Info->setText(QString("%1 / %2 files have been moved.").arg(fileCount + 1).arg(FileNum));
			qApp->processEvents();
		}
		else if (m_opType == 3)
		{//delete
			ui->label_Info->setText(QString("Deleting..."));
			QDir deletefile;
            foreach (QFileInfo fileInfo, fileList)
            {
				deletefile.remove(fileInfo.absoluteFilePath());
                ui->label_Info->setText(QString("%1 / %2 files have been deleted.").arg(fileCount + 1).arg(FileNum));
				qApp->processEvents();
			}
            ui->label_Info->setText(QString("%1 / %2 files have been deleted.").arg(fileCount + 1).arg(FileNum));
			qApp->processEvents();
		}
	}


}

void FileAssistant::on_toolButton_Folder_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Directory"),
                                                    QString(),
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    if(!dir.isNull())
    {
        ui->lineEdit_Floder->setText(dir);
    }
}

void FileAssistant::on_pushButton_Generate_clicked()
{
    if(!ui->lineEdit_Floder->text().isNull() && !ui->lineEdit_Floder->text().trimmed().isEmpty())
    {
        ui->label_Rt->setText(QString("Generating..."));
        qApp->processEvents();
        QStringList ft=ui->lineEdit_Filter_3->text().split(';');
        QFile file(QString("%1/list.txt").arg(ui->lineEdit_Floder->text()));
        if(!file.open(QIODevice::WriteOnly|QIODevice::Text)) return;
        QTextStream out(&file);
        QDirIterator::IteratorFlags iterf;
        if(ui->checkBox->isChecked())
        {
            iterf = QDirIterator::Subdirectories;
        }
        else
        {
            iterf = QDirIterator::NoIteratorFlags;
        }
        QDirIterator it(ui->lineEdit_Floder->text(), ft, QDir::Files, iterf);
        int nums = 0;
        QCollator collator;
        collator.setNumericMode(true);
        QStringList fileList;
        while (it.hasNext())
        {
            fileList.push_back(it.next());
            nums++;
        }
        std::sort(fileList.begin(),fileList.end(),[&collator](const QString &file1,const QString &file2){return collator.compare(file1,file2)<0;});
        foreach (QString s, fileList)
        {
            out << s<<"\n";
        }
        ui->label_Rt->setText(QString("%1 files have been recoded in list.txt").arg(nums)); 
		qApp->processEvents();
        file.close();
    }
}

void FileAssistant::on_toolButton_FileList_clicked()
{
    QString filter = "*.txt";
    QFileDialog *fileDialog = new QFileDialog(this,QString(tr("Open FileList File")),QString(),filter);

    if(fileDialog->exec() == QDialog::Accepted)
    {
        ui->lineEdit_FileList->setText(fileDialog->selectedFiles()[0]);
    }
}

void FileAssistant::on_toolButton_TargetFolder_2_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Directory"),
                                                    QString(),
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    if(!dir.isNull())
    {
        ui->lineEdit_TargetFolder_2->setText(dir);
    }
}

void FileAssistant::on_pushButton_OK_2_clicked()
{
    QDir dir;
    if(dir.exists(ui->lineEdit_FileList->text()))
    {
        QVector<QFileInfo> fileList;
        QFile f(ui->lineEdit_FileList->text());
        if(!f.open(QIODevice::ReadOnly|QIODevice::Text)) return;
        QTextStream in(&f);
        while (!in.atEnd())
        {
            fileList.push_back(QFileInfo(in.readLine()));
        }
        f.close();
        ui->lineEdit_sourceFolder_2->setText(fileList.at(0).absolutePath());
        qApp->processEvents();
        QVector<QFileInfo> targetFilList;
        QMap<QString,int> reduplicatedFile;
        foreach (QFileInfo fileInfo, fileList)
        {
            if (!ui->lineEdit_TargetFolder_2->text().isNull() && !ui->lineEdit_TargetFolder_2->text().trimmed().isEmpty())
            {
                QString toFolder;
                if (ui->checkBox_4->isChecked())
                {
                    QString allSourceF = fileInfo.absolutePath();
                    QString sourceFolder = QDir(ui->lineEdit_sourceFolder_2->text()).absolutePath();
                    QString targetFolder = QDir(ui->lineEdit_TargetFolder_2->text()).absolutePath();
                    QChar edC = sourceFolder.at(sourceFolder.length()-1);
                    if (edC == '\\' || edC=='/')
                    {
                        sourceFolder = sourceFolder.remove(sourceFolder.length()-1,1);
                    }
                    toFolder = targetFolder + allSourceF;
                    toFolder.replace(sourceFolder, "");
                    if (!QDir(toFolder).exists())
                    {
                        QDir().mkpath(toFolder);
                    }
                }
                else
                {
                    toFolder = ui->lineEdit_TargetFolder->text();
                }

                QFileInfo toFile(QString("%1/%2").arg(toFolder).arg(fileInfo.fileName()));
				if (ui->checkBox_NameingConflicts->isChecked())
				{
					int fnum = reduplicatedFile.value(toFile.absoluteFilePath(), 0);
					if (fnum)
					{
						reduplicatedFile.insert(toFile.absoluteFilePath(), fnum + 1);
						toFile = QFileInfo(QString("%1/%2_(%3).%4").arg(toFolder).arg(fileInfo.completeBaseName()).arg(fnum).arg(fileInfo.suffix()));
					}
					else
					{
						reduplicatedFile.insert(toFile.absoluteFilePath(), fnum + 1);
					}
				}
                targetFilList.push_back(toFile);
            }
        }

        int fileCount = -1;
        bool yestoall = false;
         int FileNum = fileList.size();
        if (m_opType == 1)
        {//copy
            if (!ui->lineEdit_TargetFolder_2->text().isNull() && !ui->lineEdit_TargetFolder_2->text().trimmed().isEmpty())
            {
                ui->label_Info->setText(QString("Copying..."));

                bool yestoall = false;
                int fileCount = 0;
                foreach (QFileInfo targetFileInfo, targetFilList)
                {

                    QFileInfo fileInfo = fileList.at(++fileCount);
                    QDir targetFile = targetFileInfo.absoluteDir();
                    QString toFile = targetFileInfo.absoluteFilePath();
                    if (targetFile.exists(toFile))
                    {
                        if (yestoall)
                        {
                            targetFile.remove(toFile);
                        }
                        else
                        {
                            int ret = QMessageBox::warning(this, tr("Copy File"),
                                tr("Cover the exist file?") + QString("\n \"%1\"").arg(toFile),
                                QMessageBox::Yes | QMessageBox::No | QMessageBox::YesToAll);
                            if (ret == QMessageBox::YesToAll)
                            {
                                yestoall = true;
                                targetFile.remove(toFile);
                            }
                            else if (ret == QMessageBox::Yes)
                            {
                                targetFile.remove(toFile);
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }
                    if (!QFile::copy(fileInfo.absoluteFilePath(), toFile))
                    {
                        QMessageBox msgBox(this);
                        msgBox.setIcon(QMessageBox::Warning);
                        msgBox.setText(tr("An error occurred when exporting the following files!") + QString("\n \"%1\"").arg(toFile));
                        msgBox.exec();
                        continue;
                    }
                    ui->label_Info->setText(QString("%1 / %2 files have been copied.").arg(fileCount + 1).arg(FileNum));
                    qApp->processEvents();
                }
            }
            ui->label_Info->setText(QString("DONE: %1  / %2 files have been copied!").arg(fileCount + 1).arg(FileNum));
            qApp->processEvents();
        }
        else if (m_opType == 2)
        {//move

            foreach (QFileInfo targetFileInfo, targetFilList)
            {
                QFileInfo fileInfo = fileList.at(++fileCount);
                QDir targetFile = targetFileInfo.absoluteDir();
                QString toFile = targetFileInfo.absoluteFilePath();
                    if (targetFile.exists(toFile))
                    {
                        if (yestoall)
                        {
                            targetFile.remove(toFile);
                        }
                        else
                        {
                            int ret = QMessageBox::warning(this, tr("Copy File"),
                                tr("Cover the exist file?") + QString("\n \"%1\"").arg(toFile),
                                QMessageBox::Yes | QMessageBox::No | QMessageBox::YesToAll);
                            if (ret == QMessageBox::YesToAll)
                            {
                                yestoall = true;
                                targetFile.remove(toFile);
                            }
                            else if (ret == QMessageBox::Yes)
                            {
                                targetFile.remove(toFile);
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }
                    bool copySuccess = QFile::copy(fileInfo.absoluteFilePath(), toFile);
                    if (copySuccess)
                    {
                        QDir removeFile;
                        removeFile.remove(fileInfo.absoluteFilePath());
                    }
                    else
                    {
                        QMessageBox msgBox(this);
                        msgBox.setIcon(QMessageBox::Warning);
                        msgBox.setText(tr("An error occurred when exporting the following files!") + QString("\n \"%1\"").arg(toFile));
                        msgBox.exec();
                        continue;
                    }
                    ui->label_Info->setText(QString("%1 / %2 files have been moved.").arg(fileCount + 1).arg(FileNum));
                    qApp->processEvents();

            }
            ui->label_Info->setText(QString("%1 / %2 files have been moved.").arg(fileCount + 1).arg(FileNum));
            qApp->processEvents();
        }
        else if (m_opType == 3)
        {//delete
            ui->label_Info->setText(QString("Deleting..."));
            QDir deletefile;
            foreach (QFileInfo fileInfo, fileList)
            {
                deletefile.remove(fileInfo.absoluteFilePath());
                ui->label_Info->setText(QString("%1 / %2 files have been deleted.").arg(fileCount + 1).arg(FileNum));
                qApp->processEvents();
            }
            ui->label_Info->setText(QString("%1 / %2 files have been deleted.").arg(fileCount + 1).arg(FileNum));
            qApp->processEvents();
        }
        }
    else
    {
        QMessageBox box(this);
        box.setText("List File does not exists!");
        box.exec();
    }
}
