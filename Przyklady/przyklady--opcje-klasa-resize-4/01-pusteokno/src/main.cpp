#include <QApplication>
#include <QWidget>


int main( int argc, char * argv[] ) 
{
  QApplication App(argc,argv);
  QWidget      Okno;

  Okno.show();

  return App.exec();
}


