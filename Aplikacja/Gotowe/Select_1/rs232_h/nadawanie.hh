#ifndef NADAWANIE_H
#define NADAWANIE_H


/**@brief
* Funkcja wysyla wiadomosc znak po znaku oraz sprawdza czy liczba
* znakow wyslanych jest taka sama jak liczba znakow do wyslania
*
*@retval TRUE Udalo sie wyslac wszystkie znaki poprawnie
*@retval FALSE Nie udalo sie wyslac wszystkich znakow
*
*/
bool RS232_Nadaj( int          DeskPortu,
                  const char*  wNapis
        );


/**@brief
* Funkcja laczy sie z odpowiednim portem komunikacyjnym, nastepnie
* tworzona jest odpowiednia ramka danych zawierajaca sume kontrolna
* oraz zostaje
*
*@retval 1 Wiadomosc zostala poprawnie wyslana
*@retval 0 Nie udalo sie poprawnie wyslac wiadomosci
*
*/

void TestNadawania(const char*  wNapis);


#endif // NADAWANIE_H
