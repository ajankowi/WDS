#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <iostream>

using namespace std;


class ProsteOkno: public QWidget {
  public:
   ProsteOkno(QWidget *wRodzic = 0L);
};


ProsteOkno::ProsteOkno(QWidget *wRodzic):  QWidget(wRodzic)
{
  QLabel *wEtyk = new QLabel("Nikt nie wmowi nam, ze biale to biale ...",this);
  wEtyk->move(10,10);

  QPushButton *wPrzycisk = new QPushButton("Opierajacy sie naciskom",this);
  wPrzycisk->move(30,50);

  resize(230,90);
}



int main( int argc, char * argv[] ) 
{
  QApplication App(argc,argv);
  ProsteOkno   Okno;

  Okno.show();

  return App.exec();
}
