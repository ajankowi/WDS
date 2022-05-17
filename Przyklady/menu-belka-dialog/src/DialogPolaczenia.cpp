#include <iostream>
#include "DialogPolaczenia.hh"

using namespace std;


DialogPolaczenia::DialogPolaczenia(QLineEdit *wDisplay_Connection, QStatusBar *wStatus)
{
  setObjectName("Dialog_Polaczenia");  
  setupUi(this);
  _wWyswietlacz = wDisplay_Connection;
  _wStatus = wStatus;
}


void DialogPolaczenia::on_Dialog_Polaczenia_accepted()
{
  if (_wPortSelection->currentIndex() == 0) {
    _wWyswietlacz->setText("");
    _wStatus->showMessage(tr("Rozłączenie ..."),2000);
    return;
  }
  _wWyswietlacz->setText(_wPortSelection->currentText());
  _wStatus->showMessage(tr("Połączenie ..."),2000);  
}


void DialogPolaczenia::on_Dialog_Polaczenia_rejected()
{
  cout << "Rejected" << endl;
}
