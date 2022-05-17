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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QVBoxLayout *verticalLayout;
    QLabel *_pLabel_Data;
    QFrame *frame_3;
    QGridLayout *gridLayout_2;
    QLabel *_pLabel_Temp_5;
    QLineEdit *_pLabel_Temp_4;
    QLabel *_pLabel_Temp_6;
    QLabel *_pLabel_Pressure_5;
    QLineEdit *_pLabel_Pressure_6;
    QLabel *_pLabel_Pressure_4;
    QLabel *_pLabel_Wind_5;
    QLineEdit *_pLabel_Wind_4;
    QLabel *_pLabel_Wind_6;
    QLabel *_pLabel_Clouds_6;
    QLineEdit *_pLabel_Clouds_4;
    QLabel *_pLabel_Clouds_5;
    QLabel *_pLabel_Rain_6;
    QLineEdit *_pLabel_Rain_5;
    QLabel *_pLabel_Rain_4;
    QLabel *_pLabel_Humidity_6;
    QLineEdit *_pLabel_Humidity_4;
    QLabel *_pLabel_Humidity_5;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *_pLabel_AirQuality;
    QLineEdit *_pLabel_AirQuality_2;
    QLabel *_pLabel_PM25;
    QLineEdit *_pLabel_PM25_2;
    QLabel *_pLabel_PM25_3;
    QLabel *_pLabel_PM10;
    QLineEdit *_pLabel_PM10_2;
    QLabel *_pLabel_PM10_3;
    QLabel *_pLabel_CO;
    QLineEdit *_pLabel_CO_2;
    QLabel *_pLabel_CO_3;
    QLabel *_pLabel_NO;
    QLineEdit *_pLabel_NO_2;
    QLabel *_pLabel_NO_3;
    QLabel *_pLabel_SO2;
    QLineEdit *_pLabel_SO2_2;
    QLabel *_pLabel_SO2_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *_wPrzycisk_Zamknij;

    void setupUi(QWidget *InfoWindow)
    {
        if (InfoWindow->objectName().isEmpty())
            InfoWindow->setObjectName(QString::fromUtf8("InfoWindow"));
        InfoWindow->setEnabled(true);
        InfoWindow->resize(735, 494);
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

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        _pLabel_Data = new QLabel(InfoWindow);
        _pLabel_Data->setObjectName(QString::fromUtf8("_pLabel_Data"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        _pLabel_Data->setFont(font);
        _pLabel_Data->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(_pLabel_Data);

        frame_3 = new QFrame(InfoWindow);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(291, 0));
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Sunken);
        frame_3->setLineWidth(2);
        gridLayout_2 = new QGridLayout(frame_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        _pLabel_Temp_5 = new QLabel(frame_3);
        _pLabel_Temp_5->setObjectName(QString::fromUtf8("_pLabel_Temp_5"));
        _pLabel_Temp_5->setMinimumSize(QSize(151, 0));
        _pLabel_Temp_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(_pLabel_Temp_5, 0, 0, 1, 1);

        _pLabel_Temp_4 = new QLineEdit(frame_3);
        _pLabel_Temp_4->setObjectName(QString::fromUtf8("_pLabel_Temp_4"));
        _pLabel_Temp_4->setMaximumSize(QSize(100, 16777215));
        _pLabel_Temp_4->setFocusPolicy(Qt::NoFocus);
        _pLabel_Temp_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        _pLabel_Temp_4->setReadOnly(true);

        gridLayout_2->addWidget(_pLabel_Temp_4, 0, 1, 1, 1);

        _pLabel_Temp_6 = new QLabel(frame_3);
        _pLabel_Temp_6->setObjectName(QString::fromUtf8("_pLabel_Temp_6"));
        _pLabel_Temp_6->setMinimumSize(QSize(45, 0));

        gridLayout_2->addWidget(_pLabel_Temp_6, 0, 2, 1, 1);

        _pLabel_Pressure_5 = new QLabel(frame_3);
        _pLabel_Pressure_5->setObjectName(QString::fromUtf8("_pLabel_Pressure_5"));
        _pLabel_Pressure_5->setMinimumSize(QSize(151, 0));
        _pLabel_Pressure_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(_pLabel_Pressure_5, 1, 0, 1, 1);

        _pLabel_Pressure_6 = new QLineEdit(frame_3);
        _pLabel_Pressure_6->setObjectName(QString::fromUtf8("_pLabel_Pressure_6"));
        _pLabel_Pressure_6->setMaximumSize(QSize(100, 16777215));
        _pLabel_Pressure_6->setFocusPolicy(Qt::NoFocus);
        _pLabel_Pressure_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        _pLabel_Pressure_6->setReadOnly(true);

        gridLayout_2->addWidget(_pLabel_Pressure_6, 1, 1, 1, 1);

        _pLabel_Pressure_4 = new QLabel(frame_3);
        _pLabel_Pressure_4->setObjectName(QString::fromUtf8("_pLabel_Pressure_4"));
        _pLabel_Pressure_4->setMinimumSize(QSize(45, 0));

        gridLayout_2->addWidget(_pLabel_Pressure_4, 1, 2, 1, 1);

        _pLabel_Wind_5 = new QLabel(frame_3);
        _pLabel_Wind_5->setObjectName(QString::fromUtf8("_pLabel_Wind_5"));
        _pLabel_Wind_5->setMinimumSize(QSize(151, 0));
        _pLabel_Wind_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(_pLabel_Wind_5, 2, 0, 1, 1);

        _pLabel_Wind_4 = new QLineEdit(frame_3);
        _pLabel_Wind_4->setObjectName(QString::fromUtf8("_pLabel_Wind_4"));
        _pLabel_Wind_4->setMaximumSize(QSize(100, 16777215));
        _pLabel_Wind_4->setFocusPolicy(Qt::NoFocus);
        _pLabel_Wind_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        _pLabel_Wind_4->setReadOnly(true);

        gridLayout_2->addWidget(_pLabel_Wind_4, 2, 1, 1, 1);

        _pLabel_Wind_6 = new QLabel(frame_3);
        _pLabel_Wind_6->setObjectName(QString::fromUtf8("_pLabel_Wind_6"));
        _pLabel_Wind_6->setMinimumSize(QSize(45, 0));

        gridLayout_2->addWidget(_pLabel_Wind_6, 2, 2, 1, 1);

        _pLabel_Clouds_6 = new QLabel(frame_3);
        _pLabel_Clouds_6->setObjectName(QString::fromUtf8("_pLabel_Clouds_6"));
        _pLabel_Clouds_6->setMinimumSize(QSize(151, 0));
        _pLabel_Clouds_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(_pLabel_Clouds_6, 3, 0, 1, 1);

        _pLabel_Clouds_4 = new QLineEdit(frame_3);
        _pLabel_Clouds_4->setObjectName(QString::fromUtf8("_pLabel_Clouds_4"));
        _pLabel_Clouds_4->setMaximumSize(QSize(100, 16777215));
        _pLabel_Clouds_4->setFocusPolicy(Qt::NoFocus);
        _pLabel_Clouds_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        _pLabel_Clouds_4->setReadOnly(true);

        gridLayout_2->addWidget(_pLabel_Clouds_4, 3, 1, 1, 1);

        _pLabel_Clouds_5 = new QLabel(frame_3);
        _pLabel_Clouds_5->setObjectName(QString::fromUtf8("_pLabel_Clouds_5"));
        _pLabel_Clouds_5->setMinimumSize(QSize(45, 0));

        gridLayout_2->addWidget(_pLabel_Clouds_5, 3, 2, 1, 1);

        _pLabel_Rain_6 = new QLabel(frame_3);
        _pLabel_Rain_6->setObjectName(QString::fromUtf8("_pLabel_Rain_6"));
        _pLabel_Rain_6->setMinimumSize(QSize(151, 0));
        _pLabel_Rain_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(_pLabel_Rain_6, 4, 0, 1, 1);

        _pLabel_Rain_5 = new QLineEdit(frame_3);
        _pLabel_Rain_5->setObjectName(QString::fromUtf8("_pLabel_Rain_5"));
        _pLabel_Rain_5->setMaximumSize(QSize(100, 16777215));
        _pLabel_Rain_5->setFocusPolicy(Qt::NoFocus);
        _pLabel_Rain_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        _pLabel_Rain_5->setReadOnly(true);

        gridLayout_2->addWidget(_pLabel_Rain_5, 4, 1, 1, 1);

        _pLabel_Rain_4 = new QLabel(frame_3);
        _pLabel_Rain_4->setObjectName(QString::fromUtf8("_pLabel_Rain_4"));
        _pLabel_Rain_4->setMinimumSize(QSize(45, 0));

        gridLayout_2->addWidget(_pLabel_Rain_4, 4, 2, 1, 1);

        _pLabel_Humidity_6 = new QLabel(frame_3);
        _pLabel_Humidity_6->setObjectName(QString::fromUtf8("_pLabel_Humidity_6"));
        _pLabel_Humidity_6->setMinimumSize(QSize(151, 0));
        _pLabel_Humidity_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(_pLabel_Humidity_6, 5, 0, 1, 1);

        _pLabel_Humidity_4 = new QLineEdit(frame_3);
        _pLabel_Humidity_4->setObjectName(QString::fromUtf8("_pLabel_Humidity_4"));
        _pLabel_Humidity_4->setMaximumSize(QSize(100, 16777215));
        _pLabel_Humidity_4->setFocusPolicy(Qt::NoFocus);
        _pLabel_Humidity_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        _pLabel_Humidity_4->setReadOnly(true);

        gridLayout_2->addWidget(_pLabel_Humidity_4, 5, 1, 1, 1);

        _pLabel_Humidity_5 = new QLabel(frame_3);
        _pLabel_Humidity_5->setObjectName(QString::fromUtf8("_pLabel_Humidity_5"));
        _pLabel_Humidity_5->setMinimumSize(QSize(45, 0));

        gridLayout_2->addWidget(_pLabel_Humidity_5, 5, 2, 1, 1);


        verticalLayout->addWidget(frame_3);

        frame = new QFrame(InfoWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(2);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        _pLabel_AirQuality = new QLabel(frame);
        _pLabel_AirQuality->setObjectName(QString::fromUtf8("_pLabel_AirQuality"));
        _pLabel_AirQuality->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(_pLabel_AirQuality, 0, 0, 1, 1);

        _pLabel_AirQuality_2 = new QLineEdit(frame);
        _pLabel_AirQuality_2->setObjectName(QString::fromUtf8("_pLabel_AirQuality_2"));
        _pLabel_AirQuality_2->setMaximumSize(QSize(100, 16777215));
        _pLabel_AirQuality_2->setFocusPolicy(Qt::NoFocus);
        _pLabel_AirQuality_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        _pLabel_AirQuality_2->setReadOnly(true);

        gridLayout->addWidget(_pLabel_AirQuality_2, 0, 1, 1, 1);

        _pLabel_PM25 = new QLabel(frame);
        _pLabel_PM25->setObjectName(QString::fromUtf8("_pLabel_PM25"));
        _pLabel_PM25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(_pLabel_PM25, 1, 0, 1, 1);

        _pLabel_PM25_2 = new QLineEdit(frame);
        _pLabel_PM25_2->setObjectName(QString::fromUtf8("_pLabel_PM25_2"));
        _pLabel_PM25_2->setMaximumSize(QSize(100, 16777215));
        _pLabel_PM25_2->setFocusPolicy(Qt::NoFocus);
        _pLabel_PM25_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        _pLabel_PM25_2->setReadOnly(true);

        gridLayout->addWidget(_pLabel_PM25_2, 1, 1, 1, 1);

        _pLabel_PM25_3 = new QLabel(frame);
        _pLabel_PM25_3->setObjectName(QString::fromUtf8("_pLabel_PM25_3"));

        gridLayout->addWidget(_pLabel_PM25_3, 1, 2, 1, 1);

        _pLabel_PM10 = new QLabel(frame);
        _pLabel_PM10->setObjectName(QString::fromUtf8("_pLabel_PM10"));
        _pLabel_PM10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(_pLabel_PM10, 2, 0, 1, 1);

        _pLabel_PM10_2 = new QLineEdit(frame);
        _pLabel_PM10_2->setObjectName(QString::fromUtf8("_pLabel_PM10_2"));
        _pLabel_PM10_2->setMaximumSize(QSize(100, 16777215));
        _pLabel_PM10_2->setFocusPolicy(Qt::NoFocus);
        _pLabel_PM10_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        _pLabel_PM10_2->setReadOnly(true);

        gridLayout->addWidget(_pLabel_PM10_2, 2, 1, 1, 1);

        _pLabel_PM10_3 = new QLabel(frame);
        _pLabel_PM10_3->setObjectName(QString::fromUtf8("_pLabel_PM10_3"));

        gridLayout->addWidget(_pLabel_PM10_3, 2, 2, 1, 1);

        _pLabel_CO = new QLabel(frame);
        _pLabel_CO->setObjectName(QString::fromUtf8("_pLabel_CO"));
        _pLabel_CO->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(_pLabel_CO, 3, 0, 1, 1);

        _pLabel_CO_2 = new QLineEdit(frame);
        _pLabel_CO_2->setObjectName(QString::fromUtf8("_pLabel_CO_2"));
        _pLabel_CO_2->setMaximumSize(QSize(100, 16777215));
        _pLabel_CO_2->setFocusPolicy(Qt::NoFocus);
        _pLabel_CO_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        _pLabel_CO_2->setReadOnly(true);

        gridLayout->addWidget(_pLabel_CO_2, 3, 1, 1, 1);

        _pLabel_CO_3 = new QLabel(frame);
        _pLabel_CO_3->setObjectName(QString::fromUtf8("_pLabel_CO_3"));

        gridLayout->addWidget(_pLabel_CO_3, 3, 2, 1, 1);

        _pLabel_NO = new QLabel(frame);
        _pLabel_NO->setObjectName(QString::fromUtf8("_pLabel_NO"));
        _pLabel_NO->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(_pLabel_NO, 4, 0, 1, 1);

        _pLabel_NO_2 = new QLineEdit(frame);
        _pLabel_NO_2->setObjectName(QString::fromUtf8("_pLabel_NO_2"));
        _pLabel_NO_2->setMaximumSize(QSize(100, 16777215));
        _pLabel_NO_2->setFocusPolicy(Qt::NoFocus);
        _pLabel_NO_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        _pLabel_NO_2->setReadOnly(true);

        gridLayout->addWidget(_pLabel_NO_2, 4, 1, 1, 1);

        _pLabel_NO_3 = new QLabel(frame);
        _pLabel_NO_3->setObjectName(QString::fromUtf8("_pLabel_NO_3"));

        gridLayout->addWidget(_pLabel_NO_3, 4, 2, 1, 1);

        _pLabel_SO2 = new QLabel(frame);
        _pLabel_SO2->setObjectName(QString::fromUtf8("_pLabel_SO2"));
        _pLabel_SO2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(_pLabel_SO2, 5, 0, 1, 1);

        _pLabel_SO2_2 = new QLineEdit(frame);
        _pLabel_SO2_2->setObjectName(QString::fromUtf8("_pLabel_SO2_2"));
        _pLabel_SO2_2->setMaximumSize(QSize(100, 16777215));
        _pLabel_SO2_2->setFocusPolicy(Qt::NoFocus);
        _pLabel_SO2_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        _pLabel_SO2_2->setReadOnly(true);

        gridLayout->addWidget(_pLabel_SO2_2, 5, 1, 1, 1);

        _pLabel_SO2_3 = new QLabel(frame);
        _pLabel_SO2_3->setObjectName(QString::fromUtf8("_pLabel_SO2_3"));

        gridLayout->addWidget(_pLabel_SO2_3, 5, 2, 1, 1);


        verticalLayout->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _wPrzycisk_Zamknij = new QPushButton(InfoWindow);
        _wPrzycisk_Zamknij->setObjectName(QString::fromUtf8("_wPrzycisk_Zamknij"));

        horizontalLayout->addWidget(_wPrzycisk_Zamknij);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(InfoWindow);

        QMetaObject::connectSlotsByName(InfoWindow);
    } // setupUi

    void retranslateUi(QWidget *InfoWindow)
    {
        InfoWindow->setWindowTitle(QApplication::translate("InfoWindow", "Form", nullptr));
        _pLabel_Map->setText(QString());
        _pLabel_Data->setText(QApplication::translate("InfoWindow", "Poniedzia\305\202ek, 25.04.2021", nullptr));
        _pLabel_Temp_5->setText(QApplication::translate("InfoWindow", "Temperatura:", nullptr));
        _pLabel_Temp_4->setText(QApplication::translate("InfoWindow", "23 ", nullptr));
        _pLabel_Temp_6->setText(QApplication::translate("InfoWindow", "C", nullptr));
        _pLabel_Pressure_5->setText(QApplication::translate("InfoWindow", "Ci\305\233nienie:", nullptr));
        _pLabel_Pressure_6->setText(QApplication::translate("InfoWindow", "1002", nullptr));
        _pLabel_Pressure_4->setText(QApplication::translate("InfoWindow", "hPa", nullptr));
        _pLabel_Wind_5->setText(QApplication::translate("InfoWindow", "Wiatr: ", nullptr));
        _pLabel_Wind_4->setText(QApplication::translate("InfoWindow", "1", nullptr));
        _pLabel_Wind_6->setText(QApplication::translate("InfoWindow", "m/s", nullptr));
        _pLabel_Clouds_6->setText(QApplication::translate("InfoWindow", "Zachmurzenie:", nullptr));
        _pLabel_Clouds_4->setText(QApplication::translate("InfoWindow", "24", nullptr));
        _pLabel_Clouds_5->setText(QApplication::translate("InfoWindow", "%", nullptr));
        _pLabel_Rain_6->setText(QApplication::translate("InfoWindow", "Deszcz:", nullptr));
        _pLabel_Rain_5->setText(QApplication::translate("InfoWindow", "0,5", nullptr));
        _pLabel_Rain_4->setText(QApplication::translate("InfoWindow", "mm", nullptr));
        _pLabel_Humidity_6->setText(QApplication::translate("InfoWindow", "Wilgotno\305\233\304\207:", nullptr));
        _pLabel_Humidity_4->setText(QApplication::translate("InfoWindow", "40", nullptr));
        _pLabel_Humidity_5->setText(QApplication::translate("InfoWindow", "%", nullptr));
        _pLabel_AirQuality->setText(QApplication::translate("InfoWindow", "Jako\305\233\304\207 powietrza:", nullptr));
        _pLabel_AirQuality_2->setText(QApplication::translate("InfoWindow", "dobra", nullptr));
        _pLabel_PM25->setText(QApplication::translate("InfoWindow", "Py\305\202 zawieszony PM2.5:", nullptr));
        _pLabel_PM25_2->setText(QApplication::translate("InfoWindow", "2,19", nullptr));
        _pLabel_PM25_3->setText(QApplication::translate("InfoWindow", "ug/m3", nullptr));
        _pLabel_PM10->setText(QApplication::translate("InfoWindow", "Py\305\202 zawieszony PM10:", nullptr));
        _pLabel_PM10_2->setText(QApplication::translate("InfoWindow", "2,88", nullptr));
        _pLabel_PM10_3->setText(QApplication::translate("InfoWindow", "ug/m3", nullptr));
        _pLabel_CO->setText(QApplication::translate("InfoWindow", "CO:", nullptr));
        _pLabel_CO_2->setText(QApplication::translate("InfoWindow", "160", nullptr));
        _pLabel_CO_3->setText(QApplication::translate("InfoWindow", "ug/m3", nullptr));
        _pLabel_NO->setText(QApplication::translate("InfoWindow", "NO:", nullptr));
        _pLabel_NO_2->setText(QApplication::translate("InfoWindow", "1", nullptr));
        _pLabel_NO_3->setText(QApplication::translate("InfoWindow", "ug/m3", nullptr));
        _pLabel_SO2->setText(QApplication::translate("InfoWindow", "SO2:", nullptr));
        _pLabel_SO2_2->setText(QApplication::translate("InfoWindow", "4,8", nullptr));
        _pLabel_SO2_3->setText(QApplication::translate("InfoWindow", "ug/m3", nullptr));
        _wPrzycisk_Zamknij->setText(QApplication::translate("InfoWindow", "Zamknij", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoWindow: public Ui_InfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOWINDOW_H
