#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMainWindow>
#include <QStatusBar>
#include <iostream>
#include <QResizeEvent>
#include <iostream>


using namespace std;


class ProsteOkno: public QWidget {

   QLabel      *_wEtyk;
   QPushButton *_wPrzycisk;  

  public:
   ProsteOkno(QWidget *wRodzic = nullptr);
   ~ProsteOkno() { cerr << "Destrukcja" << endl; }

   virtual void resizeEvent( QResizeEvent  *wZdarz ) override;
};


ProsteOkno::ProsteOkno(QWidget *wRodzic):  QWidget(wRodzic)
{
  _wEtyk = new QLabel("Nikt nie wmowi nam, ze biale to biale ...",this);
  _wEtyk->adjustSize();
  _wPrzycisk = new QPushButton("Opierajacy sie naciskom",this);
  _wPrzycisk->adjustSize();
  setMinimumWidth(_wEtyk->width()+10);
  setMinimumHeight(30+_wEtyk->height()+_wPrzycisk->height());
  resize(10,10);
}



void ProsteOkno::resizeEvent( QResizeEvent *wZdarz )
{
  int  x, y;

  cout << "----------- Resize --------------" << endl;

  x = (width()-_wPrzycisk->width())/2; 
  y = (height() - _wPrzycisk->height() - 10);
  _wPrzycisk->move(x,y);

  x = (width() <= _wEtyk->width()) ? 0 : (width()-_wEtyk->width())/2; 
  y = 10;
  _wEtyk->move(x,y);  
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
