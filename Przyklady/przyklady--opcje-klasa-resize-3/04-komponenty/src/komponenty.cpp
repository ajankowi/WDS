#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>


int main( int argc, char * argv[] ) 
{
  QApplication App(argc,argv);
  QWidget      Okno;

  
  QLabel *wEtyk = new QLabel(QObject::tr("Nikt nie wmowi nam, ze biale to biale ..."),&Okno);
  wEtyk->move(10,10);

  QPushButton *wPrzycisk = new QPushButton(QObject::tr("Opierajacy sie naciskom"),&Okno);
  wPrzycisk->move(30,50);

  Okno.resize(230,90);
  Okno.show();

  return App.exec();
}
