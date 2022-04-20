#include "ProsteOkno.hh"
#include <iostream>

using namespace std;



ProsteOkno::ProsteOkno(QWidget *wRodzic):  QWidget(wRodzic)
{
  _wEtyk = new QLabel("Nikt nie wmowi nam, ze biale to biale ...",this);
  _wEtyk->adjustSize();
  _wPrzycisk = new QPushButton("Opierajacy sie naciskom",this);
  _wPrzycisk->adjustSize();
  setMinimumWidth(_wEtyk->width()+10);
  setMinimumHeight(30+_wEtyk->height()+_wPrzycisk->height());
}


ProsteOkno::~ProsteOkno()
{
  cerr << "Destrukcja" << endl;
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
