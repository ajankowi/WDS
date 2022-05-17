#ifndef WATEKODBIORU_HH
#define WATEKODBIORU_HH


#include "BuforDanych.hh"


class Komunikacja {
     int           _DeskPortu = -1;
     BuforDanych   _BufNap;
     bool          _Kontynuuj = true;
   private:
    int WezDeskPortu() const { return _DeskPortu; }
  
   public:
     bool OtworzPort(const char* sPortSzeregowy);
     bool OdbierzDane();

     BuforDanych & UzyjBufNap() { return _BufNap; }
     const BuforDanych & WezBufNap() const { return _BufNap; }
     bool Kontynuuj() const { return _Kontynuuj; }
     void Zakoncz() { _Kontynuuj = false; }
};




void WatekOdbioru( Komunikacja *pLaczeKom );



#endif
