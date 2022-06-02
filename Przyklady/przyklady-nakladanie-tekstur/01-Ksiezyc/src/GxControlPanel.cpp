#include <cassert>
#include "GxControlPanel.hh"


GxControlPanel::GxControlPanel(QWidget *pParent): QWidget(pParent),
						  _pViewerWidget(nullptr)
{
  setupUi(this);
}



void GxControlPanel::Initialize()
{
  _pSliderX->setValue(5);
  _pSliderY->setValue(10);
}


void GxControlPanel::SetViewerWidget(QWidget *pViewer)
{
  _pViewerWidget = pViewer;
}



void GxControlPanel::on__pSliderKat_valueChanged(int Val_deg)
{
  ScnParams.SetAngleX_deg(Val_deg);
  assert(_pViewerWidget);
  _pViewerWidget->update();
}




void GxControlPanel::on__pSliderX_valueChanged(int Val_deg)
{
  ScnParams.SetX_Light_deg(Val_deg);
  assert(_pViewerWidget);
  _pViewerWidget->update();
}



void GxControlPanel::on__pSliderY_valueChanged(int Val_deg)
{
  ScnParams.SetY_Light_deg(Val_deg);
  assert(_pViewerWidget);
  _pViewerWidget->update();
}



void GxControlPanel::on__pSliderZ_valueChanged(int Val_deg)
{
  ScnParams.SetZ_Light_deg(Val_deg);
  assert(_pViewerWidget);
  _pViewerWidget->update();
}
