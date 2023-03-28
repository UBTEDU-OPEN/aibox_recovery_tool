#-------------------------------------------------
#
# Project created by QtCreator 2021-07-12T17:32:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TRANSLATIONS += cn.ts \
                en.ts

TARGET = recovery_tool
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    titlebar.cpp \
    content.cpp \
    dialog.cpp \
    tempmask.cpp

HEADERS += \
        mainwindow.h \
    titlebar.h \
    content.h \
    dialog.h \
    tempmask.h

FORMS += \
        mainwindow.ui \
    titlebar.ui \
    content.ui \
    dialog.ui \
    tempmask.ui

RESOURCES += \
    icon.qrc


include(qtsingleapplication/src/qtsingleapplication.pri)

DISTFILES += \
    recovery_tool_zh_CN.ts \
    recovery_tool_en_US.ts
