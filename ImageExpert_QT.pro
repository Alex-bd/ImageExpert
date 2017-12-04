#-------------------------------------------------
#
# Project created by QtCreator 2017-04-06T10:44:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageExpert
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += main.cpp\
    mainwindow.cpp \
    systemconfigs.cpp \
    cimagelabel.cpp \
    cimageprocessing.cpp \
    FileAssistant.cpp

HEADERS  += mainwindow.h \
    systemconfigs.h \
    cimagelabel.h \
    cimageprocessing.h \
    FileAssistant.h


FORMS    += mainwindow.ui \
    FileAssistant.ui


TRANSLATIONS+= languageEN.ts

RESOURCES += resource.qrc

RC_FILE = ico.rc

#copy files

INCLUDEPATH+=D:\_SDKToolkits\OpenCV\opencv320\build\include \
        D:\_SDKToolkits\OpenCV\opencv320\build\include\opencv2 \
        D:\_SDKToolkits\OpenCV\opencv320\build\include\opencv

CONFIG(debug,debug|release){
LIBS+=D:/_SDKToolkits/OpenCV/opencv320/build/x64/vc14/lib/opencv_world320.lib
}else:CONFIG(release, debug|release):{
LIBS+=D:/_SDKToolkits/OpenCV/opencv320/build/x64/vc14/lib/opencv_world320d.lib
}


