#ifndef OKNOGLOWNEAPLIKACJI_HPP
#define OKNOGLOWNEAPLIKACJI_HPP

#ifdef __GNUG__
# pragma interface
#endif


#include <QMainWindow>

#include "ui_oknoglowne.h"


class OknoGlowneAplikacji: public QMainWindow, public Ui::OknoGlowne {
   Q_OBJECT
  public:
   OknoGlowneAplikacji();
   virtual void changeEvent(QEvent *event) override;

  public slots:
   void on_action_Open_triggered(bool checked);  
   void on_action_Exit_triggered(bool checked);
   void on__wPrzycisk_Koniec_clicked();
   void on__wWyborJezyka_currentIndexChanged(int);
};

#endif
