#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <iostream>
#include <sstream>
#include <QMainWindow>
#include <QPushButton>
#include <QBrush>
#include <QPalette>
#include <unistd.h>

using namespace std;


/*=========================================================================
 * Przyklad demonstruje tworzenia wlasnej metody realizujacej
 * operacje rysowania oraz sposob wymuszania operacji odrysowania. 
 */


class OknoZRysunkiem: public QWidget {
 public:
  OknoZRysunkiem(QWidget *wRodzic = nullptr);

  virtual void paintEvent( QPaintEvent * event );

 private:
  static int _Numer;
};


class Kanwa: public QWidget {
 public:
  Kanwa(QWidget *wRodzic = nullptr);
};



class OknoGlowne: public QMainWindow {
 public:
  OknoGlowne(QWidget *wRodzic = nullptr);
};


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

  connect(wPrzyciskRysuj,SIGNAL(clicked()),wOkRys,SLOT(update()));
}

//................ Kanwa .....................................
//============================================================


//============================================================
//................ OknoGlowne ................................


OknoGlowne::OknoGlowne(QWidget *wRodzic): QMainWindow(wRodzic)
{
  Kanwa *wOknoKw = new Kanwa(this);
  resize(300,200);
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
