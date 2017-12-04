#include "systemconfigs.h"
#include <QFile>
#include <QDebug>
SystemConfigs::SystemConfigs()
{

}

///
/// \brief 加载系统配置信息
///
void SystemConfigs::loadConfig()
{
    QFile f("config.ini");
    if(!f.exists())
    {
        setDefaultConfig();
    }
    else
    {
        QSettings setting("config.ini",QSettings::IniFormat);
        m_workSpaceFloder = setting.value("system/workSpace").toString();
        m_language = setting.value("system/currentLanguage").toInt();
        m_lastSelectdExportFloder = setting.value("system/lastSelectedExportFloder").toString();
        m_lastOpenFileFloder = setting.value("system/lastOpenFileFloder").toString();
        m_lastSaveFloder = setting.value("system/lastSaveFloder").toString();
    }

}

///
/// \brief 写入系统配置信息
///
void SystemConfigs::writeConfig()
{
    QSettings setting("config.ini",QSettings::IniFormat);
    setting.setValue("system/workSpace",m_workSpaceFloder);
    setting.setValue("system/currentLanguage",m_language);
    setting.setValue("system/lastSelectedExportFloder",m_lastSelectdExportFloder);
    setting.setValue("system/lastOpenFileFloder",m_lastOpenFileFloder);
    setting.setValue("system/lastSaveFloder",m_lastSaveFloder);
}

void SystemConfigs::setDefaultConfig()
{
    m_workSpaceFloder = "C:/ProgramData/ImageExpert/";
    m_language = 0;
    m_lastSelectdExportFloder=QString();
    m_lastOpenFileFloder = QString();
    m_lastSaveFloder = QString();
    writeConfig();
}
