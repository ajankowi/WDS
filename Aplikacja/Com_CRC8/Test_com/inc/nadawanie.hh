#ifndef NADAWANIE_HH
#define NADAWANIE_HH


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <cstdlib>


/**@brief
* Funkcja wysyla wiadomosc znak po znaku oraz sprawdza czy liczba
* znakow wyslanych jest taka sama jak liczba znakow do wyslania
*
*@retval TRUE Udalo sie wyslac wszystkie znaki poprawnie
*@retval FALSE Nie udalo sie wyslac wszystkich znakow
*
*/
bool RS232_Nadaj( int DeskPortu, const char*  wNapis);


/**@brief
* Funkcja laczy sie z odpowiednim portem komunikacyjnym, nastepnie
* tworzona jest odpowiednia ramka danych zawierajaca sume kontrolna
* oraz zostaje
*
*@retval 1 Wiadomosc zostala poprawnie wyslana
*@retval 0 Nie udalo sie poprawnie wyslac wiadomosci
*
*/
int Nadaj(const int sig);


#endif
