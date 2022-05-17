/*****************************************************************************
 * Copyright (c) 2007-2008 Bogdan Kreczmer, wszystkie prawa zastrzezone
 *
 * Niniejszy plik zostal utworzony jako przyklad na potrzebe nauki
 * programowania z wykorzystaniem biblioteki Qt w ramach kursu
 * "Wizualizacja danych sensorycznych" prowadzonym na specjalnosci Robotyka,
 * kierunku Automatyka i Robotyka, Wydzialu Elektroniki Politechniki
 * Wroclawskiej.
 * Plik ten jest udostepniany na licencji GNU General Public License v. 3.
 * 
 * Niniejszy plik nie jest objety zadnymi gwarancjami, ze bedzie mogl byc
 * wykorzystany do innych celow nie zwiazanych z nauka programowania.
 *
 *****************************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLineEdit>
#include <QIcon>
#include <iostream>
#include "odbieranie.hh"
#include "transparam.hh"
#include <QThread>
#include <QCloseEvent>
#include <unistd.h>

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

using namespace std;

#include "okienko_odbiornika.hpp"

using namespace std;

/*==============================================================================
 * Przyklad demonstruje uzycie QListWidget. Sposób pos³ugiwania siê wy¶wietlan±
 * list± w tym przyk³adzie wymusza ustawienie wszystkich elementów w porzadku
 * alfabetycznym.
 */




void WatekOdbioru::run()
{
 cout << "Poczatek" << endl;
  _Start = true;
  string   Bufor;
  while (_Start) {
    if(RS232_Odbierz(_wKanwa->WezDeskPortu(),Bufor,1000,100)) {
      _wKanwa->UmiescTekstNaLiscie(Bufor.c_str());
    }
  }
 cout << "Koniec" << endl;
}


//==============================================================================
//................ Kanwa .......................................................

Kanwa::Kanwa(QWidget *wRodzic): QWidget(wRodzic), _Start(false), _DeskPortu(0),
				_WatekOdb(this,this)
{
  QGridLayout *wOrganizer = new QGridLayout(this);
  QIcon        Icon4Progress;

  _wListaElem = new QListWidget(this);
  
  _wListaElem->setObjectName("_wListaElem");
  //  _wListaElem->setSortingEnabled(true); // <*** Tutaj wymuszamy sortowanie
  /*
  for (int i = 1; i < 5; ++i) {
    StQ:: MakeIcon4CheckProgress(Icon4Progress,i*20);
    _wListaElem->addItem(new QListWidgetItem(Icon4Progress,
                                             tr("Napis %1").arg(i)));
  }
  */
  _wEdycja = new QLineEdit(this);
  _wEdycja->setObjectName("EdycjaTekstu");
  _wPrzycisk_Start = new QPushButton(tr("Start"));
  _wPrzycisk_Start->setObjectName("_wPrzycisk_Start");
  _wPrzycisk_Start->setCheckable(true);

  wOrganizer->addWidget(_wListaElem,0,0,1,2);
  wOrganizer->addWidget(_wEdycja,1,0,1,2); 
  wOrganizer->addWidget(_wPrzycisk_Start,2,1);
  setLayout(wOrganizer);

  QMetaObject::connectSlotsByName(this);
}


void Kanwa::on__wListaElem_itemClicked(QListWidgetItem *wElem)
{
  _wEdycja->setText(wElem->text());
}


void Kanwa::UmiescTekstNaLiscie(const QString& Tekst)
{
  _wListaElem->addItem(Tekst);
  if (_wListaElem->count() > 6) {
    delete _wListaElem->takeItem(0);
  }
}


void Kanwa::on_EdycjaTekstu_returnPressed()
{
  UmiescTekstNaLiscie(_wEdycja->text());
}



void Kanwa::on__wPrzycisk_Start_toggled(bool Checked)
{
  if (Checked){ _WatekOdb.Start(); }
  else _WatekOdb.Stop();
}



//................ Kanwa .......................................................
//==============================================================================


//==============================================================================
//................ OknoGlowne ..................................................


OknoGlowne::OknoGlowne(QWidget *wRodzic): QMainWindow(wRodzic)
{
  _wKanwa = new Kanwa(this);
  setCentralWidget(_wKanwa);
}


void OknoGlowne::closeEvent(QCloseEvent *pEvent)
{
  cout << "Zamykanie ...." << endl;
  _wKanwa->ZakonczOdbior();
  _wKanwa->CzekajNaKoniecWatku();
  pEvent->accept();
}

//................ OknoGlowne ..................................................
//==============================================================================




int main( int argc, char * argv[] ) 
{
  int    DeskPortu;
  
  if ((DeskPortu = open("/dev/ttyUSB0",O_RDWR | O_NONBLOCK)) < 0) {
    cerr << ":( Blad otwarcia portu USB0" << endl;  
    exit(1);
  }
  SetTransParam(DeskPortu);


  QApplication App(argc,argv);
  OknoGlowne   Okno;

  Okno.resize(220,180);
  Okno.UstawDeskPortu(DeskPortu);
  Okno.show();

  return App.exec();
}
