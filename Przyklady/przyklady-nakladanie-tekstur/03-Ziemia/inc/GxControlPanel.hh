#ifndef GXCONTROLPANEL_HH
#define GXCONTROLPANEL_HH

#include "ui_DxControlPanel.h"
#include <QWidget>
#include "SceneParams.hh"


class GxControlPanel: public QWidget, public Ui::DxControlPanel {
   Q_OBJECT
   QWidget  *_pViewerWidget;
  public:
   GxControlPanel(QWidget *pParent = nullptr);

   void SetViewerWidget(QWidget *pViewer);

   void Initialize();
					 
  public slots:
   void on__pSliderKat_valueChanged(int);

   void on__pSliderX_valueChanged(int);
   void on__pSliderY_valueChanged(int);
   void on__pSliderZ_valueChanged(int);
};



#endif
