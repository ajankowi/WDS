#ifndef GLOWNYPANEL_HH
#define GLOWNYPANEL_HH

#include <QWidget>
#include "ui_DGlownyPanel.h"


class GlownyPanel: public QWidget, public Ui::DGlownyPanel {
  public:
  GlownyPanel(QWidget *wRodzic);
};


#endif
