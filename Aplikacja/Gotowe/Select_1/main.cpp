

#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

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
