#ifndef KANWA_HH
#define KANWA_HH

#include <QWidget>


class Kanwa: public QWidget {
  Q_OBJECT
 public:
  Kanwa(QWidget *wRodzic = nullptr);

 public slots:
  void GdyZamkniecie();

 signals:
  void ZglosZamkniecie();
};



#endif
