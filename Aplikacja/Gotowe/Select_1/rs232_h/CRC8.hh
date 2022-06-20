#ifndef INC_CRC8_HH_
#define INC_CRC8_HH_

#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <iomanip>
#include <bitset>
using namespace std;


//------------------------------------------------------------------
//  Przyk³ad implementacji obliczania sumy kontrolnej CRC8
//  oraz tworzenia ramki danych.
//


typedef unsigned char byte;
#define POLYNOMIAL_9 0x161


/**@brief
* Funkcja konwertuje pojedynczy bit
*
*@retval Odpowiedno przkonwertowany bit
*/
unsigned int CRC8_SingleByte( unsigned int Data2 );



/**@brief
* Funkcja oblicza odpowiednia wartosc sumy kontrolnej
* w zaleznosci od wiadomosci
*
*@retval Zwraca odpowiednia wartosc sumy kontrolnej
*/
byte CRC8_DataArray( const byte *pDataFrame, byte Len );



/**@brief
* Funkcja konwertuje rozmiar const char* na const bite*
*
*@retval Zwraca odpowiednia wartosc sumy kontrolnej
*/
byte CRC8_DataArray( const char *pDataFrame, byte Len );


/**@brief
* Funkcja sprawdza popranosc danej ramki danych w zaleznosci od
* przeslanej wiadomosci
*
*@retval TRUE Odebrana ramka danych jest poprawna
*@retval FALSE Blad danych wejsciowych lub blad w ramce danych
*/
bool ParseDataFrame( const char *pDataFrame, int &AccX);


/**@brief
* Funkcja konwertuje rozmiar string na const char* oraz uruchamia
* funckje ParseDataFrame( const char *pDataFrame, int &AccX)
*
*@retval TRUE Odebrana ramka danych jest poprawna
*@retval FALSE Blad danych wejsciowych lub blad w ramce danych
*/
bool ParseDataFrame( const std::string &rDataFrame, int &AccX);


/**@brief
* Funkcja tworzy odpowiednia ramke danych zawierajaca
* znak 'X' na poczatku, przesylana wiadomosc oraz sume kontrolna
*
*@retval Zwracany jest string zawierajacy ramke danych
*/
std::string CreateDataFrame( int AccX);


/**@brief
* Funkcja laczy i sprawdza poprawnosc dzialania tworzenia i odbierania
* wiadomosci z suma kontrolna
*
*@retval 0 poprawnie udalo sie wykonac funkcje
*/
int min();



#endif /* INC_CRC8_HH_ */
