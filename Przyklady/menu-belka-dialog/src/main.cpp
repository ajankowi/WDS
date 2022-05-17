#include <QApplication>
#include "GlowneOkno.hh"

int main(int argc, char** argv)
{
  QApplication  App(argc,argv);
  GlowneOkno    GOkno;

  GOkno.show();
  return App.exec();
}
