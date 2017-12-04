#ifndef TESTCONTROL_H
#define TESTCONTROL_H

#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>
class QDESIGNER_WIDGET_EXPORT  TestControl : public QWidget
{
    Q_OBJECT

public:
    TestControl(QWidget *parent = 0);
};

#endif
