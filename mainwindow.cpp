#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnConnect_clicked()
{

    this->mySocket = new QTcpSocket(this);

    connect(mySocket, SIGNAL(connected()),this, SLOT(connected()));
    connect(mySocket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(mySocket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(mySocket, SIGNAL(readyRead()),this, SLOT(readyRead()));

    qDebug() << "connecting...";

    // this is not blocking call
    mySocket->connectToHost("https://www.google.com", 80);

    // we need to wait...
    if(!mySocket->waitForConnected(5000))
    {
        qDebug() << "Error: " << mySocket->errorString();
    }
}

void MainWindow::connected()
{
    qDebug() << "connected...";

    // Hey server, tell me about you.
    mySocket->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");
}

void MainWindow::disconnected()
{
    qDebug() << "disconnected...";
}

void MainWindow::bytesWritten(qint64 bytes)
{
    qDebug() << bytes << " bytes written...";
}

void MainWindow::readyRead()
{
    qDebug() << "reading...";

    // read the data from the socket
    qDebug() << mySocket->readAll();
}


void MainWindow::on_btnDeconnect_clicked()
{

}
