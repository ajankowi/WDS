#ifndef CLIPPINGPLANE_HH
#define CLIPPINGPLANE_HH

#include <QGLViewer/qglviewer.h>

class Viewer : public QGLViewer
{
protected :
  virtual void draw();
  virtual void init();
  virtual QString helpString() const;
};

#endif
