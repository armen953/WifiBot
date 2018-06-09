#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QKeyEvent>
#include <QNetworkAccessManager>
#include <QFileDialog>

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
     void disableInterface();
     void enableInterface();
     static MainWindow* getMainWinPtr();
     void updateBatterieUi(unsigned char value);
     int getVitesse();
     void updateDistanceForLeft(int value);
     void updateDistanceForRight(int value);
     void updateDistanceBackLeft(int value);
     void updateDistanceBackRight(int value);
     Ui::MainWindow *getUi() const;

private slots:
    void on_btnConnect_clicked();
    void on_btnDeconnect_clicked();
    void setValueToTheLabel(int value);

    void on_z_pressed();
    void on_z_released();
    void on_d_pressed();
    void on_d_released();
    void on_s_pressed();
    void on_s_released();
    void on_q_pressed();
    void on_q_released();

    void on_haut_clicked();
    void on_gauche_clicked();
    void on_bas_clicked();
    void on_droite_clicked();

    void on_capture_clicked();

private:
    Ui::MainWindow *ui;
    WifiBotController* wifibotcontroller;
    QString hostname;
    int port;
    QNetworkAccessManager *cameraControl;

    QString battrieSafeColor = "QProgressBar::chunk {background: green;}";
    QString battrieOrange = "QProgressBar::chunk {background: orange;}";
    QString battrieDangerColor = "QProgressBar::chunk {background: red;}";

    static MainWindow * pMainWindow;
};

#endif // MAINWINDOW_H
