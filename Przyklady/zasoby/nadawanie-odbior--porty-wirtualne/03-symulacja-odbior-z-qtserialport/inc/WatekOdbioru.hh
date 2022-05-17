#ifndef WATEKODBIORU_HH
#define WATEKODBIORU_HH

#ifdef __GNUG__
  #pragma interface
  #pragma implementation
#endif

#include <QThread>
#include <QSerialPort>
#include "BuforDanych.hh"





class Komunikacja {
     QSerialPort  *_wPort = nullptr;
     BuforDanych   _BufNap;
     bool          _Kontynuuj = true;
     std::string   _NazwaPortu;
  
   public:

     void UstawNazwePortu(const std::string &rNazwa) { _NazwaPortu = rNazwa; }
     void SkojarzObiektPortu(QSerialPort  *wPort) { _wPort = wPort; }

     bool OtworzPort(const char* sPortSzeregowy);
     bool OtworzPort() { return OtworzPort(_NazwaPortu.c_str()); }
  
     BuforDanych & UzyjBufNap() { return _BufNap; }
     const BuforDanych & WezBufNap() const { return _BufNap; }
     bool Kontynuuj() const { return _Kontynuuj; }
     void Zakoncz() { _Kontynuuj = false; }
  
     bool OdbierzJednaLinie();
     void OdbiorDanych();
};




class Watek: public QThread {
   Q_OBJECT
   Komunikacja  *_wKom = nullptr;

  public:
   Watek(Komunikacja *wKom) { _wKom = wKom; }
   void run() override; 
};





#endif
