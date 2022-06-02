/********************************************************************************
** Form generated from reading UI file 'DxMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DXMAINWINDOW_H
#define UI_DXMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "GxControlPanel.hh"
#include "Viewer.hh"

QT_BEGIN_NAMESPACE

class Ui_DxMainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    Viewer *_pWidget_Viewer;
    GxControlPanel *_pWidget_CtrPanel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DxMainWindow)
    {
        if (DxMainWindow->objectName().isEmpty())
            DxMainWindow->setObjectName(QString::fromUtf8("DxMainWindow"));
        DxMainWindow->resize(782, 660);
        centralwidget = new QWidget(DxMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        _pWidget_Viewer = new Viewer(centralwidget);
        _pWidget_Viewer->setObjectName(QString::fromUtf8("_pWidget_Viewer"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(_pWidget_Viewer->sizePolicy().hasHeightForWidth());
        _pWidget_Viewer->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(_pWidget_Viewer);

        _pWidget_CtrPanel = new GxControlPanel(centralwidget);
        _pWidget_CtrPanel->setObjectName(QString::fromUtf8("_pWidget_CtrPanel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(_pWidget_CtrPanel->sizePolicy().hasHeightForWidth());
        _pWidget_CtrPanel->setSizePolicy(sizePolicy1);
        _pWidget_CtrPanel->setMinimumSize(QSize(0, 190));

        verticalLayout->addWidget(_pWidget_CtrPanel);

        DxMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DxMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 782, 22));
        DxMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DxMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DxMainWindow->setStatusBar(statusbar);

        retranslateUi(DxMainWindow);

        QMetaObject::connectSlotsByName(DxMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DxMainWindow)
    {
        DxMainWindow->setWindowTitle(QApplication::translate("DxMainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DxMainWindow: public Ui_DxMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DXMAINWINDOW_H
