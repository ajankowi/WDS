#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstdio>
#include <iostream>
#include "WatekOdbioru.hh"
#include "transparam.hh"
#include "odbieranie.hh"

using namespace std;


bool Komunikacja::OtworzPort(const char* sPortSzeregowy)
{
  if ((_DeskPortu = open(sPortSzeregowy,O_RDWR | O_NONBLOCK)) < 0) {
    cerr << ":( Blad otwarcia portu " << sPortSzeregowy << endl;  
    return false;
  }
  SetTransParam(_DeskPortu);
  return true;
}



bool Komunikacja::OdbierzDane()
{
  if (_DeskPortu < 0) {
    cerr << ":( Port szeregowy nie jest otwarty." << endl;
    return false;
  }

  string   Napis;
  if(RS232_Odbierz(WezDeskPortu(),Napis,1000,100)) {
    _BufNap.DodajNapis(Napis);
  }
  return true;
}





void WatekOdbioru( Komunikacja *pLaczeKom )
{
  while (pLaczeKom->Kontynuuj()) {
    if (!pLaczeKom->OdbierzDane()) return;
  }
}
