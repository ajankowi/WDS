#include "MainWindow.hh"
#include "InfoWindow.hh"


MainWindow::MainWindow(QWidget *pParent): QMainWindow(pParent)
{
  setCentralWidget(new InfoWindow(this));
  setAttribute(Qt::WA_DeleteOnClose);
}

