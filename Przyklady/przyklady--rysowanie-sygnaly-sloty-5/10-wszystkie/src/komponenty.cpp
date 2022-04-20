#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QMainWindow>
#include <QSpinBox>
#include <QProgressBar>
#include <QLCDNumber>


using namespace std;

/*=================================================================
 * Przyklad demonstruje uzycie oraz polaczenia  realizowane
 * dla obiektow klasy QLCDNumber, QProgressBar, QSpinBox i QSlider
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
  QProgressBar  *wBelkaPost = new QProgressBar(this);
  wBelkaPost->setGeometry(10,120,190,20);
  wBelkaPost->setRange(0,99);


  QSpinBox  *wOkLicz = new QSpinBox(this);
  wOkLicz->setGeometry(115,10,100,30);
  wOkLicz->setRange(0,99);
  wOkLicz->setSuffix(tr(" mm"));
  wOkLicz->setSpecialValueText(tr("domyslna"));

  QSlider  *wSuwak = new QSlider(Qt::Horizontal,this);
  wSuwak->setGeometry(10,140,190,22);
  wSuwak->setMinimum(0);  
  wSuwak->setMaximum(99);

  QLCDNumber  *wLCD = new QLCDNumber(2,this);
  wLCD->setGeometry(10,10,60,90);

  connect(wSuwak,SIGNAL(valueChanged(int)),wOkLicz,SLOT(setValue(int)));
  connect(wSuwak,SIGNAL(valueChanged(int)),wBelkaPost,SLOT(setValue(int)));
  connect(wSuwak,SIGNAL(valueChanged(int)),wLCD,SLOT(display(int)));
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
