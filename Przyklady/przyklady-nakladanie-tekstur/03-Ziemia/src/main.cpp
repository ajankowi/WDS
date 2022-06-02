#include <QApplication>
#include "Viewer.hh"
#include "GxControlPanel.hh"
#include "GxMainWindow.hh"



int main(int argc, char** argv)
{
  // Read command lines arguments.
  QApplication application(argc,argv);
  GxMainWindow  MWin;

  MWin.Initialize();
  MWin.show();
  return application.exec();
}
