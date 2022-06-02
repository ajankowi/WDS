#include <QApplication>
#include "OknoGlowneApp.hh"
#include <QLocale>
#include <iostream>

using namespace std;


int main( int argc, char * argv[] ) 
{
  QApplication App(argc,argv);
  OknoGlowneAplikacji  Okno;

  cout << "Locale: " << QLocale::system().name().toStdString() << endl;
  if (QLocale::system().name() == "pl_PL") {
    Okno.on__wWyborJezyka_currentIndexChanged(1);
  }
  Okno.show();

  return App.exec();
}
