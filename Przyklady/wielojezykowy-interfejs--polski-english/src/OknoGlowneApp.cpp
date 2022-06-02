
#ifdef __GNUG__
# pragma implementation 
#endif


#include <QApplication>
#include <QColor>
#include <QPainter>
#include <QStatusBar>
#include <QTime>
#include <QDate>
#include <QString>
#include <QFileDialog>
#include <QTime>
#include <QDate>
#include <iostream>
#include <QTranslator>
#include <QEvent>


#include "OknoGlowneApp.hh"

using namespace std;

//==============================================================================
//................ OknoGlowneAplikacji .........................................

OknoGlowneAplikacji::OknoGlowneAplikacji()
{
  setupUi(this);
  QString Napis;

  Napis = QDate::currentDate().toString();
  _wNapis_Czas->setText(Napis);

  _wWyborJezyka->addItem("English");
  _wWyborJezyka->addItem("Polski");
  //  _wNapis_Czas->hide();
  //  _wEtykieta_Data->hide();
}


void OknoGlowneAplikacji::on_action_Open_triggered(bool)
{
 QString NazwaPliku = QFileDialog::getOpenFileName(this,tr("Otworz plik"));


}


void OknoGlowneAplikacji::on_action_Exit_triggered(bool)
{
  qApp->exit();  
}


void OknoGlowneAplikacji::on__wPrzycisk_Koniec_clicked()
{
  qApp->exit();
}

void OknoGlowneAplikacji::changeEvent(QEvent *event)
{
    if ( event->type() == QEvent::LanguageChange ) {
        cout << "Zmiana" << endl;
	retranslateUi(this);  
        return;
    } 
    QMainWindow::changeEvent(event);
}


//................ OknoGlowneAplikacji .........................................
//==============================================================================


void OknoGlowneAplikacji::on__wWyborJezyka_currentIndexChanged(int Idx)
{
  static QTranslator *wTlumaczPL = new QTranslator();


    switch (Idx) {
        case 0: {
           qApp->removeTranslator(wTlumaczPL);
	    QLocale  Locale4EN(QLocale::English);
	   _wNapis_Czas->setText(Locale4EN.toString(QDate::currentDate()));
           //_wNapis_Czas->setText(QDate::currentDate().toString());
	   _pLabel_Flag->setPixmap(QPixmap(QString::fromUtf8(":/icons/flag.png")));
	   _wWyborJezyka->setCurrentIndex(0);  // To jest ważne
           break;
	}
	case 1: {
           if (wTlumaczPL->load("pro/interapp_pl.qm",".") ) {
               qApp->installTranslator(wTlumaczPL);
               QLocale  Locale4PL(QLocale::Polish);
               _wNapis_Czas->setText(Locale4PL.toString(QDate::currentDate()));
	       _pLabel_Flag->setPixmap(QPixmap(QString::fromUtf8(":/icons/flag_pl.png")));
               _wWyborJezyka->setCurrentIndex(1);
           } else cerr << "!!! Plik ’interapp_pl.qm’"
                          " nie zostal zaladowany." << endl;
           break;
	}
    }
}

