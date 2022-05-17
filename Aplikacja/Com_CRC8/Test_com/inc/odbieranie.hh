#ifndef ODBIERANIE_HH_
#define ODBIERANIE_HH_


#include "odbieranie.hh"
#include "transparam.hh"

using namespace std;

/**@brief
* Funkcja sprawdza czy czy podany czas jest ponizej aktualnego
*
*@retval TRUE jezeli podany czas jest ponizej aktualnego
*@retval FALSE jezeli czas jest powyzej badz jest rowny
*
*/

bool Czas_JestPozniejNiz(const struct timespec& CzasX);


/**@brief
* Funkcja odczytuje pojedynczy znak wiadomosci oraz
* sprawdza czy nie zostal przekroczony czas wczytywania
*
*@retval TRUE Poprawnie wczytano znak
*
*/
bool RS232_Odbierz( int            DeskPortu,
                    string        &Bufor,
                    unsigned int   IloscZnakow
                    );

/**@brief
* Funkcja odczytuje liczbe znakow w  wiadomosci oraz
* sprawdza czy nie zostal przekroczony czas wczytywania
*
*@retval TRUE Liczba odebranych znakow wiadomosci jest wieksza od 1
*@retval FALSE Nie udalo sie odebrac wiadomosci, liczba znakow wynosi 0
*
*/
int RS232_Odbierz( int DeskPortu, char &BuforZnaku);

/**@brief
* Funkcja otwiera odpowiedni port komunikacyjny, wczytuje otrzymana
* wiadomosc oraz sprawdza sume kontrolna przeslanej wiadomosci.
*
*@retval 0 - Poprawnie odebrano wiadomosc
*@retval -1 - Blad podczas odbierania wiadomosci
*
*/
int Odbierz(int &str);


#endif /* INC_ODBIERANIE_HH_ */
