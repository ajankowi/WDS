#include "InfoWindow.hh"
#include <cassert>


InfoWindow::InfoWindow(QWidget *pParent): QWidget(pParent)
{
  setupUi(this);

  assert(pParent != nullptr);
  connect(_wPrzycisk_Zamknij,SIGNAL(clicked()),pParent,SLOT(close()));
}
