#include "mainwindow.h"
#include <QApplication>
#include <QtSingleApplication>
#include <QTranslator>
#include <QLocale>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);


    QtSingleApplication a(argc, argv);
    if(a.isRunning())
    {
        a.sendMessage("process is already in running");
        return EXIT_SUCCESS;
    }
    QLocale locale;
    QTranslator translator;
    if (locale.language() == QLocale::English)
    {
        translator.load("/home/oneai/.config/recovery_tool/recovery_tool_en_US.qm");
        a.installTranslator(&translator);
    }

    Mainwindow w;
    w.show();

    QObject::connect(&a, &QtSingleApplication::messageReceived, &w, &Mainwindow::showNormal);

    return a.exec();
}
