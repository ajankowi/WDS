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
#include <QThread>
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

class Punkt{

public:
    int x;
    int y;
    int z;

    void ustawPoloz(int x, int y, int z);
};


class WatekPoloz : public QThread
{
    Q_OBJECT
public:
    explicit WatekPoloz(QObject *parent = nullptr);
    void run();
    bool _Start;

signals:
    void Poloz(int, int, int);

};



class WatekCom : public QThread
{
    Q_OBJECT
public:
    explicit WatekCom(QObject *parent = nullptr);
    void run();
    bool _Start;
    void zmien(bool);
signals:
    void NumberCh(bool);
    void Status(bool);
    void Koniec(bool);
};








class WatekOdbioru : public QThread
{
    Q_OBJECT


public:
    explicit WatekOdbioru(QObject *parent = nullptr);
    void run();
    bool _Start;
    void zmien(bool);
    void zakoncz(bool);

signals:
    void Wspolrz(float,float,float);


public slots:

};














class MainWindow : public QMainWindow
{
    Q_OBJECT
    //WatekOdbioru *mWatek;
    WatekCom *mCom;
    WatekPoloz *mPoloz;
    //Viewer *mViewer;



public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();


public slots:
    void onNumberCh(bool);
    void onStatus(bool);
    void onKoniec(bool);
    void onPoloz(int x, int y, int z);

private slots:
    void on_pushButton_ustaw_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_start_clicked();

private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
