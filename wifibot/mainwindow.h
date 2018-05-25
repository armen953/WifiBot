#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QKeyEvent>

#include "wifibotcontroller.h"
#include "direction.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void keyPressEvent(QKeyEvent *event);
     void keyReleaseEvent(QKeyEvent *event);


private slots:
    void on_btnConnect_clicked();
    void on_btnDeconnect_clicked();


    void on_z_pressed();

    void on_z_released();

    void on_d_pressed();

    void on_d_released();

    void on_s_pressed();

    void on_s_released();

    void on_q_pressed();

    void on_q_released();

private:
    Ui::MainWindow *ui;
    WifiBotController* wifibotcontroller;
    QString hostname;
    int port;
};

#endif // MAINWINDOW_H
