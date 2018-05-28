/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "qwebengineview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QPushButton *s;
    QPushButton *q;
    QPushButton *z;
    QPushButton *d;
    QToolButton *haut;
    QToolButton *bas;
    QToolButton *droite;
    QToolButton *gauche;
    QLabel *label_3;
    QLabel *label_4;
    QSlider *verticalSlider;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *hostname;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *port;
    QPushButton *btnConnect;
    QPushButton *btnDeconnect;
    QWebEngineView *camera;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(917, 762);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 500, 901, 201));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        s = new QPushButton(frame);
        s->setObjectName(QStringLiteral("s"));
        s->setGeometry(QRect(70, 130, 61, 61));
        q = new QPushButton(frame);
        q->setObjectName(QStringLiteral("q"));
        q->setGeometry(QRect(10, 70, 61, 61));
        z = new QPushButton(frame);
        z->setObjectName(QStringLiteral("z"));
        z->setGeometry(QRect(70, 10, 61, 61));
        d = new QPushButton(frame);
        d->setObjectName(QStringLiteral("d"));
        d->setGeometry(QRect(130, 70, 61, 61));
        haut = new QToolButton(frame);
        haut->setObjectName(QStringLiteral("haut"));
        haut->setGeometry(QRect(750, 10, 61, 61));
        bas = new QToolButton(frame);
        bas->setObjectName(QStringLiteral("bas"));
        bas->setGeometry(QRect(750, 130, 61, 61));
        droite = new QToolButton(frame);
        droite->setObjectName(QStringLiteral("droite"));
        droite->setGeometry(QRect(810, 70, 61, 61));
        gauche = new QToolButton(frame);
        gauche->setObjectName(QStringLiteral("gauche"));
        gauche->setGeometry(QRect(690, 70, 61, 61));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 170, 60, 16));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(820, 160, 60, 16));
        verticalSlider = new QSlider(frame);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(230, 20, 16, 160));
        verticalSlider->setOrientation(Qt::Vertical);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(650, 10, 261, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        hostname = new QLineEdit(gridLayoutWidget);
        hostname->setObjectName(QStringLiteral("hostname"));

        gridLayout->addWidget(hostname, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        port = new QLineEdit(gridLayoutWidget);
        port->setObjectName(QStringLiteral("port"));

        gridLayout->addWidget(port, 1, 1, 1, 1);

        btnConnect = new QPushButton(centralWidget);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setGeometry(QRect(690, 100, 161, 32));
        btnDeconnect = new QPushButton(centralWidget);
        btnDeconnect->setObjectName(QStringLiteral("btnDeconnect"));
        btnDeconnect->setGeometry(QRect(690, 140, 161, 32));
        camera = new QWebEngineView(centralWidget);
        camera->setObjectName(QStringLiteral("camera"));
        camera->setGeometry(QRect(10, 0, 631, 481));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 917, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        s->setText(QApplication::translate("MainWindow", "S", nullptr));
        q->setText(QApplication::translate("MainWindow", "Q", nullptr));
        z->setText(QApplication::translate("MainWindow", "Z", nullptr));
        d->setText(QApplication::translate("MainWindow", "D", nullptr));
        haut->setText(QString());
        bas->setText(QString());
        droite->setText(QString());
        gauche->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "v\303\251hicule", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "cam\303\251ra", nullptr));
        hostname->setText(QApplication::translate("MainWindow", "192.168.1.106", nullptr));
        label->setText(QApplication::translate("MainWindow", "Addresse IP :", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Port :", nullptr));
        port->setText(QApplication::translate("MainWindow", "15020", nullptr));
        btnConnect->setText(QApplication::translate("MainWindow", "Connexion", nullptr));
        btnDeconnect->setText(QApplication::translate("MainWindow", "Deconnexion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
