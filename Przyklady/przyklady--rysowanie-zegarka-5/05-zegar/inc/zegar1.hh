#ifndef ZEGAR1_HH
#define ZEGAR1_HH

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
#include <QTimer>
#include <QPainter>




class Zegar: public QWidget { //---------------------------------------
    Q_OBJECT
  public:
    Zegar(QWidget *wRodzic = 0L);
    virtual void paintEvent ( QPaintEvent * event ) override;
    void RysujWskazowki(QPainter&, int Promien);
    void RysujJednaWskazowke(QPainter&, int Dlugosc, int Grubosc, int Kat );

  public slots:
    void GdySekunda(); 

  signals:  
    void ZglosNapis(const QString &);

  private:
    QTimer _Sekundnik;
}; //------------------------------------------------------------------


class OknoGlowne: public QMainWindow { //------------------------------
   Q_OBJECT
  public:
   OknoGlowne(QWidget *wRodzic = 0L);
  public slots:
   void GdyNapis(const QString &);
}; //------------------------------------------------------------------

#endif
