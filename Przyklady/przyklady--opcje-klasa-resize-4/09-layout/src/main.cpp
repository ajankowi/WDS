#include <QApplication>
#include "GlowneOkno.hh"


int main( int argc, char * argv[] ) 
{
 QApplication App(argc,argv);
 GlowneOkno   Ok;

 Ok.show();

 return App.exec();
}
