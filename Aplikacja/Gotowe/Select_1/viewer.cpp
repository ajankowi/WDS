#include "viewer.h"
#include <math.h>
#include <QTranslator>
#include <stdlib.h> // RAND_MAX
#include "mainwindow.h"

using namespace qglviewer;
using namespace std;




///////////////////////   V i e w e r  ///////////////////////

Viewer::Viewer(QWidget *parent) : QGLViewer(parent) {
  //restoreStateFromFile();
  //help();

    mOdbior = new WatekOdbioru(this);

    connect(mOdbior,&WatekOdbioru::Wspolrz,this,&Viewer::onWspolrz);

    mOdbior->start();

}




void Viewer::onWspolrz(float x, float y, float z){

    static int a = 2;
    a++;

    if((x == 144)&&(y == 144)&&(z == 144)){
        mOdbior->zakoncz(true);

        mOdbior->_Start = false;
    }else{
        particle_[a].pos_ = Vec(x/100, y/100, z/100);
        point_[a].x=x;
        point_[a].y=y;
        point_[a].z=z;

    }
}


void Viewer::init() {

  restoreStateFromFile();
  glDisable(GL_LIGHTING);
  nbPart_ = 10000;
  particle_ = new Particle[nbPart_];
  point_ = new Punkt[nbPart_];
  glPointSize(6.0);
  setGridIsDrawn();
  help();
  startAnimation();
}

void Viewer::draw() {


  glBegin(GL_POINTS);
  glColor3f(1.0, 1.0, 1.0);
  for (int i = 0; i < nbPart_; i++)
    particle_[i].draw(i == selectedName());
  //glVertex3fv(Vec(0.5,0.5,0.5));
  glEnd();


  //if (selectedName() >= 0) {
  //  glColor3f(0.9f, 0.2f, 0.1f);
  //  glBegin(GL_POINTS);
  //  glVertex3fv(selectedPoint);
  //  glEnd();
  //}


  // Draw the intersection line
  glBegin(GL_LINES);
  glVertex3fv(orig);
  glVertex3fv(orig + 100.0 * dir);
  glEnd();

}





void Viewer::drawWithNames() {

  for (int i = 0; i < nbPart_; i++){
      glPushName(i);
      glBegin(GL_POINTS);
      particle_[i].draw(i == selectedName());
      glEnd();
      glPopName();
  }

}



void Viewer::postSelection(const QPoint &point) {
  // Compute orig and dir, used to draw a representation of the intersecting
  // line
  camera()->convertClickToLine(point, orig, dir);

  // Find the selectedPoint coordinates, using camera()->pointUnderPixel().
  bool found;
  selectedPoint = camera()->pointUnderPixel(point, found);

  // Note that "found" is different from (selectedObjectId()>=0) because of the
  // size of the select region.

  if (selectedName() != -1){
      point_->ustawPoloz(point_[selectedName()].x,point_[selectedName()].y,point_[selectedName()].z);

  }
}







QString Viewer::helpString() const {
  QString text(tr("<h2>Skaner 3D</h2>"));
  text += tr("Parametry: <br><br>");

  text += tr("<b>N</b> - Oznacza liczbę pomiarów w ciągu jednego obrotu<br>");

  text += tr("<b>H</b> - Oznacza odległość między pomiarami na osi Z<br><br>");

  text += tr("W celu wybrania danego punktu należy przytrzymać przycisk  "
          "<i>Shift</i>.");
  return text;
}












///////////////////////   P a r t i c l e   ///////////////////////////////

Particle::Particle() {
    init();
}


void Particle::draw(bool special) {

  if (special)
   glColor3f(0.9f, 0.2f, 0.1f);
  else
     glColor3f(1.0, 1.0, 1.0);
  glVertex3fv(pos_);
}

void Particle::init() {
  pos_ = Vec(-10, -10, -10);
}
