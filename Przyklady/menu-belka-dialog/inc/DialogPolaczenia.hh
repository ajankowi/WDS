#ifndef DIALOGPOLACZENIA_HH
#define DIALOGPOLACZENIA_HH


#include <QDialog>
#include <QLineEdit>
#include <QStatusBar>
#include "ui_DDialogPolaczenia.h"

class DialogPolaczenia: public QDialog, public Ui::DDialogPolaczenia {
    Q_OBJECT
    QLineEdit  *_wWyswietlacz = nullptr;
    QStatusBar *_wStatus = nullptr;
  
  public:
   DialogPolaczenia(QLineEdit *wDisplay_Connection, QStatusBar *wStatus);

  public slots:
   void on_Dialog_Polaczenia_accepted();
   void on_Dialog_Polaczenia_rejected();
};


#endif
