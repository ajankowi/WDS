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
#include <QProgressBar>
#include <QIcon>
#include <QCloseEvent>
#include <iostream>
#include "odbieranie.hh"
#include "transparam.hh"

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



//==============================================================================
//................ Kanwa .......................................................

Kanwa::Kanwa(QWidget *wRodzic): QWidget(wRodzic), _Start(false), _DeskPortu(0), _Postep(0)
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

  _wBelkaPostepu = new QProgressBar(this);
  _wBelkaPostepu->setRange(0,9);

  wOrganizer->addWidget(_wListaElem,0,0,1,2);
  wOrganizer->addWidget(_wEdycja,1,0,1,2); 
  wOrganizer->addWidget(_wBelkaPostepu,2,0,1,2);
  wOrganizer->addWidget(_wPrzycisk_Start,3,1);
  setLayout(wOrganizer);

  QMetaObject::connectSlotsByName(this);
}

//     on_<nazwa_zrodla_sygnalu>_<nazw_syngalu>

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
  _wBelkaPostepu->setValue(++_Postep % 10);
}


void Kanwa::on_EdycjaTekstu_returnPressed()
{
  UmiescTekstNaLiscie(_wEdycja->text());
}





void Kanwa::on__wPrzycisk_Start_toggled(bool Checked)
{
  cout << " Start: " << Checked << endl;
  if (!Checked) { _Start = false;  return; }
  _Start = true;
  string   Bufor;
  while (_Start && _wPrzycisk_Start->isChecked()) {
    if(RS232_Odbierz(WezDeskPortu(),Bufor,1000,100)) {
      UmiescTekstNaLiscie(Bufor.c_str());
    }
    qApp->processEvents();
  }
}



//................ Kanwa .......................................................
//==============================================================================


//==============================================================================
//................ OknoGlowne ..................................................


OknoGlowne::OknoGlowne(QWidget *wRodzic): QMainWindow(wRodzic)
{
  _wKanwa = new Kanwa(this);
  setCentralWidget(_wKanwa);
  setAttribute(Qt::WA_DeleteOnClose);
}


void OknoGlowne::closeEvent(QCloseEvent *pEvent)
{
  _wKanwa->ZakonczOdbior();
  qApp->processEvents();
  pEvent->accept();
}



//................ OknoGlowne ..................................................
//==============================================================================




int main( int argc, char * argv[] ) 
{
  int    DeskPortu;
  
  if (argc < 2) {
    cout << endl
	 << " Wywolanie:" << endl
	 << "     " << *argv << " urzadzenie (np. /dev/pts/30)" << endl
	 << endl;
    return 1;
  }

  if ((DeskPortu = open(argv[1],O_RDWR | O_NONBLOCK)) < 0) {
    cerr << ":( Blad otwarcia portu " << argv[1] << endl;  
    exit(1);
  }
  SetTransParam(DeskPortu);


  QApplication App(argc,argv);
  OknoGlowne   *wOkno = new OknoGlowne();

  wOkno->resize(220,180);
  wOkno->UstawDeskPortu(DeskPortu);
  wOkno->show();

  return App.exec();
}
