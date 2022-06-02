#ifndef DRAWLIGHT_HH
#define DRAWLIGHT_HH


#include <QGLViewer/qglviewer.h>


class Viewer : public QGLViewer
{
 protected :
  virtual void draw();
  virtual void init();
  virtual QString helpString() const;

 private:
  qglviewer::ManipulatedFrame* light1;
  qglviewer::ManipulatedFrame* light2;
};


#endif
