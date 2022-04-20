#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QMainWindow>
#include <QProgressBar>


using namespace std;

/*=====================================================================
 * Przyklad demonstruje uzycie oraz polaczenie QProgressBar z QSlider
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
  wBelkaPost->setGeometry(10,80,190,20);
  wBelkaPost->setRange(0,99);

  QSlider  *wSuwak = new QSlider(Qt::Horizontal,this);
  wSuwak->setGeometry(10,120,190,22);
  wSuwak->setMinimum(0);  
  wSuwak->setMaximum(99);

  connect(wSuwak,SIGNAL(valueChanged(int)),wBelkaPost,SLOT(setValue(int)));
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
