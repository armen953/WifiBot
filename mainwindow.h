#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnConnect_clicked();

    void on_btnDeconnect_clicked();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void connected();
    void disconnected();
    short Crc16(unsigned char *Adresse_tab , unsigned char Taille_max);




private:
    Ui::MainWindow *ui;
    QTcpSocket * mySocket;
    QString hostname;
    int port;
    QByteArray buffer;
};

#endif // MAINWINDOW_H
