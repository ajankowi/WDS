#ifndef RYSOWANIE_HH
#define RYSOWANIE_HH

#include <QWidget>
#include <QMainWindow>
#include <QLabel>

/*===========================================================
 * Przyklad demonstruje laczenie sygnalu z sygnalem, ktory
 * przekazuje argument.
 */


class OknoZRysunkiem: public QWidget {
  Q_OBJECT   // Gdy wprowadzamy sygnal tez musi byc Q_OBJECT
 public:
  OknoZRysunkiem(QWidget *wRodzic = nullptr);

  void paintEvent( QPaintEvent * event );
  static int Numer() { return _Numer;}

 signals:
  void ZglosNapisGdyRysowanie(const QString &);

 private:
  static int _Numer;
};


class Kanwa: public QWidget {
  Q_OBJECT
 public:
  Kanwa(QWidget *wRodzic = nullptr);
 signals:
  void ZglosNapis(const QString &);
};



class OknoGlowne: public QMainWindow {
  Q_OBJECT
 public:
  OknoGlowne(QWidget *wRodzic = nullptr);
 public slots:
  void OdbierzNapisStatusu(const QString &);  
};

#endif
