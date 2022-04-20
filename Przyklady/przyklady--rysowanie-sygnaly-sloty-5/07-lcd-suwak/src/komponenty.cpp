#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QMainWindow>
#include <QLCDNumber>


using namespace std;

/*================================================================
 * Przyklad demonstruje uzycie i polaczenie QLCDNumber i QSlider
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
  QLCDNumber  *wLCD = new QLCDNumber(2,this);
  wLCD->setGeometry(70,10,60,90);

  QSlider  *wSuwak = new QSlider(Qt::Horizontal,this);
  wSuwak->setGeometry(10,120,190,22);
  wSuwak->setMinimum(0);  
  wSuwak->setMaximum(99);

  connect(wSuwak,SIGNAL(valueChanged(int)),wLCD,SLOT(display(int)));
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
