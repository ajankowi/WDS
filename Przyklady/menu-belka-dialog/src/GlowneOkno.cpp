#include "GlowneOkno.hh"
#include "DialogPolaczenia.hh"
#include <iostream>

using namespace std;


GlowneOkno::GlowneOkno()
{
  setupUi(this);
}


void GlowneOkno::on__pAction_Quit_triggered()
{
  close(); 
}


void GlowneOkno::on__pAction_Connection_triggered()
{
  cout << "Connection" << endl;
  GlownyPanel *wPanel = static_cast<GlownyPanel*>(centralWidget());
  
  (new DialogPolaczenia(wPanel->_pDisplay_PortName,statusBar()))->show();
}
