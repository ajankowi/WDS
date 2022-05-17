#ifndef OKIENKOODBIORNIKA_HH
#define OKIENKOODBIORNIKA_HH

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

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



#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include <QProgressBar>


class OkienkoOdbiornika: public QWidget { //-----------------------------------------------
    Q_OBJECT
    bool  _Start = false;
    int   _DeskPortu = 0;

    int           _Postep = 0;
    QListWidget  *_wListaElem = nullptr;
    QProgressBar *_wBelkaPostepu = nullptr;
    QLineEdit    *_wEdycja = nullptr; 
    QPushButton  *_wPrzycisk_Start = nullptr;

  public:
    OkienkoOdbiornika(QWidget *wRodzic = nullptr);

    void UstawDeskPortu(int DeskPortu) { _DeskPortu = DeskPortu; }
    int  WezDeskPortu() const { return _DeskPortu; }
    void UmiescTekstNaLiscie(const QString& Tekst);
    void ZakonczOdbior() { _Start = false; }

  public slots:
    void on__wListaElem_itemClicked(QListWidgetItem *wElem);
    void on_EdycjaTekstu_returnPressed();
    void on__wPrzycisk_Start_toggled(bool Checked);
}; //--------------------------------------------------------------------------


#endif
