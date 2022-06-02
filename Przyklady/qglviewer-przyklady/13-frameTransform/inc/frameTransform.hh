#ifndef FRAMETRANSFORM_HH
#define FRAMETRANSFORM_HH


#include <QGLViewer/qglviewer.h>

class Viewer : public QGLViewer
{
 protected :
  virtual void draw();
  virtual void init();
  virtual QString helpString() const;
};


#endif
