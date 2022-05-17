#ifndef INFOWINDOW_HH
#define INFOWINDOW_HH

#include <QWidget>
#include "ui_InfoWindow.h"


class InfoWindow: public QWidget, public Ui::InfoWindow {
  public:
    InfoWindow(QWidget *pParent);
};

#endif
