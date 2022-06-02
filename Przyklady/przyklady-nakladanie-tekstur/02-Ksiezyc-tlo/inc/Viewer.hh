#ifndef VIEWER_HH
#define VIEWER_HH

#include <QGLViewer>
#include <QGLViewer/qglviewer.h>

class Viewer : public QGLViewer
{
 public:
  Viewer(QWidget *pParent = nullptr): QGLViewer(pParent) {}
 protected :
  virtual void draw();
  virtual void init();
  virtual QString helpString() const;
};
#endif
