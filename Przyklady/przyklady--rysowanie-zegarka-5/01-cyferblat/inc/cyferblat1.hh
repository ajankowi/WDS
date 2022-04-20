#ifndef CYFERBLAT1_HH
#define CYFERBLAT1_HH

/*****************************************************************************
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
 * Autor: Bogan Kreczmer
 *****************************************************************************/


#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif


#include <QWidget>
#include <QMainWindow>


class Zegar: public QWidget { //------------------------------------------------
  public:
    Zegar(QWidget *wRodzic = nullptr);
    virtual void paintEvent( QPaintEvent * event ) override;

}; //---------------------------------------------------------------------------


class OknoGlowne: public QMainWindow { //---------------------------------------
  public:
   OknoGlowne(QWidget *wRodzic = nullptr);
}; //---------------------------------------------------------------------------


#endif
