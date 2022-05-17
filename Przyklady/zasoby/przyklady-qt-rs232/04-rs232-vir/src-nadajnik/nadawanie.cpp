#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <cstdlib>
#include "transparam.hh"

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




void TestNadawania(const char *sDevName)
{
  int    DeskPortu;
  
  if ((DeskPortu = open(sDevName,O_RDWR | O_NONBLOCK)) < 0) {
    cerr << ":( Blad otwarcia portu " << sDevName << endl;  
    exit(1);
  }

  SetTransParam(DeskPortu);

  int  Rezultat;

  while ((Rezultat = RS232_Nadaj(DeskPortu,"Czesc! To ja, nadajnik.\n")) >= 0) {
    usleep(1000000);
    cout << "Nadaje kolejne powitanie" << endl;
  }
  cout << "Koniec" << endl;
}



int main(int argc, char *argv[])
{
  if (argc < 2) {
    cout << endl
	 << " Wywolanie:" << endl
	 << "     " << *argv << " urzadzenie (np. /dev/pts/30)" << endl
	 << endl;
    return 1;
  }


  TestNadawania(argv[1]);
}
