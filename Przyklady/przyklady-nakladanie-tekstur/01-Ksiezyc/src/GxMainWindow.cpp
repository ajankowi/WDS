#include "GxMainWindow.hh"


GxMainWindow::GxMainWindow(QWidget *pParent): QMainWindow(pParent)
{
  setupUi(this);
  _pWidget_CtrPanel->SetViewerWidget(_pWidget_Viewer);
}


void GxMainWindow::Initialize()
{
  _pWidget_CtrPanel->Initialize();
}
