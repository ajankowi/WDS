#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QMainWindow>
#include <QSpinBox>


using namespace std;

/*==================================================================
 * Przyklad demonstruje u¿ycie i po³±czenie QSpinBox i QSlider
 */



class Kanwa: public QWidget {
 public:
  Kanwa(QWidget *wRodzic = nullptr);
};



class OknoGlowne: public QMainWindow {
 public:
  OknoGlowne(QWidget *wRodzic = nullptr);
};



//============================================================
//................ Kanwa .....................................

Kanwa::Kanwa(QWidget *wRodzic):  QWidget(wRodzic)
{
  QSpinBox  *wOkLicz = new QSpinBox(this);
  wOkLicz->setGeometry(80,60,110,30);
  wOkLicz->setRange(0,99);
  wOkLicz->setSuffix(tr(" mm"));
  wOkLicz->setSpecialValueText(tr("domyslna"));

  QSlider  *wSuwak = new QSlider(Qt::Horizontal,this);
  wSuwak->setGeometry(10,120,190,22);
  wSuwak->setMinimum(0);  
  wSuwak->setMaximum(99);

  connect(wSuwak,SIGNAL(valueChanged(int)),wOkLicz,SLOT(setValue(int)));
  connect(wOkLicz,SIGNAL(valueChanged(int)),wSuwak,SLOT(setValue(int)));
}


//................ Kanwa .....................................
//============================================================


//============================================================
//................ OknoGlowne ................................


OknoGlowne::OknoGlowne(QWidget *wRodzic): QMainWindow(wRodzic)
{
  Kanwa *wOknoKw = new Kanwa(this);
  resize(220,180);
  setCentralWidget(wOknoKw);
}

//................ OknoGlowne ................................
//============================================================




int main( int argc, char * argv[] ) 
{
  QApplication App(argc,argv);
  OknoGlowne   Okno;

  Okno.show();

  return App.exec();
}
