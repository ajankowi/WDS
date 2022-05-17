/********************************************************************************
** Form generated from reading UI file 'InfoWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOWINDOW_H
#define UI_INFOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoWindow
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *_pLabel_Map;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *_pLabel_Data;
    QLabel *_pLabel_Temp;
    QLabel *_pLabel_Pressure;
    QLabel *_pLabel_Clouds;
    QLabel *_pLabel_Humidity;
    QLabel *_pLabel_Rain;
    QLabel *_pLabel_AirQuality;
    QLabel *_pLabel_Wind;
    QLabel *_pLabel_PM25;
    QLabel *_pLabel_PM10;
    QLabel *_pLabel_CO;
    QLabel *_pLabel_NO;
    QLabel *_pLabel_SO2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *_wPrzycisk_Zamknij;

    void setupUi(QWidget *InfoWindow)
    {
        if (InfoWindow->objectName().isEmpty())
            InfoWindow->setObjectName(QString::fromUtf8("InfoWindow"));
        InfoWindow->resize(745, 426);
        horizontalLayout_2 = new QHBoxLayout(InfoWindow);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        _pLabel_Map = new QLabel(InfoWindow);
        _pLabel_Map->setObjectName(QString::fromUtf8("_pLabel_Map"));
        _pLabel_Map->setPixmap(QPixmap(QString::fromUtf8(":/maps/img/mapa.png")));

        verticalLayout_3->addWidget(_pLabel_Map);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        _pLabel_Data = new QLabel(InfoWindow);
        _pLabel_Data->setObjectName(QString::fromUtf8("_pLabel_Data"));

        verticalLayout->addWidget(_pLabel_Data);

        _pLabel_Temp = new QLabel(InfoWindow);
        _pLabel_Temp->setObjectName(QString::fromUtf8("_pLabel_Temp"));

        verticalLayout->addWidget(_pLabel_Temp);

        _pLabel_Pressure = new QLabel(InfoWindow);
        _pLabel_Pressure->setObjectName(QString::fromUtf8("_pLabel_Pressure"));

        verticalLayout->addWidget(_pLabel_Pressure);

        _pLabel_Clouds = new QLabel(InfoWindow);
        _pLabel_Clouds->setObjectName(QString::fromUtf8("_pLabel_Clouds"));

        verticalLayout->addWidget(_pLabel_Clouds);

        _pLabel_Humidity = new QLabel(InfoWindow);
        _pLabel_Humidity->setObjectName(QString::fromUtf8("_pLabel_Humidity"));

        verticalLayout->addWidget(_pLabel_Humidity);

        _pLabel_Rain = new QLabel(InfoWindow);
        _pLabel_Rain->setObjectName(QString::fromUtf8("_pLabel_Rain"));

        verticalLayout->addWidget(_pLabel_Rain);

        _pLabel_AirQuality = new QLabel(InfoWindow);
        _pLabel_AirQuality->setObjectName(QString::fromUtf8("_pLabel_AirQuality"));

        verticalLayout->addWidget(_pLabel_AirQuality);

        _pLabel_Wind = new QLabel(InfoWindow);
        _pLabel_Wind->setObjectName(QString::fromUtf8("_pLabel_Wind"));

        verticalLayout->addWidget(_pLabel_Wind);

        _pLabel_PM25 = new QLabel(InfoWindow);
        _pLabel_PM25->setObjectName(QString::fromUtf8("_pLabel_PM25"));

        verticalLayout->addWidget(_pLabel_PM25);

        _pLabel_PM10 = new QLabel(InfoWindow);
        _pLabel_PM10->setObjectName(QString::fromUtf8("_pLabel_PM10"));

        verticalLayout->addWidget(_pLabel_PM10);

        _pLabel_CO = new QLabel(InfoWindow);
        _pLabel_CO->setObjectName(QString::fromUtf8("_pLabel_CO"));

        verticalLayout->addWidget(_pLabel_CO);

        _pLabel_NO = new QLabel(InfoWindow);
        _pLabel_NO->setObjectName(QString::fromUtf8("_pLabel_NO"));

        verticalLayout->addWidget(_pLabel_NO);

        _pLabel_SO2 = new QLabel(InfoWindow);
        _pLabel_SO2->setObjectName(QString::fromUtf8("_pLabel_SO2"));

        verticalLayout->addWidget(_pLabel_SO2);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _wPrzycisk_Zamknij = new QPushButton(InfoWindow);
        _wPrzycisk_Zamknij->setObjectName(QString::fromUtf8("_wPrzycisk_Zamknij"));

        horizontalLayout->addWidget(_wPrzycisk_Zamknij);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(InfoWindow);

        QMetaObject::connectSlotsByName(InfoWindow);
    } // setupUi

    void retranslateUi(QWidget *InfoWindow)
    {
        InfoWindow->setWindowTitle(QApplication::translate("InfoWindow", "Form", nullptr));
        _pLabel_Map->setText(QString());
        _pLabel_Data->setText(QApplication::translate("InfoWindow", "Poniedzia\305\202ek, 25.04.2021", nullptr));
        _pLabel_Temp->setText(QApplication::translate("InfoWindow", "Temperatura: 23 C", nullptr));
        _pLabel_Pressure->setText(QApplication::translate("InfoWindow", "Ci\305\233nienie: 1002 hPa", nullptr));
        _pLabel_Clouds->setText(QApplication::translate("InfoWindow", "Zachmurzenie: 24%", nullptr));
        _pLabel_Humidity->setText(QApplication::translate("InfoWindow", "Wilgotno\305\233\304\207: 40%", nullptr));
        _pLabel_Rain->setText(QApplication::translate("InfoWindow", "Deszcz: 0,5 mm", nullptr));
        _pLabel_AirQuality->setText(QApplication::translate("InfoWindow", "Jako\305\233\304\207 powietrza: dobra", nullptr));
        _pLabel_Wind->setText(QApplication::translate("InfoWindow", "Wiatr: 1 m/s", nullptr));
        _pLabel_PM25->setText(QApplication::translate("InfoWindow", "Py\305\202 zawieszony PM2.5:  2,19 ug/m3", nullptr));
        _pLabel_PM10->setText(QApplication::translate("InfoWindow", "Py\305\202 zawieszonyPM10: 2,88 ug/m3", nullptr));
        _pLabel_CO->setText(QApplication::translate("InfoWindow", "CO: 160 ug/m3", nullptr));
        _pLabel_NO->setText(QApplication::translate("InfoWindow", "NO:  1 ug/m3", nullptr));
        _pLabel_SO2->setText(QApplication::translate("InfoWindow", "SO2: 4,8 ug/m3", nullptr));
        _wPrzycisk_Zamknij->setText(QApplication::translate("InfoWindow", "Zamknij", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoWindow: public Ui_InfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOWINDOW_H
