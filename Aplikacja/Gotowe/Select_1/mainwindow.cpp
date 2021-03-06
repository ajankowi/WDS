#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLineEdit>
#include <QIcon>
#include <iostream>
#include "rs232_h/odbieranie.hh"
#include "rs232_h/transparam.hh"
#include "rs232_h/nadawanie.hh"
//#include "viewer.h"
#include <QThread>
#include <QCloseEvent>
#include <unistd.h>
#include <viewer.h>
#include <string>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <QTranslator>
#include <sstream>


volatile bool _Sprawdz;
volatile bool _Kalibracja;
volatile int co_robi;


int a;
int b;
int c;



void Punkt::ustawPoloz(int x, int y, int z){

    a = x;
    b = y;
    c = z;

   //cout << "x: " << a << "  y: " << b << "  z: " << c << endl;

}


WatekPoloz::WatekPoloz(QObject *parent)
    : QThread{parent}
{

}


void WatekPoloz::run(){

    _Start = true;

    int ao = 0;
    int bo = 0;
    int co = 0;

    while(_Start){
        if((ao != a)||(bo != b)||(co != c)){
            ao = a;
            bo = b;
            co = c;
            emit Poloz(a,b,c);
        }
         msleep(500);
    }
}


WatekCom::WatekCom(QObject *parent)
    : QThread{parent}
{

}

void WatekCom::run(){

    _Start = true;
    int DeskPortu;

    while(_Start){

        if ((DeskPortu = open("/dev/ttyUSB0",O_RDWR | O_NONBLOCK)) < 0) {
            zmien(false);
            emit Status(false);
        }
        else{

            zmien(true);
            emit Status(true);
        }

        if(_Kalibracja == true){
            _Kalibracja = false;
            emit NumberCh(true);
        }

        if(co_robi == 4){
            emit Koniec(true);
            co_robi = 5;
        }
        SetTransParam(DeskPortu);
        msleep(500);

    }
}

void WatekCom::zmien(bool Zmiana){
    _Sprawdz = Zmiana;
}














WatekOdbioru::WatekOdbioru(QObject *parent)
    : QThread{parent}
{

}


void WatekOdbioru::zmien(bool Zmiana){
    _Sprawdz = Zmiana;
}

void WatekOdbioru::zakoncz(bool Koniec){

    if(Koniec){
        co_robi = 4;
    }

}

void WatekOdbioru::run(){

    int DeskPortu;
    string Bufor;
    float x;
    float y;
    float z;
    char  FHeader;
    bool polacz = true;
    bool flaga = true;

    _Start = true;

     while (_Start) {
        while(_Sprawdz){
            if(_Sprawdz&&polacz){
                if ((DeskPortu = open("/dev/ttyUSB0",O_RDWR | O_NONBLOCK)) < 0) {
                    cerr << ":( Blad otwarcia portu /dev/ttyUSB0" << endl;
                }
                polacz = false;
            }
            if(RS232_Odbierz(DeskPortu,Bufor,1000,100)) {
                std::istringstream IStrm(Bufor);
                IStrm >> FHeader >> x >> y >> z;

                if (IStrm.fail() || FHeader != 'X' ){
                    cout << "Bledna ramka danych!" << endl;
                }

                if((x==8889)&&(y==8889)&&(z==8889)&&flaga){
                    _Kalibracja = true;
                    co_robi = 3;
                    flaga = false;
                }else{
                    emit Wspolrz(x,y,z);
                }
            }
        }
     }

}










MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Skaner 3D"));

    co_robi = 1;
     _Kalibracja = false;

    mCom = new WatekCom(this);
    mPoloz = new WatekPoloz(this);

    mCom->start();
    mPoloz->start();

    connect(mCom,&WatekCom::Status,this,&MainWindow::onStatus);
    connect(mCom,&WatekCom::NumberCh,this,&MainWindow::onNumberCh);
    connect(mCom,&WatekCom::Koniec,this,&MainWindow::onKoniec);

    connect(mPoloz,&WatekPoloz::Poloz,this,&MainWindow::onPoloz);



    ui->_pLabel_N_var->setRange(0,64);
    ui->_pLabel_H_var->setRange(0,9);

}

MainWindow::~MainWindow()
{
    mCom->_Start = false;
    mPoloz->_Start = false;
    delete ui;
}

void MainWindow::onNumberCh(bool kalib){
     if(kalib){
         QMessageBox::about(this,tr("Komunikat"),tr("Kalibracja przebieg??a poprawnie \nMo??na rozpocz???? skanowanie"));
     }
}

void MainWindow::onKoniec(bool koni){

    if(koni){
        QMessageBox::about(this,tr("Komunikat"),tr("Zako??czono skanowanie obiektu"));
    }

}
void MainWindow::onPoloz(int x, int y, int z){

    int ao = 0;
    int bo = 0;
    int co = 0;

    //cout << "Uruchamia sie!" << endl;

    if((ao != x)||(bo != y)||(co != z)){
         ui->_pLabel_x_var->setText(QString::number(x));
         ui->_pLabel_y_var->setText(QString::number(y));
         ui->_pLabel_z_var->setText(QString::number(z));
         ao = x;
         bo = y;
         co = z;
    }


}



void MainWindow::onStatus(bool zmienna){

    if(zmienna){

        QPixmap pix("/home/adam_j4/Qt/Select_1/img/green.png");
        ui->_pLabel_com_pix->setPixmap(pix);
        ui->_pLabel_com->setText(tr("Po????czono: "));

    }else{
        QPixmap pix("/home/adam_j4/Qt/Select_1/img/red.png");
        ui->_pLabel_com_pix->setPixmap(pix);
        ui->_pLabel_com->setText(tr("Brak po????czenia: "));
    }

}

void MainWindow::on_pushButton_ustaw_clicked(){

    int n = 0;
    int h = 0;
    char tab[20];

    if(co_robi == 1){

        n = ui->_pLabel_N_var->value();
        h = ui->_pLabel_H_var->value();

        if((n!=0)&&(h!=0)){
            co_robi = 2;
            sprintf(tab,"%d %d 987@",n,h);
            TestNadawania(tab);
            QMessageBox::about(this,tr("Komunikat"),tr("Poprawnie przes??ano paramtry, rozpocz??to kalibracj??"));

        }
        else{
            QMessageBox::warning(this,tr("Ostrze??enie"),tr("Nale??y ustawi?? odpowiednie parametry: \n\n N - liczba pomiar??w na obr??t \n H - odleg??o???? mi??dzy pomiarami"));
        }
    }
    else{
        QMessageBox::warning(this,tr("Ostrze??enie"),tr("Parametry zosta??y ju?? przes??ane"));
    }

}

void MainWindow::on_pushButton_stop_clicked(){

    TestNadawania("4 4 997@");

}

void MainWindow::on_pushButton_start_clicked(){

    if(co_robi >= 2){

        if(co_robi == 2){
            QMessageBox::warning(this,tr("Ostrze??enie"),tr("Skaner jest w trakcie kalibracji, prosz?? chwil?? poczeka??"));
        }
        else if(co_robi == 3){
            TestNadawania("4 4 944@");
        }
    }
    else{
        QMessageBox::warning(this,tr("Ostrze??enie"),tr("Nale??y ustawi?? parametry!"));
    }

}
