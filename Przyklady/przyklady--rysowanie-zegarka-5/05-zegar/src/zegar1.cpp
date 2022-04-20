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
 *****************************************************************************/

#include <QApplication>
#include <QColor>
#include <QPainter>
#include <QStatusBar>
#include <QTime>
#include <QDate>

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif


#include "zegar1.hh"


/*==============================================================================
 * Przyklad demonstruje wykorzystanie obiektu klasy QTimer oraz transformacji
 * ukladu wspolrzednych przy rysowaniu na obiekcie klasy QWidget. Rysowana jest
 * podzialka minutowa i godzinna oraz oznaczenia godzin. Napisy sa rozlozone
 * wewnatrz cyferblatu i prawidlowo obrocone w sposob czytelny dla uzytkownika.
 * Ponadto rysowane sa wskazowki zegara. 
 * Sam zegar napedzany jest poprzez wykorzystanie obiektu QTimer.
 */


//==============================================================================
//................ Zegar .......................................................

Zegar::Zegar(QWidget *wRodzic):  QWidget(wRodzic)
{
  setAutoFillBackground(true);
  setPalette(QPalette(Qt::white));
  connect(&_Sekundnik,SIGNAL(timeout()),this,SLOT(GdySekunda()));
  _Sekundnik.setInterval(1000);
  _Sekundnik.setSingleShot(false);
  _Sekundnik.start();
}



#define ZN_KROTKI        4
#define ZN_DLUGI         8
#define MARGINES        10
#define ODSTEP_ZNAKU    16
#define PRZESUNIECIE_X   3

#define WSKSEK_D     8





void Zegar::RysujJednaWskazowke( QPainter& Rysownik, 
                                 int       Dlugosc, 
                                 int       Grubosc, 
                                 int       KatObr
                               )
{
  QPen Piorko(Rysownik.pen());

  Piorko.setWidth(Grubosc);
  Rysownik.setPen(Piorko);
  Rysownik.rotate(KatObr);
  Rysownik.drawLine(0,-Dlugosc+WSKSEK_D,0,WSKSEK_D);
  Rysownik.rotate(-KatObr);  
}



void Zegar::RysujWskazowki( QPainter &  Rysownik, int Promien )
{
  QTime  Czas;

  Czas.start();
  int  KatObr = 6*Czas.second();
  
  RysujJednaWskazowke(Rysownik,Promien,1,KatObr);
  RysujJednaWskazowke(Rysownik,static_cast<int>(Promien*0.8),3,
                                   6*Czas.minute());
  RysujJednaWskazowke(Rysownik,static_cast<int>(Promien*0.5),6,
                                   30*Czas.hour() + 30*Czas.minute()/60);
}





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
       Rysownik.translate(0,-Promien+ODSTEP_ZNAKU);
       Rysownik.rotate(-6*Min);
       Rysownik.drawText(-PRZESUNIECIE_X,4,Godzina);
       Rysownik.rotate(6*Min);
       Rysownik.translate(0,Promien-ODSTEP_ZNAKU);
    } else {
       Rysownik.drawLine(0,Promien-ZN_KROTKI,0,Promien);
    }
  }
  RysujWskazowki(Rysownik,Promien);
}



void Zegar::GdySekunda()
{
  update();
  QString Data = QDate::currentDate().toString();
  emit ZglosNapis(Data);
}

//................ Zegar .......................................................
//==============================================================================


//==============================================================================
//................ OknoGlowne ..................................................


void OknoGlowne::GdyNapis(const QString &Napis)
{
  statusBar()->showMessage(Napis);
}


OknoGlowne::OknoGlowne(QWidget *wRodzic): QMainWindow(wRodzic)
{
  Zegar *wOkno = new Zegar(this);
  setCentralWidget(wOkno);
  setStatusBar(new QStatusBar());
  connect(wOkno,SIGNAL(ZglosNapis(const QString &)),
          this,SLOT(GdyNapis(const QString &)));
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
