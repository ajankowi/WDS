#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstdio>
#include <iostream>
#include <cassert>

#ifdef __GNUG__
  #pragma interface
  #pragma implementation
#endif



#include "WatekOdbioru.hh"
#include "transparam.hh"
#include "odbieranie.hh"


using namespace std;



bool Komunikacja::OtworzPort(const char* sPortSzeregowy)
{
  _wPort = new QSerialPort(); 
  _wPort->setBaudRate(QSerialPort::Baud115200);
  _wPort->setFlowControl(QSerialPort::NoFlowControl);
  _wPort->setStopBits(QSerialPort::OneStop);
  _wPort->setDataBits(QSerialPort::Data8);
  _wPort->setParity(QSerialPort::NoParity);
  _wPort->setPortName(sPortSzeregowy);

  if (!_wPort->open(QSerialPort::ReadOnly)) {
    cerr << ":( Blad otwarcia portu " << sPortSzeregowy << endl;  
    return false;
  }
  return true;
}



bool Komunikacja::OdbierzJednaLinie()
{
#define  ROZ_LINII 200
  char Linia[ROZ_LINII+1];
  qint64  IloscOdebranych;

  IloscOdebranych  = _wPort->readLine(Linia, ROZ_LINII); // Czeka az bedzie pelna linia.


  if (IloscOdebranych == 0 && !_wPort->waitForReadyRead()) return false;
  
  if (IloscOdebranych > 0) {
    if (Linia[strlen(Linia)-1] == '\n') {
	   Linia[strlen(Linia)-1] = 0;
    }
    _BufNap.DodajNapis(Linia);
  }
  return true;
}




void Komunikacja::OdbiorDanych()
{
  while (Kontynuuj()) {
    if (!OdbierzJednaLinie()) return;
  }
}



void Watek::run()
{
  QSerialPort   Serial;

  _wKom->SkojarzObiektPortu(&Serial);
  if (!_wKom->OtworzPort()) {
     cerr << ":( Operacja otwarcia portu nie powiodla sie." << endl;
     cerr << ":( Watek odbioru zakonczony." << endl;
     return;
  }

  cout << "Start watku" << endl;
  _wKom->OdbiorDanych();
  Serial.close();
  cout << "Koniec watku" << endl;
}




