#ifndef CAMERALIGHT_HH
#define CAMERALIGHT_HH

#include <QGLViewer/qglviewer.h>

class Viewer : public QGLViewer
{
 protected :
  virtual void draw();
  virtual void init();
  virtual QString helpString() const;

 private :
  virtual void drawSpiral();
};


#endif
