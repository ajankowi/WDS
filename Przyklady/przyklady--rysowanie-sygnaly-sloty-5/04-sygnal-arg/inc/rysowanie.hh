#ifndef RYSOWANIE_HH
#define RYSOWANIE_HH

#include <QWidget>
#include <QMainWindow>
#include <QLabel>

/*===========================================================
 * Przyklad demonstruje tworzenie wlasnego sygnalu, ktory
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
 public slots:
  void OdbierzNapisGdyRysuj(const QString &);
 private:
  QLabel *_wNapis;
};



class OknoGlowne: public QMainWindow {
 public:
  OknoGlowne(QWidget *wRodzic = nullptr);
};

#endif
