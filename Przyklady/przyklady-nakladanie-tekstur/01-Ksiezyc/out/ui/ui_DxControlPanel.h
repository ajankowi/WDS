/********************************************************************************
** Form generated from reading UI file 'DxControlPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DXCONTROLPANEL_H
#define UI_DXCONTROLPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DxControlPanel
{
public:
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *_pLabel_LightDir;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_2;
    QLabel *_pLabel_X;
    QSlider *_pSliderX;
    QSpinBox *_pSpinBoxX;
    QLabel *_pLabel_Y;
    QSlider *_pSliderY;
    QSpinBox *_pSpinBoxY;
    QLabel *_pLabel_Z;
    QSlider *_pSliderZ;
    QSpinBox *_pSpinBoxZ;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *_pLabel_LightDir_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *_pLabel_Kat;
    QSlider *_pSliderKat;
    QSpinBox *_pSpinBoxKat;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *DxControlPanel)
    {
        if (DxControlPanel->objectName().isEmpty())
            DxControlPanel->setObjectName(QString::fromUtf8("DxControlPanel"));
        DxControlPanel->resize(745, 190);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DxControlPanel->sizePolicy().hasHeightForWidth());
        DxControlPanel->setSizePolicy(sizePolicy);
        DxControlPanel->setMinimumSize(QSize(0, 180));
        DxControlPanel->setMaximumSize(QSize(16777215, 190));
        verticalLayout_3 = new QVBoxLayout(DxControlPanel);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        frame = new QFrame(DxControlPanel);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 140));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(3);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        _pLabel_LightDir = new QLabel(frame);
        _pLabel_LightDir->setObjectName(QString::fromUtf8("_pLabel_LightDir"));
        _pLabel_LightDir->setMaximumSize(QSize(16777215, 25));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        _pLabel_LightDir->setFont(font);

        verticalLayout->addWidget(_pLabel_LightDir);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(5);
        _pLabel_X = new QLabel(frame);
        _pLabel_X->setObjectName(QString::fromUtf8("_pLabel_X"));

        gridLayout_2->addWidget(_pLabel_X, 0, 0, 1, 1);

        _pSliderX = new QSlider(frame);
        _pSliderX->setObjectName(QString::fromUtf8("_pSliderX"));
        _pSliderX->setMinimumSize(QSize(200, 0));
        _pSliderX->setMinimum(-90);
        _pSliderX->setMaximum(90);
        _pSliderX->setValue(2);
        _pSliderX->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(_pSliderX, 0, 1, 1, 1);

        _pSpinBoxX = new QSpinBox(frame);
        _pSpinBoxX->setObjectName(QString::fromUtf8("_pSpinBoxX"));
        _pSpinBoxX->setMinimumSize(QSize(60, 0));
        _pSpinBoxX->setMinimum(-90);
        _pSpinBoxX->setMaximum(90);

        gridLayout_2->addWidget(_pSpinBoxX, 0, 2, 1, 1);

        _pLabel_Y = new QLabel(frame);
        _pLabel_Y->setObjectName(QString::fromUtf8("_pLabel_Y"));

        gridLayout_2->addWidget(_pLabel_Y, 1, 0, 1, 1);

        _pSliderY = new QSlider(frame);
        _pSliderY->setObjectName(QString::fromUtf8("_pSliderY"));
        _pSliderY->setMinimum(-90);
        _pSliderY->setMaximum(90);
        _pSliderY->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(_pSliderY, 1, 1, 1, 1);

        _pSpinBoxY = new QSpinBox(frame);
        _pSpinBoxY->setObjectName(QString::fromUtf8("_pSpinBoxY"));
        _pSpinBoxY->setMinimum(-90);
        _pSpinBoxY->setMaximum(90);

        gridLayout_2->addWidget(_pSpinBoxY, 1, 2, 1, 1);

        _pLabel_Z = new QLabel(frame);
        _pLabel_Z->setObjectName(QString::fromUtf8("_pLabel_Z"));

        gridLayout_2->addWidget(_pLabel_Z, 2, 0, 1, 1);

        _pSliderZ = new QSlider(frame);
        _pSliderZ->setObjectName(QString::fromUtf8("_pSliderZ"));
        _pSliderZ->setMinimum(-90);
        _pSliderZ->setMaximum(90);
        _pSliderZ->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(_pSliderZ, 2, 1, 1, 1);

        _pSpinBoxZ = new QSpinBox(frame);
        _pSpinBoxZ->setObjectName(QString::fromUtf8("_pSpinBoxZ"));
        _pSpinBoxZ->setMinimum(-90);
        _pSpinBoxZ->setMaximum(90);

        gridLayout_2->addWidget(_pSpinBoxZ, 2, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout_3->addWidget(frame);

        horizontalSpacer = new QSpacerItem(89, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        frame_2 = new QFrame(DxControlPanel);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(320, 140));
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Sunken);
        frame_2->setLineWidth(3);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        _pLabel_LightDir_2 = new QLabel(frame_2);
        _pLabel_LightDir_2->setObjectName(QString::fromUtf8("_pLabel_LightDir_2"));
        _pLabel_LightDir_2->setFont(font);

        verticalLayout_2->addWidget(_pLabel_LightDir_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        _pLabel_Kat = new QLabel(frame_2);
        _pLabel_Kat->setObjectName(QString::fromUtf8("_pLabel_Kat"));

        horizontalLayout_2->addWidget(_pLabel_Kat);

        _pSliderKat = new QSlider(frame_2);
        _pSliderKat->setObjectName(QString::fromUtf8("_pSliderKat"));
        _pSliderKat->setMinimum(-90);
        _pSliderKat->setMaximum(90);
        _pSliderKat->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(_pSliderKat);

        _pSpinBoxKat = new QSpinBox(frame_2);
        _pSpinBoxKat->setObjectName(QString::fromUtf8("_pSpinBoxKat"));
        _pSpinBoxKat->setMinimum(-90);
        _pSpinBoxKat->setMaximum(90);

        horizontalLayout_2->addWidget(_pSpinBoxKat);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 78, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_3->addWidget(frame_2);


        verticalLayout_3->addLayout(horizontalLayout_3);


        retranslateUi(DxControlPanel);
        QObject::connect(_pSliderKat, SIGNAL(valueChanged(int)), _pSpinBoxKat, SLOT(setValue(int)));
        QObject::connect(_pSpinBoxKat, SIGNAL(valueChanged(int)), _pSliderKat, SLOT(setValue(int)));
        QObject::connect(_pSpinBoxZ, SIGNAL(valueChanged(int)), _pSliderZ, SLOT(setValue(int)));
        QObject::connect(_pSliderZ, SIGNAL(valueChanged(int)), _pSpinBoxZ, SLOT(setValue(int)));
        QObject::connect(_pSpinBoxY, SIGNAL(valueChanged(int)), _pSliderY, SLOT(setValue(int)));
        QObject::connect(_pSliderY, SIGNAL(valueChanged(int)), _pSpinBoxY, SLOT(setValue(int)));
        QObject::connect(_pSpinBoxX, SIGNAL(valueChanged(int)), _pSliderX, SLOT(setValue(int)));
        QObject::connect(_pSliderX, SIGNAL(valueChanged(int)), _pSpinBoxX, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(DxControlPanel);
    } // setupUi

    void retranslateUi(QWidget *DxControlPanel)
    {
        DxControlPanel->setWindowTitle(QApplication::translate("DxControlPanel", "Form", nullptr));
        _pLabel_LightDir->setText(QApplication::translate("DxControlPanel", "Kierunek o\305\233wietlania:", nullptr));
        _pLabel_X->setText(QApplication::translate("DxControlPanel", "X ", nullptr));
#ifndef QT_NO_TOOLTIP
        _pSliderX->setToolTip(QApplication::translate("DxControlPanel", "Rotation of the second joint", nullptr));
#endif // QT_NO_TOOLTIP
        _pLabel_Y->setText(QApplication::translate("DxControlPanel", "Y", nullptr));
#ifndef QT_NO_TOOLTIP
        _pSliderY->setToolTip(QApplication::translate("DxControlPanel", "Rotation of the second joint", nullptr));
#endif // QT_NO_TOOLTIP
        _pLabel_Z->setText(QApplication::translate("DxControlPanel", "Z ", nullptr));
#ifndef QT_NO_TOOLTIP
        _pSliderZ->setToolTip(QApplication::translate("DxControlPanel", "Rotation of the second joint", nullptr));
#endif // QT_NO_TOOLTIP
        _pLabel_LightDir_2->setText(QApplication::translate("DxControlPanel", "K\304\205t obrotu kuli wok\303\263\305\202 osi OX:", nullptr));
        _pLabel_Kat->setText(QApplication::translate("DxControlPanel", "Kat [stopnie]", nullptr));
#ifndef QT_NO_TOOLTIP
        _pSliderKat->setToolTip(QApplication::translate("DxControlPanel", "Rotation of the second joint", nullptr));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class DxControlPanel: public Ui_DxControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DXCONTROLPANEL_H
