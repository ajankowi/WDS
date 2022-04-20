#include <QApplication>
#include <QWidget>


int main( int argc, char * argv[] ) 
{
  QApplication App(argc,argv);
  QWidget      Okno;

  Okno.show();
  Okno.setWindowTitle("Bardzo proste okno");
  Okno.setGeometry(0,100,300,150);

  return App.exec();
}
