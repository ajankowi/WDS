#ifndef PROSTEOKNO_HH
#define PROSTEOKNO_HH

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QResizeEvent>


class ProsteOkno: public QWidget {

   QLabel      *_wEtyk;
   QPushButton *_wPrzycisk;  

  public:
   ProsteOkno(QWidget *wRodzic = nullptr);
   ~ProsteOkno();
};


#endif
