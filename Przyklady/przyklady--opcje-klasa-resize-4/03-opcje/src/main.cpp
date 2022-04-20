#include <QApplication>
#include <QWidget>
#include <iostream>

using namespace std;

void WyswietlArgumenty( int argc, char * argv[] ) 
{
  for (int i=0; i < argc; ++i)
      cout << "argv[" << i << "] = " << argv[i] << endl;
}

int main( int argc, char * argv[] ) 
{
  WyswietlArgumenty(argc,argv);

  QApplication App(argc,argv);

  cout << "===========================" << endl;
  WyswietlArgumenty(argc,argv);
}
