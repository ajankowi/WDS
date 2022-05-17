#include <iostream>
#include <QApplication>
#include "OkienkoOdbiornika.hh"


using namespace std;




int main( int argc, char * argv[] ) 
{
  Komunikacja   LaczeKom;
  
  if (argc < 2) {
    cout << endl
	 << " Wywolanie:" << endl
	 << "     " << *argv << " urzadzenie (np. /dev/pts/30)" << endl
	 << endl;
    return 1;
  }
  

  if (!LaczeKom.OtworzPort(argv[1])) return 2;
  

  QApplication        App(argc,argv);
  OkienkoOdbiornika  *wOkno = new OkienkoOdbiornika();

  wOkno->resize(220,180);
  wOkno->UstawLacze(&LaczeKom);
  wOkno->show();  
   
  std::thread Watek(WatekOdbioru, &LaczeKom);
  
  int Wynik = App.exec();

  Watek.join();
  
  return Wynik;
}
