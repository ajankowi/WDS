#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <iostream>
#include <sstream>
#include <QMainWindow>
#include <QLCDNumber>
#include <QPushButton>
#include <QMessageBox>
#include "Kanwa.hh"

using namespace std;



class OknoGlowne: public QMainWindow {
 public:
  OknoGlowne(QWidget *wRodzic = nullptr);
};



//============================================================
//................ Kanwa .....................................

Kanwa::Kanwa(QWidget *wRodzic):  QWidget(wRodzic)
{
  QPushButton  *wPrzycisk = new QPushButton(tr("Zamkniecie"),this);
  wPrzycisk->move(110,120);

  connect(wPrzycisk,SIGNAL(clicked()),this,SLOT(GdyZamkniecie()));
}



void Kanwa::GdyZamkniecie()
{
  cout << endl << "Zamykamy okienko i wysylam sygnal" << endl << endl;
  emit ZglosZamkniecie();
}

//................ Kanwa .....................................
//============================================================


//============================================================
//................ OknoGlowne ................................


OknoGlowne::OknoGlowne(QWidget *wRodzic): QMainWindow(wRodzic)
{
  Kanwa *wOknoKw = new Kanwa(this);
  resize(220,180);
  setCentralWidget(wOknoKw);
  connect(wOknoKw,SIGNAL(ZglosZamkniecie()),this,SLOT(close()));
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
