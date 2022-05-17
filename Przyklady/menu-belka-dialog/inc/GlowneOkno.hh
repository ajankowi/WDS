#ifndef GLOWNEOKNO_HH
#define GLOWNEOKNO_HH

#include <QMainWindow>
#include "ui_DGlowneOkno.h"

class GlowneOkno: public QMainWindow, public Ui::DGlowneOkno {
    Q_OBJECT
  public:
   GlowneOkno();

  public slots:
   void on__pAction_Quit_triggered();
   void on__pAction_Connection_triggered();
};

#endif
