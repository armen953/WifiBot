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

    buffer.clear();
    buffer.append(255);//char1 is 255
    buffer.append(0x07);//char2 is 0x07
    buffer.append(240);//char3 & char4 are the leftspeed control
    buffer.append(1);//char4
    buffer.append(120);//char5 & char6 are the rightspeed control
    buffer.append(1);//char6
    buffer.append(0b01010000);//char 7


    //Calcul du CRC
    unsigned short crc = Crc16((unsigned char* )buffer.constData(), buffer.length());
    buffer.append(crc); //8
    buffer.append((crc>>8)); //9

    qDebug() << buffer;
    mySocket->write(buffer);
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
    mySocket->disconnectFromHost();
}




//Calcul du Crc16
short MainWindow::Crc16(unsigned char *Adresse_tab , unsigned char Taille_max)
{
    unsigned int Crc = 0xFFFF;
    unsigned int Polynome = 0xA001;
    unsigned int CptOctet = 0;
    unsigned int CptBit = 0;
    unsigned int Parity= 0;

    //On commence à 1 car il est déconseillé dans la documentation d'utiliser l'octet 255 que l'ont a au debut
    for (CptOctet = 1; CptOctet < Taille_max ; CptOctet++)
    {
        Crc ^= *( Adresse_tab + CptOctet);

        for ( CptBit = 0; CptBit <= 7 ; CptBit++)
        {
            Parity= Crc;
            Crc >>= 1;
            if (Parity%2 == true) Crc ^= Polynome;
        }
    }
    return(Crc);
}




