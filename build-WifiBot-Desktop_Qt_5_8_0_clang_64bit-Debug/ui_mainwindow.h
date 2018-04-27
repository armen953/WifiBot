/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

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
    QPushButton *btnConnect;
    QPushButton *btnDeconnect;
    QToolButton *haut;
    QToolButton *bas;
    QToolButton *droite;
    QToolButton *gauche;
    QLineEdit *hostname;
    QLineEdit *port;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *frame_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(835, 762);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 500, 811, 201));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        s = new QPushButton(frame);
        s->setObjectName(QStringLiteral("s"));
        s->setGeometry(QRect(70, 110, 61, 61));
        q = new QPushButton(frame);
        q->setObjectName(QStringLiteral("q"));
        q->setGeometry(QRect(20, 60, 61, 61));
        z = new QPushButton(frame);
        z->setObjectName(QStringLiteral("z"));
        z->setGeometry(QRect(70, 10, 61, 61));
        d = new QPushButton(frame);
        d->setObjectName(QStringLiteral("d"));
        d->setGeometry(QRect(120, 60, 61, 61));
        btnConnect = new QPushButton(frame);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setGeometry(QRect(320, 110, 113, 32));
        btnDeconnect = new QPushButton(frame);
        btnDeconnect->setObjectName(QStringLiteral("btnDeconnect"));
        btnDeconnect->setGeometry(QRect(320, 140, 113, 32));
        haut = new QToolButton(frame);
        haut->setObjectName(QStringLiteral("haut"));
        haut->setGeometry(QRect(620, 10, 61, 61));
        bas = new QToolButton(frame);
        bas->setObjectName(QStringLiteral("bas"));
        bas->setGeometry(QRect(620, 130, 61, 61));
        droite = new QToolButton(frame);
        droite->setObjectName(QStringLiteral("droite"));
        droite->setGeometry(QRect(680, 70, 61, 61));
        gauche = new QToolButton(frame);
        gauche->setObjectName(QStringLiteral("gauche"));
        gauche->setGeometry(QRect(560, 70, 61, 61));
        hostname = new QLineEdit(frame);
        hostname->setObjectName(QStringLiteral("hostname"));
        hostname->setGeometry(QRect(320, 10, 113, 21));
        port = new QLineEdit(frame);
        port->setObjectName(QStringLiteral("port"));
        port->setGeometry(QRect(320, 40, 113, 21));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 10, 91, 20));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(270, 40, 41, 16));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 170, 60, 16));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(690, 160, 60, 16));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 10, 641, 481));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 835, 22));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        s->setText(QApplication::translate("MainWindow", "S", Q_NULLPTR));
        q->setText(QApplication::translate("MainWindow", "Q", Q_NULLPTR));
        z->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        d->setText(QApplication::translate("MainWindow", "D", Q_NULLPTR));
        btnConnect->setText(QApplication::translate("MainWindow", "Connexion", Q_NULLPTR));
        btnDeconnect->setText(QApplication::translate("MainWindow", "Deconnexion", Q_NULLPTR));
        haut->setText(QString());
        bas->setText(QString());
        droite->setText(QString());
        gauche->setText(QString());
        hostname->setText(QApplication::translate("MainWindow", "192.168.1.106", Q_NULLPTR));
        port->setText(QApplication::translate("MainWindow", "15020", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Addresse IP :", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Port :", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "v\303\251hicule", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "cam\303\251ra", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
