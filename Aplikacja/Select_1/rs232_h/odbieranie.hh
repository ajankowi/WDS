#ifndef ODBIERANIE_HH
#define ODBIERANIE_HH


#include <string>


/**@brief
* Funkcja odczytuje liczbe znakow w  wiadomosci oraz
* sprawdza czy nie zostal przekroczony czas wczytywania
*
*@retval TRUE Liczba odebranych znakow wiadomosci jest wieksza od 1
*@retval FALSE Nie udalo sie odebrac wiadomosci, liczba znakow wynosi 0
*
*/
bool RS232_Odbierz( int            DeskPortu,
                    std::string   &Bufor,
                    unsigned int   IloscZnakow,
                    unsigned int   CzasOczekiwania_ms = 2000
          );


#endif
