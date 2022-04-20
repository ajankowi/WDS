#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <iostream>
#include <sstream>
#include <QMainWindow>
#include <QPushButton>
#include <QBrush>
#include <QPalette>
#include <QStatusBar>
#include <unistd.h>
#include <QString>

#include "rysowanie.hh"

using namespace std;


/*===========================================================
 * Przyklad demonstruje tworzenie wlasnego sygnalu, ktory
 * przekazuje argument.
 */


//============================================================
//................ OknoZRysunkiem ............................

int OknoZRysunkiem::_Numer = 0;


OknoZRysunkiem::OknoZRysunkiem(QWidget *wRodzic): QWidget(wRodzic) 
{
  setPalette(QPalette(Qt::white));
  setAutoFillBackground(true);
}


void OknoZRysunkiem::paintEvent(QPaintEvent *)
{
  QPainter  Rysownik(this);
  Rysownik.setBackground(Qt::white);

  QString  Napis = tr("Odrysowanie nr: %1").arg(++_Numer);

  Rysownik.drawText(30,30,Napis); 
  Rysownik.fillRect(10,50,8*(_Numer % 25 +2),80,Qt::green);
  Rysownik.fillRect(10,50,8*(_Numer % 25),80,Qt::blue);

  emit ZglosNapisGdyRysowanie(Napis);
}

//................ OknoZRysunkiem ............................
//============================================================


//============================================================
//................ Kanwa .....................................

Kanwa::Kanwa(QWidget *wRodzic):  QWidget(wRodzic)
{
  OknoZRysunkiem  *wOkRys = new OknoZRysunkiem(this);
  wOkRys->setGeometry(10,10,250,150);

  QPushButton *wPrzyciskRysuj = new QPushButton(tr("Rysuj"),this);
  wPrzyciskRysuj->move(190,170);

  _wNapis = new QLabel(this);
  _wNapis->setGeometry(10,170,140,20);

  connect(wPrzyciskRysuj,SIGNAL(clicked()),wOkRys,SLOT(update()));
  connect(wOkRys,SIGNAL(ZglosNapisGdyRysowanie(const QString &)),
          this,SLOT(OdbierzNapisGdyRysuj(const QString &)));
}

void Kanwa::OdbierzNapisGdyRysuj(const QString &Napis)
{
  _wNapis->setText(Napis);
}

//................ Kanwa .....................................
//============================================================


//============================================================
//................ OknoGlowne ................................


OknoGlowne::OknoGlowne(QWidget *wRodzic): QMainWindow(wRodzic)
{
  Kanwa *wOknoKw = new Kanwa(this);
  setStatusBar(new QStatusBar());
  resize(300,230);
  setCentralWidget(wOknoKw);
}

//................ OknoGlowne ................................
//============================================================




int main( int argc, char * argv[] ) 
{
  QApplication App(argc,argv);
  OknoGlowne   Okno;

  Okno.show();

  return App.exec();
}
