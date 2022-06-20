#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <cstdlib>
#include "rs232_h/transparam.hh"
#include "rs232_h/CRC8.hh"

#define ROZMIAR_LINII   100


using namespace std;



/*!
 *
 */
bool RS232_Nadaj( int          DeskPortu,
                  const char*  wNapis
		)
{
  int  Ilosc_DoNadania = strlen(wNapis);
  int  Ilosc_Nadana;

  while (Ilosc_DoNadania > 0) {
    if (!(Ilosc_Nadana = write(DeskPortu,wNapis,Ilosc_DoNadania))) { 
      usleep(20); continue; 
    }
    if (Ilosc_Nadana < 0) { 
      cerr << ":( Blad nadawania\n";  
      return false;
    }
    Ilosc_DoNadania -= Ilosc_Nadana;  
    wNapis += Ilosc_Nadana; 
  }
  return true;
}




void TestNadawania(const char*  wNapis)
{
  int    DeskPortu;
  
  if ((DeskPortu = open("/dev/ttyUSB0",O_RDWR | O_NONBLOCK)) < 0) {
    cerr << ":( Blad otwarcia portu USB0" << endl;  

  }

  //SetTransParam(DeskPortu);

  int  Rezultat;

  if ((Rezultat = RS232_Nadaj(DeskPortu, wNapis)) >= 0) {

    //cout << wNapis << endl;
  }else{
        cout << "Nie udalo sie wyslac wiadomosci" << endl;
  }


}



//int main()
//{
//  TestNadawania();
//
