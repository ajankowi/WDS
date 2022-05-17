/*****************************************************************************
 * Copyright (c) 2021 Bogdan Kreczmer, wszystkie prawa zastrzezone
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

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif


#include <cassert>
#include <QWidget>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLineEdit>
#include <QProgressBar>
#include <QCloseEvent>
#include "OkienkoOdbiornika.hh"
#include "WatekOdbioru.hh"




using namespace std;



//==============================================================================
//................ OkienkoOdbiornika ...........................................

OkienkoOdbiornika::OkienkoOdbiornika(QWidget *wRodzic): QWidget(wRodzic)
{
  QGridLayout *wOrganizer = new QGridLayout(this);

  setAttribute(Qt::WA_DeleteOnClose);
  
  _Stoper.setObjectName("Stoper");
  _Stoper.setParent(this);
  _wListaElem = new QListWidget(this);
  
  _wListaElem->setObjectName("_wListaElem");

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

  _Stoper.setInterval(100);
  _Stoper.setSingleShot(true);
  _Stoper.start();
}



//-----------------------------------------------------------
//  Schemat tworzenia nazw slotow:
//     on_<nazwa_zrodla_sygnalu>_<nazw_syngalu>
//

void OkienkoOdbiornika::on__wListaElem_itemClicked(QListWidgetItem *wElem)
{
  _wEdycja->setText(wElem->text());
}



void OkienkoOdbiornika::UmiescTekstNaLiscie(const QString& Tekst)
{
  _wListaElem->addItem(Tekst);
  if (_wListaElem->count() > 6) {
    delete _wListaElem->takeItem(0);
  }
  _wBelkaPostepu->setValue(++_Postep % 10);
}



void OkienkoOdbiornika::on_Stoper_timeout()
{
  std::string  Napis;

  assert(_wLacze != nullptr);

  if (_Start) {
    while (_wLacze->WezBufNap().JestNapis()) {
      if (!_wLacze->UzyjBufNap().PobierzNapis(Napis)) continue;
      UmiescTekstNaLiscie(Napis.c_str());
    }
  }
  _Stoper.start();
}



void OkienkoOdbiornika::on_EdycjaTekstu_returnPressed()
{
  UmiescTekstNaLiscie(_wEdycja->text());
}



void OkienkoOdbiornika::on__wPrzycisk_Start_toggled(bool Checked)
{
  _Start = Checked;
}



void OkienkoOdbiornika::closeEvent(QCloseEvent *pEvent)
{
  ZakonczOdbior();
  pEvent->accept();
}




//................ OkienkoOdbiornika ...........................................
//==============================================================================

