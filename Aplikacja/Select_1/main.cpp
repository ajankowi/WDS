

#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Thread_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;
    w.show();
    return a.exec();
}


/*
#include "viewer.h"
#include <qapplication.h>

int main(int argc, char **argv) {
  QApplication application(argc, argv);

  Viewer viewer;

  viewer.setWindowTitle("animation");

  viewer.show();

  return application.exec();
}
*/
