#ifndef SYSTEMCONFIGS_H
#define SYSTEMCONFIGS_H
#include <QSettings>

class SystemConfigs
{
public:
    SystemConfigs();
public:
    QString m_workSpaceFloder;//临时文件的目录
    int m_language;//语言
    QString m_lastSelectdExportFloder;//上次导出所选的路径
    QString m_lastSaveFloder;//上次保存文件的路径
    QString m_lastOpenFileFloder; //上次打开文件的文件夹
public:
    void loadConfig();
    void writeConfig();
    void setDefaultConfig();
};

#endif // SYSTEMCONFIGS_H
