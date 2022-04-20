#include <iostream>
#include "program.hh"

using namespace std;

/*===========================================================
 * Przyklad demonstruje tworzenie wlasnego sygnalu i slotu
 * bez GUI.
 */



void BardzoProstaKlasa_z_Qt::wstawWartosc(int NowaWartosc)
{
  if (_Wartosc != NowaWartosc) {
    _Wartosc = NowaWartosc;
    emit zmianaWartosci(_Wartosc);
  }
}



int main() 
{
  BardzoProstaKlasa_z_Qt  Obiekt_A, Obiekt_B;

  QObject::connect(&Obiekt_A,SIGNAL(zmianaWartosci(int)),
                   &Obiekt_B,SLOT(wstawWartosc(int)));

  Obiekt_B.wstawWartosc(11);
  Obiekt_A.wstawWartosc(79);

  cout << Obiekt_B.pobierzWartosc() << endl;

  Obiekt_B.wstawWartosc(11);

  cout << Obiekt_A.pobierzWartosc() << endl;
}
