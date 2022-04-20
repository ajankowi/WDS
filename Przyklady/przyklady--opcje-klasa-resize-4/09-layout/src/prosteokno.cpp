#include <QLayout>
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

  QVBoxLayout *wOrganizerWer = new QVBoxLayout;
  wOrganizerWer->addWidget(_wEtyk);
  wOrganizerWer->addWidget(_wPrzycisk);
  setLayout(wOrganizerWer);

  resize(10,10);
}


ProsteOkno::~ProsteOkno()
{
  cerr << "Destrukcja" << endl;
}
