#ifndef RYSOWANIE_HH
#define RYSOWANIE_HH

#include <QWidget>
#include <QMainWindow>
#include <QLabel>

class OknoZRysunkiem: public QWidget {
  Q_OBJECT   // Gdy wprowadzamy sygnal tez musi byc Q_OBJECT
 public:
  OknoZRysunkiem(QWidget *wRodzic = nullptr);

  void paintEvent( QPaintEvent * event );
  static int Numer() { return _Numer;}

 signals:
  void OglosRysowanie();

 private:
  static int _Numer;
};


class Kanwa: public QWidget {
  Q_OBJECT
 public:
  Kanwa(QWidget *wRodzic = nullptr);
 public slots:
  void GdyRysuj();
 private:
  QLabel *_wNapis;
};



class OknoGlowne: public QMainWindow {
 public:
  OknoGlowne(QWidget *wRodzic = nullptr);
};

#endif
