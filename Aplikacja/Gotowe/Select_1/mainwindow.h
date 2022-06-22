#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLineEdit>
#include <QIcon>
#include <QThread>
#include <QCloseEvent>
#include <unistd.h>
#include <QMessageBox>
#include <QString>
#include <QAbstractButton>
#include <QtCore>
#include <QTranslator>
#include "rs232_h/odbieranie.hh"
#include "rs232_h/transparam.hh"
#include "rs232_h/nadawanie.hh"
//#include <viewer.h>

#include <string>
#include <cstring>
#include <string>
#include <cassert>
#include <iomanip>
#include <bitset>
#include <sstream>

using namespace std;



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow;
class WatekOdbioru;
class WatekCom;


/**
 * @brief Klasa Punkt zapisuje współrzędne danego punktu
 */

class Punkt{

public:
    /**
     * Zapisuje współrzędne punktu
     * @brief Kostruktor
     * @param x - wartość współrzędnej na osi x
     * @param y - wartość współrzędnej na osi y
     * @param z - wartość współrzędnej na osi z
     * @see ustawPoloz(int x, int y, int z);
     */

    int x;
    int y;
    int z;

    /**
     * @brief Metoda kopiująca
     * @param[in] x,y,z - współrzędne punktu
     * @retval Wyświetla współrzędne punktu
     */

    void ustawPoloz(int x, int y, int z);
};


/**
 * @brief Klasa WatekPoloz sprawdza czy wybrany punkt został zmieniony
 */
class WatekPoloz : public QThread
{
    Q_OBJECT
public:

    /**
     * @brief Inicjalizacja wątku
     */
    explicit WatekPoloz(QObject *parent = nullptr);
    /**
     * @brief Uruchamia pracę wątku
     * @param[in] x,y,z - współrzędne punktu
     * @param[out] x,y,z - współrzędne nowego punktu
     * @retval Zmienia współrzędne punktu w momencie gdy użytkownik wybierze inny punkt
     */
    void run();
    /**
     * @brief Zmienna _Start umożliwia zabicie wątku
     * @brief True - wątek żyje
     * @brief False - wątek zostaje zabity
     */
    bool _Start;

signals:
    /**
     * @brief Metoda Poloz służy do połączenia z metodą onPoluz w klasie MainWindow
     * @param[out] x,y,z - współrzędne punktu
     */
    void Poloz(int, int, int);

};



/**
 * @brief Klasa WatekCom służy do sprawdzania połączenia między procesoerm a aplikacją
 */
class WatekCom : public QThread
{
    Q_OBJECT
public:
    /**
     * @brief Inicjalizacja wątku
     */
    explicit WatekCom(QObject *parent = nullptr);
    /**
     * @brief Uruchamia pracę wątku
     * @param[out] True - jeżeli urządzenia są połączone
     * @param[out] False - jeżeli urządzenia nie są połączone
     * @retval Wątek regularnie sprawdza połączenie pomiędzy urządzeniami
     */
    void run();
    /**
     * @brief Zmienna _Start umożliwia zabicie wątku
     */
    bool _Start;

    /**
     * @brief Zmienia wartość logiczną zmiennej _Sprawdz
     * @param[in] Zmienna _SPpawdz
     * @param[out] Wartość zmiennej wejściowej
     * @retval Umożliwia zmianę stanu logicznego dla zmiennej _Sprawdz
     */
    void zmien(bool);
signals:
    /**
     * @brief Służy do komunikacji z metodą klasy MainWindow onNumberChar()
     * @param[in] Zmienna logiczna kalib, która odpowiada za kalibrację skanera
     */
    void NumberCh(bool);
    /**
     * @brief Służy do komunikacji z metodą klasy MainWindow onStatus()
     * @param[in] Zmienna logiczna _Status
     */
    void Status(bool);
    /**
     * @brief Służy do komunikacji z metodą klasy MainWindow onKoniec()
     * @param[in] Zmienna logiczna _Status
     */
    void Koniec(bool);
};






/**
 * @brief Klasa WatekOdbioru służy do odbierania danych przesłanych z procesora
 */

class WatekOdbioru : public QThread
{
    Q_OBJECT

public:
    /**
     * @brief Inicjalizacja wątku
     */
    explicit WatekOdbioru(QObject *parent = nullptr);
    /**
     * @brief Uruchamia pracę wątku
     * @param[out] x - wartość współrzędnej na osi x
     * @param[out] y - wartość współrzędnej na osi y
     * @param[out] z - wartość współrzędnej na osi z
     * @retval Wątek regularnie odbiera dane przesyłane z procesora
     */
    void run();
    /**
     * @brief Zmienna _Start umożliwia zabicie wątku
     */
    bool _Start;
    /**
     * @brief Zmienia wartość logiczną zmiennej _Sprawdz
     * @param[in] Zmienna _Sprawdz
     * @param[out] Wartość zmiennej wejściowej
     * @retval Umożliwia zmianę stanu logicznego dla zmiennej _Sprawdz
     */
    void zmien(bool);
    /**
     * @brief Metoda zakończająca pracę watku
     * @param[in] Zmienna _Start
     * @param[out] Wartość zmiennej wejściowej
     * @retval Umożliwia zmianę stanu logicznego dla zmiennej _Start
     */
    void zakoncz(bool);

signals:
    /**
     * @brief Służy do komunikacji z metodą klasy Viewer onWspolrz()
     * @param[in] Zmienna logiczna bool
     */
    void Wspolrz(float,float,float);


public slots:

};







/**
 * @brief Klasa MainWindow służy do stworzenia okna aplikacji
 */


class MainWindow : public QMainWindow
{
    Q_OBJECT

    WatekCom *mCom;
    WatekPoloz *mPoloz;


public:
    /**
     * @brief Inicjalizacja głównego okna
     */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    /**
     * @brief Służy do komunikacji z metodą klasy WatekCom NumberCh()
     * @param[in] Zmienna logiczna _Status
     * @retval Wyświetla komunikat o kalibracji użytkownikowi
     */
    void onNumberCh(bool);
    /**
     * @brief Służy do komunikacji z metodą klasy WatekCom Status()
     * @param[in] Zmienna logiczna _Status
     * @retval Zmienia kolor diody w zaleznosci czy urzadzenie jest podlaczone
     */
    void onStatus(bool);
    /**
     * @brief Służy do komunikacji z metodą klasy Watekcom Koniec()
     * @param[in] Zmienna logiczna _Koniec
     * @retval Wyświetla komunikat o zakończeniu skanowania
     */
    void onKoniec(bool);
    /**
     * @brief Służy do komunikacji z metodą klasy WatekPoloz Poloz()
     * @param[in] x, y, z - współrzędne punktu
     * @retval Metoda wyświetla dostarczone współrzędne w aplikacji
     */
    void onPoloz(int x, int y, int z);

private slots:
    /**
     * @brief Obsługuje opcje związne z przyciskiem ustaw
     */
    void on_pushButton_ustaw_clicked();
    /**
     * @brief Obsługuje opcje związne z przyciskiem stop
     */
    void on_pushButton_stop_clicked();
    /**
     * @brief Obsługuje opcje związne z przyciskiem start
     */
    void on_pushButton_start_clicked();

private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
