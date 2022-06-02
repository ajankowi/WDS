/********************************************************************************
** Form generated from reading UI file 'oknoglowne.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OKNOGLOWNE_H
#define UI_OKNOGLOWNE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OknoGlowne
{
public:
    QAction *action_Open;
    QAction *action_Exit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *_pLabel_Flag;
    QSpacerItem *horizontalSpacer;
    QLabel *_wNapis_Jezyk;
    QComboBox *_wWyborJezyka;
    QLabel *_wEtykieta_Data;
    QLineEdit *_wNapis_Czas;
    QPushButton *_wPrzycisk_Koniec;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *OknoGlowne)
    {
        if (OknoGlowne->objectName().isEmpty())
            OknoGlowne->setObjectName(QString::fromUtf8("OknoGlowne"));
        OknoGlowne->resize(583, 257);
        action_Open = new QAction(OknoGlowne);
        action_Open->setObjectName(QString::fromUtf8("action_Open"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon);
        action_Exit = new QAction(OknoGlowne);
        action_Exit->setObjectName(QString::fromUtf8("action_Exit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Exit->setIcon(icon1);
        centralwidget = new QWidget(OknoGlowne);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        _pLabel_Flag = new QLabel(centralwidget);
        _pLabel_Flag->setObjectName(QString::fromUtf8("_pLabel_Flag"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(_pLabel_Flag->sizePolicy().hasHeightForWidth());
        _pLabel_Flag->setSizePolicy(sizePolicy);
        _pLabel_Flag->setPixmap(QPixmap(QString::fromUtf8(":/icons/flag_pl.png")));

        gridLayout->addWidget(_pLabel_Flag, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(327, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 2);

        _wNapis_Jezyk = new QLabel(centralwidget);
        _wNapis_Jezyk->setObjectName(QString::fromUtf8("_wNapis_Jezyk"));
        QFont font;
        font.setPointSize(11);
        _wNapis_Jezyk->setFont(font);
        _wNapis_Jezyk->setLayoutDirection(Qt::LeftToRight);
        _wNapis_Jezyk->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(_wNapis_Jezyk, 1, 2, 1, 1);

        _wWyborJezyka = new QComboBox(centralwidget);
        _wWyborJezyka->setObjectName(QString::fromUtf8("_wWyborJezyka"));

        gridLayout->addWidget(_wWyborJezyka, 1, 3, 1, 1);

        _wEtykieta_Data = new QLabel(centralwidget);
        _wEtykieta_Data->setObjectName(QString::fromUtf8("_wEtykieta_Data"));
        _wEtykieta_Data->setMinimumSize(QSize(10, 10));
        QFont font1;
        font1.setPointSize(14);
        _wEtykieta_Data->setFont(font1);

        gridLayout->addWidget(_wEtykieta_Data, 2, 0, 1, 1);

        _wNapis_Czas = new QLineEdit(centralwidget);
        _wNapis_Czas->setObjectName(QString::fromUtf8("_wNapis_Czas"));
        _wNapis_Czas->setMinimumSize(QSize(200, 20));
        _wNapis_Czas->setReadOnly(true);

        gridLayout->addWidget(_wNapis_Czas, 2, 1, 1, 1);

        _wPrzycisk_Koniec = new QPushButton(centralwidget);
        _wPrzycisk_Koniec->setObjectName(QString::fromUtf8("_wPrzycisk_Koniec"));

        gridLayout->addWidget(_wPrzycisk_Koniec, 3, 3, 1, 1);

        OknoGlowne->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OknoGlowne);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 583, 22));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        OknoGlowne->setMenuBar(menubar);
        statusbar = new QStatusBar(OknoGlowne);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        OknoGlowne->setStatusBar(statusbar);
        toolBar = new QToolBar(OknoGlowne);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setOrientation(Qt::Horizontal);
        OknoGlowne->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(action_Open);
        menu_File->addAction(action_Exit);
        toolBar->addAction(action_Open);
        toolBar->addAction(action_Exit);

        retranslateUi(OknoGlowne);

        QMetaObject::connectSlotsByName(OknoGlowne);
    } // setupUi

    void retranslateUi(QMainWindow *OknoGlowne)
    {
        OknoGlowne->setWindowTitle(QApplication::translate("OknoGlowne", "Application Window", nullptr));
        action_Open->setText(QApplication::translate("OknoGlowne", "&Open", nullptr));
#ifndef QT_NO_TOOLTIP
        action_Open->setToolTip(QApplication::translate("OknoGlowne", "Open a new file", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_Open->setStatusTip(QApplication::translate("OknoGlowne", "Open a new file (status bar)", nullptr));
#endif // QT_NO_STATUSTIP
        action_Exit->setText(QApplication::translate("OknoGlowne", "&Exit", nullptr));
#ifndef QT_NO_TOOLTIP
        action_Exit->setToolTip(QApplication::translate("OknoGlowne", "Exit the application", nullptr));
#endif // QT_NO_TOOLTIP
        _pLabel_Flag->setText(QString());
        _wNapis_Jezyk->setText(QApplication::translate("OknoGlowne", "Language:", nullptr));
        _wEtykieta_Data->setText(QApplication::translate("OknoGlowne", "Current date:", nullptr));
#ifndef QT_NO_STATUSTIP
        _wPrzycisk_Koniec->setStatusTip(QApplication::translate("OknoGlowne", "Close and exit an application", nullptr));
#endif // QT_NO_STATUSTIP
        _wPrzycisk_Koniec->setText(QApplication::translate("OknoGlowne", "Close", nullptr));
        menu_File->setTitle(QApplication::translate("OknoGlowne", "&File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OknoGlowne: public Ui_OknoGlowne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OKNOGLOWNE_H
