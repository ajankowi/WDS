

#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    /*
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Thread_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    */

     QTranslator t;
    QStringList languages;

    languages << "Polski" << "English";

    QString lang = QInputDialog::getItem(NULL,"Select language","Language",languages);


    if( lang == "English"){
        t.load("/home/adam_j4/Qt/Select_1/english.qm");

    }
    if(lang != "Polski"){

        a.installTranslator(&t);

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
