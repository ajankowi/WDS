#ifndef FASTDRAW_HH
#define FASTDRAW_HH


#include <QGLViewer/qglviewer.h>

class Viewer : public QGLViewer
{
protected:
  virtual void init();
  virtual void draw();
  virtual void fastDraw();
  virtual QString helpString() const;
};


#endif
