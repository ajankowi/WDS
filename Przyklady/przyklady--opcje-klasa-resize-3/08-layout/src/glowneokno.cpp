#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMainWindow>
#include <QStatusBar>
#include <iostream>
#include <QResizeEvent>
#include <QVBoxLayout>

using namespace std;


class ProsteOkno: public QWidget {

   QLabel      *_wEtyk;
   QPushButton *_wPrzycisk;  

  public:
   ProsteOkno(QWidget *wRodzic = nullptr);
   ~ProsteOkno() { cerr << "Destrukcja" << endl; }

};


ProsteOkno::ProsteOkno(QWidget *wRodzic):  QWidget(wRodzic)
{
  _wEtyk = new QLabel("Nikt nie wmowi nam, ze biale to biale ...",this);
  _wEtyk->adjustSize();
  _wPrzycisk = new QPushButton("Opierajacy sie naciskom",this);
  _wPrzycisk->adjustSize();
  setMinimumWidth(_wEtyk->width()+10);
  setMinimumHeight(30+_wEtyk->height()+_wPrzycisk->height());

  QVBoxLayout *wOrganizerWer = new QVBoxLayout;
  wOrganizerWer->addWidget(_wEtyk);
  wOrganizerWer->addWidget(_wPrzycisk);
  setLayout(wOrganizerWer);

  resize(10,10);
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
