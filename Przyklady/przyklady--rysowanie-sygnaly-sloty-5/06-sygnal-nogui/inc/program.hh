#ifndef PROGRAM_HH
#define PROGRAM_HH
#include <QObject>


/*===========================================================
 * Przyklad demonstruje tworzenie wlasnego sygnalu i slotu
 * bez GUI.
 */


class BardzoProstaKlasa_z_Qt: public QObject {
  Q_OBJECT  
 public:
  BardzoProstaKlasa_z_Qt() { _Wartosc = 0; }

  int pobierzWartosc() const { return _Wartosc; }

 public slots:
  void wstawWartosc(int);

 signals:
  void zmianaWartosci(int);

 private:
  int _Wartosc;
};


#endif
