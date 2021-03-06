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
#include "odbieranie.hh"
#include "transparam.hh"
#include "CRC8.hh"

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


/*!
 *
 */
bool RS232_Odbierz( int            DeskPortu, 
                    string        &Bufor, 
                    unsigned int   IloscZnakow
                  )
{
  Bufor.clear();
  Bufor.reserve(IloscZnakow);

  struct timespec  Czas_Koniec;
  
  unsigned int CzasOczekiwania_ms = 2000;

  clock_gettime(CLOCK_REALTIME,&Czas_Koniec);
  Czas_Koniec.tv_sec += CzasOczekiwania_ms/1000;
  Czas_Koniec.tv_nsec += static_cast<long int>((CzasOczekiwania_ms % 1000)*1000000);

  do {
     
  } while (true);  
  return true;
}




int RS232_Odbierz( int            DeskPortu, 
                   char          &BuforZnaku
                 )
{

  struct timespec  Czas_Koniec;
  
  unsigned int CzasOczekiwania_ms = 2000;

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



int Odbierz(int &sig)
{


  int DeskPortu;
  int AccX;
  char  FHeader;
  unsigned int CRC8;



  if ((DeskPortu = open("/dev/ttyUSB0",O_RDWR | O_NONBLOCK)) < 0) {
    cerr << ":( Blad otwarcia portu /dev/ttyUSB0" << endl;
    exit(1);
  }
  SetTransParam(DeskPortu);

  char Znak;
  int  Rezultat = 0;
  int flaga = 1;
  int i = 0;
  char tab[100];
  string a;

  while (((Rezultat = RS232_Odbierz(DeskPortu,Znak)) > 0)&&(flaga)) {
	  if(Znak != 64){
		  tab[i] = Znak;

      	  i++;
	  }
	  else{
		  flaga = 0;
	  }

  }
  //string mystr(tab);



  std::istringstream IStrm(tab);

  i = strlen(tab);

  tab[i-1] = '\0';

  //cout << tab << endl;

  IStrm >> FHeader >> AccX >> hex >> CRC8;

  if (IStrm.fail() || FHeader != 'X' ) return -1;



  if (ParseDataFrame(tab,AccX)) {
      sig = AccX;
  } else {
      cout << endl << ":(  Ramka jest niepoprawna." << endl << endl;
      return -1;
  }


  return 0;

}






