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
// 1 - wysyla wartosci do skanera



void Punkt::ustawPoloz(int x, int y, int z){

    a = x;
    b = y;
    c = z;

    cout << "x: " << a << "  y: " << b << "  z: " << c << endl;

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

    //cout << "zyje" << endl;

    while(_Start){
        if((ao != a)||(bo != b)||(co != c)){
            ao = a;
            bo = b;
            co = c;
            //cout << "zyje 2" << endl;
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
            //cout << "Halo" << endl;
            emit Koniec(true);
            co_robi = 5;
        }
        //TUTAJ
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
                //TUTAJ
                //SetTransParam(DeskPortu);
            }
            if(RS232_Odbierz(DeskPortu,Bufor,1000,100)) {
                std::istringstream IStrm(Bufor);
                IStrm >> FHeader >> x >> y >> z;

                if (IStrm.fail() || FHeader != 'X' ){
                    cout << "Bledna ramka danych!" << endl;
                }
                //cout << x << y << z << endl;

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

    //mWatek = new WatekOdbioru(this);
    mCom = new WatekCom(this);
    mPoloz = new WatekPoloz(this);
    //mViewer = new Viewer(this);

    mCom->start();
    mPoloz->start();

    connect(mCom,&WatekCom::Status,this,&MainWindow::onStatus);
    connect(mCom,&WatekCom::NumberCh,this,&MainWindow::onNumberCh);
    connect(mCom,&WatekCom::Koniec,this,&MainWindow::onKoniec);

    connect(mPoloz,&WatekPoloz::Poloz,this,&MainWindow::onPoloz);



    ui->_pLabel_N_var->setRange(0,64);
    ui->_pLabel_H_var->setRange(0,9);



    // Oba dzialaja

    //connect(mWatek,&WatekOdbioru::NumberCh,this,&MainWindow::onNumberCh);
    //connect(mWatek,SIGNAL(NumberCh(QString)),this,SLOT(onNumberCh(QString)), Qt::DirectConnection);

    //connect(mWatek,SIGNAL(Wspolrz(int,int,int)),mViewer,SLOT(onWspolrz(int,int,int)), Qt::DirectConnection);
    //connect(mWatek,&WatekOdbioru::Wspolrz,mViewer,&Viewer::onWspolrz);
    //connect(mWatek,&WatekOdbioru::Wspolrz,this,&Viewer::onWspolrz);

    //Przyklad sygnalu
    //connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int)));

}

MainWindow::~MainWindow()
{
    mCom->_Start = false;
    mPoloz->_Start = false;
    delete ui;
}

void MainWindow::onNumberCh(bool kalib){
    //ui->_pLabel_N_var->setText(Nazwa);
     if(kalib){
         QMessageBox::about(this,tr("Komunikat"),tr("Kalibracja przebiegła poprawnie \nMożna rozpocząć skanowanie"));
     }
}

void MainWindow::onKoniec(bool koni){

    if(koni){
        QMessageBox::about(this,tr("Komunikat"),tr("Zakończono skanowanie obiektu"));
    }

}
void MainWindow::onPoloz(int x, int y, int z){

    int ao = 0;
    int bo = 0;
    int co = 0;

    cout << "Uruchamia sie!" << endl;

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
        ui->_pLabel_com->setText(tr("Połączono: "));

    }else{
        QPixmap pix("/home/adam_j4/Qt/Select_1/img/red.png");
        ui->_pLabel_com_pix->setPixmap(pix);
        ui->_pLabel_com->setText(tr("Brak połączenia: "));
    }

}

void MainWindow::on_pushButton_ustaw_clicked(){
    //ui->_pLabel_N_var->setText("ustaw");
    //Przyklad wiadomosci
    //QMessageBox::about(this,"Moj tytul","To jest bardzo wazna wiadomosc, której nie można pominac");

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
            QMessageBox::about(this,tr("Komunikat"),tr("Poprawnie przesłano paramtry, rozpoczęto kalibrację"));

        }
        else{
            QMessageBox::warning(this,tr("Ostrzeżenie"),tr("Należy ustawić odpowiednie parametry: \n\n N - liczba pomiarów na obrót \n H - odległość między pomiarami"));
        }
    }
    else{
        QMessageBox::warning(this,tr("Ostrzeżenie"),tr("Parametry zostały już przesłane"));
    }

}

void MainWindow::on_pushButton_stop_clicked(){

    TestNadawania("4 4 997@");


    //ui->_pLabel_H_var->setText("stop");
    //mWatek->_Start = false;

}

void MainWindow::on_pushButton_start_clicked(){

    if(co_robi >= 2){

        if(co_robi == 2){
            QMessageBox::warning(this,tr("Ostrzeżenie"),tr("Skaner jest w trakcie kalibracji, proszę chwilę poczekać"));
        }
        else if(co_robi == 3){
            TestNadawania("4 4 944@");
        }
    }
    else{
        QMessageBox::warning(this,tr("Ostrzeżenie"),tr("Należy ustawić parametry!"));
    }
     //mWatek->start();
     //mOdbior->start();
}
