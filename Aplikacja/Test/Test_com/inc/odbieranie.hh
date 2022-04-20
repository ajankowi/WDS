#ifndef ODBIERANIE_HH_
#define ODBIERANIE_HH_


#include "odbieranie.hh"
#include "transparam.hh"

using namespace std;

bool Czas_JestPozniejNiz(const struct timespec& CzasX);
bool RS232_Odbierz( int            DeskPortu,
                    string        &Bufor,
                    unsigned int   IloscZnakow
                    );
int RS232_Odbierz( int DeskPortu, char &BuforZnaku);
int Odbierz(int &str);


#endif /* INC_ODBIERANIE_HH_ */
