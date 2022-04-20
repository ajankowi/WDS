#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMainWindow>
#include <QStatusBar>
#include <iostream>

using namespace std;


class ProsteOkno: public QWidget {
  public:
   ProsteOkno(QWidget *wRodzic = nullptr);
  ~ProsteOkno() { cerr << "Destrukcja" << endl; }
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
 QMainWindow  GlowneOkno;

 GlowneOkno.setCentralWidget(new ProsteOkno());
 GlowneOkno.setStatusBar(new QStatusBar());
 GlowneOkno.statusBar()->showMessage(QObject::tr("Start aplikacji"));
 GlowneOkno.show();

 return App.exec();
}
