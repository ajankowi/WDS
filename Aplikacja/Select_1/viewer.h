#ifndef ANIMATION_H
#define ANIMATION_H

#include <QGLViewer/qglviewer.h>
#include "mainwindow.h"

class Viewer;

class Particle {
public:
  Particle();

  void init();
  void draw(bool special);

  qglviewer::Vec pos_;

private:
  qglviewer::Vec speed_;
  int age_, ageMax_;
};










class Viewer : public QGLViewer {

    WatekOdbioru *mOdbior;

    //MainWindow *te;

public:
  Viewer(QWidget *parent);

protected:
  virtual void draw();
  virtual void init();
  virtual void drawWithNames();
  virtual void postSelection(const QPoint &point);
  virtual QString helpString() const;

private:
  int nbPart_;
  Particle *particle_;
  Punkt *point_;
  qglviewer::Vec selectedPoint, dir, orig;



public slots:
    void onWspolrz(float,float,float);

};



#endif // ANIMATION_H
