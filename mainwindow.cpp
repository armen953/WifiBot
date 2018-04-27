#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QMainWindow::setFocus();
    ui->setupUi(this);
    this->ui->haut->setArrowType(Qt::UpArrow);
    this->ui->bas->setArrowType(Qt::DownArrow);
    this->ui->droite->setArrowType(Qt::RightArrow);
    this->ui->gauche->setArrowType(Qt::LeftArrow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnConnect_clicked()
{
    this->hostname = ui->hostname->text();
    this->port = ui->port->text().toInt();

    this->mySocket = new QTcpSocket(this);

    connect(mySocket, SIGNAL(connected()),this, SLOT(connected()));
    connect(mySocket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(mySocket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(mySocket, SIGNAL(readyRead()),this, SLOT(readyRead()));

    qDebug() << "connecting...";

    // this is not blocking call
    mySocket->connectToHost(this->hostname, this->port);

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
    mySocket->write("hello");
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
