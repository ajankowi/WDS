#include <iostream>
#include <QApplication>
#include <QThread>
#include "OkienkoOdbiornika.hh"


using namespace std;




int main( int argc, char * argv[] ) 
{
  QApplication        App(argc,argv);
  Komunikacja         LaczeKom;
  Watek               WatekOdbioru(&LaczeKom);

  
  if (argc < 2) {
    cout << endl
	 << " Wywolanie:" << endl
	 << "     " << *argv << " urzadzenie (np. /dev/pts/30)" << endl
	 << endl;
    return 1;
  }
  
  LaczeKom.UstawNazwePortu(argv[1]);
  


  OkienkoOdbiornika  *wOkno = new OkienkoOdbiornika();

  wOkno->resize(220,180);
  wOkno->UstawLacze(&LaczeKom);
  wOkno->show();
   

  WatekOdbioru.start();
  int Wynik = App.exec();

  WatekOdbioru.wait();
  
  return Wynik;
}
