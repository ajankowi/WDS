#include <QApplication>
#include <QWidget>
#include <iostream>
#include <QMainWindow>
#include <QPushButton>
#include "Kanwa.hh"

using namespace std;

/*================================================================
 * Przyklad demonstruje tworzenie wlasnego slotu.
 */



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


//...................................
// Definicja slotu
//
void Kanwa::GdyZamkniecie()
{
  cout << endl << "Zamykamy okienko" << endl << endl;
  static_cast<QWidget*>(parent())->close();
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
