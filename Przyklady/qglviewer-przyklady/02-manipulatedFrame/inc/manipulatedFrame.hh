#ifndef MANIPULATEDFRAME_HH
#define MANIPULATEDFRAME_HH

#include <QGLViewer/qglviewer.h>

class Viewer : public QGLViewer
{
 protected :
  virtual void draw();
  virtual void init();
  virtual QString helpString() const;
};
#endif
