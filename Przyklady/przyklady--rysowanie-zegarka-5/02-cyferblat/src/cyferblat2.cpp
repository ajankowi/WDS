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

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif


#include "cyferblat2.hh"


/*==============================================================================
 * Przyklad demonstruje wykorzystanie transformacji ukladu wspolrzednych
 * przy rysowaniu na obiekcie klasy QWidget. Rysowana jest podzialka minutowa
 * i godzinna oraz oznaczenia godzin. Napisy sa rozlozone wewnatrz cyferblatu.
 */


//==============================================================================
//................ Zegar .......................................................

Zegar::Zegar(QWidget *wRodzic):  QWidget(wRodzic)
{
  setAutoFillBackground(true);
  setPalette(QPalette(Qt::white));
}



#define ZN_KROTKI        4
#define ZN_DLUGI         8
#define MARGINES        10
#define ODSTEP_ZNAKU    20
#define PRZESUNIECIE_X   3



void Zegar::paintEvent( QPaintEvent * )
{
  QPainter Rysownik(this);
  QString  Godzina;
 
  int Promien = width() > height() ? height()/2 : width()/2;
  Promien -= MARGINES;


  Rysownik.translate(width()/2,height()/2);
  for (int Min = 1; Min < 61; ++Min ) {
    Rysownik.rotate(6);
    if (!(Min % 5)) {
       Rysownik.drawLine(0,-Promien+ZN_DLUGI,0,-Promien);
       Godzina.setNum(Min / 5);
       Rysownik.drawText(-PRZESUNIECIE_X,-Promien+ODSTEP_ZNAKU,Godzina);
    } else {
       Rysownik.drawLine(0,Promien-ZN_KROTKI,0,Promien);
    }
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
