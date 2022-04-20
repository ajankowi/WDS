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

#include <QApplication>
#include <QMainWindow>
#include <QColor>
#include <QPainter>
#include <QStatusBar>
#include <iostream>

using namespace std;

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif


#include "cyferblat1.hh"


/*==============================================================================
 * Przyklad demonstruje wykorzystanie transformacji ukladu wspolrzednych
 * przy rysowaniu na obiekcie klasy QWidget.
 */


//==============================================================================
//................ Zegar .......................................................

Zegar::Zegar(QWidget *wRodzic):  QWidget(wRodzic)
{
  setAutoFillBackground(true);
  setPalette(QPalette(Qt::white));
}



#define ZN_KROTKI    4
#define ZN_DLUGI     8
#define MARGINES     5

void Zegar::paintEvent( QPaintEvent * )
{
  QPainter Rysownik(this);

  int Promien = width() > height() ? height()/2 : width()/2;
  Promien -= MARGINES;

  Rysownik.translate(width()/2,height()/2);
  for (int Min = 0; Min < 60; ++Min) {
    if (!(Min % 5)) {
       Rysownik.drawLine(0,-Promien+ZN_DLUGI,0,-Promien);
    } else {
       Rysownik.drawLine(0,-Promien+ZN_KROTKI,0,-Promien);
    }
    Rysownik.rotate(6);
  }
}

//................ Zegar .......................................................
//==============================================================================


//==============================================================================
//................ OknoGlowne ..................................................


OknoGlowne::OknoGlowne(QWidget *wRodzic): QMainWindow(wRodzic)
{
  Zegar *wOkno = new Zegar(this);
  setCentralWidget(wOkno);
  setStatusBar(new QStatusBar());
}

//................ OknoGlowne ..................................................
//==============================================================================




int main( int argc, char * argv[] ) 
{
  QApplication App(argc,argv);
  OknoGlowne   Okno;

  Okno.show();
  

  return App.exec();
}
