#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <time.h>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <errno.h>
#include "transparam.hh"

#define ROZMIAR_LINII   100


using namespace std;




/*!
 *
 */
bool Czas_JestPozniejNiz(const struct timespec& CzasX)
{
  struct timespec  Czas_Aktualny;

  clock_gettime(CLOCK_REALTIME,&Czas_Aktualny);
  return Czas_Aktualny.tv_sec > CzasX.tv_sec ||
        (Czas_Aktualny.tv_sec == CzasX.tv_sec &&
         Czas_Aktualny.tv_nsec > CzasX.tv_nsec) ;
}





int RS232_Odbierz( int            DeskPortu, 
                   char          &BuforZnaku, 
                   unsigned int   CzasOczekiwania_ms = 2000
                 )
{

  struct timespec  Czas_Koniec;
  
  clock_gettime(CLOCK_REALTIME,&Czas_Koniec);
  Czas_Koniec.tv_sec += CzasOczekiwania_ms/1000;
  Czas_Koniec.tv_nsec += static_cast<long int>((CzasOczekiwania_ms % 1000)*1000000);
  int   Ilosc_Odb;

  while ((Ilosc_Odb = read(DeskPortu,&BuforZnaku,1)),
	 Ilosc_Odb == 0 || (Ilosc_Odb < 0 && errno == EAGAIN)) {
      if (Czas_JestPozniejNiz(Czas_Koniec)) return 0;
      usleep(10);
  };  

  return Ilosc_Odb > 0 ? 1 : -1;
}




/*!
 *
 */
bool RS232_Odbierz( int            DeskPortu, 
                    string        &Bufor, 
                    unsigned int   IloscZnakow,
                    unsigned int   CzasOczekiwania_ms
                  )
{
  Bufor.clear();
  Bufor.reserve(IloscZnakow);

  struct timespec  Czas_Koniec;
  
  clock_gettime(CLOCK_REALTIME,&Czas_Koniec);
  Czas_Koniec.tv_sec += CzasOczekiwania_ms/1000;
  Czas_Koniec.tv_nsec += static_cast<long int>((CzasOczekiwania_ms % 1000)*1000000);

  char Odebrany_Znak;
  int flaga = 1;


  do {
    if (RS232_Odbierz(DeskPortu,Odebrany_Znak,50) <= 0) return false;
    if (Czas_JestPozniejNiz(Czas_Koniec)) return false;
    if (Odebrany_Znak == '\n') flaga = 0;       //return true;
    if(flaga){
      Bufor += Odebrany_Znak;
      --IloscZnakow;
    }
  } while ((IloscZnakow > 0) && flaga);  
                                   //return true;




  if (Bufor[1] != 'X' ){
     cout << "Zla ramka" << endl;
     return false;
  } 
  return true;

}


void TestOdbioru( )
{
  int    DeskPortu;
  
  if ((DeskPortu = open("/dev/ttyUSB0",O_RDWR | O_NONBLOCK)) < 0) {
    cerr << ":( Blad otwarcia portu USB0" << endl;  
    exit(1);
  }
  SetTransParam(DeskPortu);


  char Znak;
  int  Rezultat = 0;

  while ((Rezultat = RS232_Odbierz(DeskPortu,Znak)) >= 0) {
    if (Rezultat > 0) {
      cout << Znak << flush;
      continue;
    }
    cout << endl << endl
	 << ":( Przekroczony czas oczekiwania" << endl
	 << endl;
  }
  cout << "Koniec" << endl;
}



