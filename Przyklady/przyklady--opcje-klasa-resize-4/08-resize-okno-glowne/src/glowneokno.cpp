

#include <QStatusBar>
#include <iostream>
#include "ProsteOkno.hh"
#include "GlowneOkno.hh"

using namespace std;





GlowneOkno::GlowneOkno(QWidget *wRodzic): QMainWindow(wRodzic)
{
 setCentralWidget(new ProsteOkno());
 setStatusBar(new QStatusBar());
 statusBar()->showMessage(QObject::tr("Start aplikacji"));
 resize(330,120);
}
