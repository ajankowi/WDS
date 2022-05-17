#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <QApplication>
#include <iostream>
#include "OkienkoOdbiornika.hh"
#include "transparam.hh"

using namespace std;


int main( int argc, char * argv[] ) 
{
  int    DeskPortu;
  
  if (argc < 2) {
    cout << endl
	 << " Wywolanie:" << endl
	 << "     " << *argv << " urzadzenie (np. /dev/pts/30)" << endl
	 << endl;
    return 1;
  }

  if ((DeskPortu = open(argv[1],O_RDWR | O_NONBLOCK)) < 0) {
    cerr << ":( Blad otwarcia portu " << argv[1] << endl;  
    exit(1);
  }
  SetTransParam(DeskPortu);

  
  QApplication App(argc,argv);
  OkienkoOdbiornika   *wOkno = new OkienkoOdbiornika();

  wOkno->resize(220,180);
  wOkno->UstawDeskPortu(DeskPortu);
  wOkno->show();
  
  return App.exec();
}
