#include <QApplication>
#include "MainWindow.hh"


int main(int argc, char **argv)
{
  QApplication  App(argc,argv);
  MainWindow   *pWnd = new MainWindow();

  pWnd->show();
  return App.exec();
}
