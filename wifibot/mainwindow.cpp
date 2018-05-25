#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief Constructor of the class
 * @param parent
 */
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

    this->setWindowTitle("WIFIBOT MAHMEDOV PATRU");

    //center the window on the screen ceneter
    QRect position = frameGeometry();
    move(position.center());

    this->wifibotcontroller = new WifiBotController(this);
}

/**
 * @brief Destructor (free the memory alocated)
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete wifibotcontroller;
}

/**
 * @brief Event when a key is pressed
 * @param event the event
 */
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Z: // move forward
        //this->wifibotcontroller->moveWifibot(Direction::up,240,240);
        //this->wifibotcontroller->setIsMovingForward(true);

        ui->z->animateClick();
        // FAIRE ANIMATE CLICK OU APPELER LA FNC POUR PASSER A TRUE

        //qDebug() << this->wifibotcontroller->getIsMovingForward();
        break;

    case Qt::Key_Q:  // go left
        this->wifibotcontroller->setIsGoingLeft(true);
        this->wifibotcontroller->moveWifibot(Direction::left,240,240);
        break;

    case Qt::Key_S: // go back
        this->wifibotcontroller->setIsMovingBack(true);
        break;

    case Qt::Key_D: //go right
        this->wifibotcontroller->setIsGoingRight(true);
        break;

    case Qt::Key_Up: // up camera

        break;

    case Qt::Key_Down: // down camera

        break;

    case Qt::Key_Left: // move left camera

        break;

    case Qt::Key_Right: // move right camera

        break;
    }
}

/**
 * @brief Event when a key is released
 * @param event the event
 */
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Z:

        //qDebug() << this->wifibotcontroller->getIsMovingForward();
        break;
    case Qt::Key_Q:
        this->wifibotcontroller->setIsGoingLeft(false);
        break;
    case Qt::Key_S:
        this->wifibotcontroller->setIsMovingBack(false);
        break;
    case Qt::Key_D:
        this->wifibotcontroller->setIsGoingRight(true);
        break;
    }
}

//void MainWindow::displayWarningOnScreen(QString title, QString mgs)
//{
//     QMessageBox::warning(this, title, mgs, QMessageBox::Ok);
//}

/**
 * @brief Event when the connecion button is pressed
 */
void MainWindow::on_btnConnect_clicked()
{
    this->hostname = ui->hostname->text();
    this->port = ui->port->text().toInt();
    this->wifibotcontroller->hello();

    this->wifibotcontroller->attemptConnection(this->hostname, this->port);
}

/*
void MainWindow::whenConnected()
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
*/

/**
 * @brief Event when deconnect button is pressed
 */
void MainWindow::on_btnDeconnect_clicked()
{
    this->wifibotcontroller->endConnection();
}


void MainWindow::on_z_pressed()
{
    this->wifibotcontroller->setIsMovingForward(true);
    this->wifibotcontroller->sendData();
}

void MainWindow::on_q_pressed()
{
    this->wifibotcontroller->setIsGoingLeft(true);
}

void MainWindow::on_s_pressed()
{
    this->wifibotcontroller->setIsMovingBack(true);
}

void MainWindow::on_d_pressed()
{
    this->wifibotcontroller->setIsGoingRight(true);
}


void MainWindow::on_z_released()
{
    this->wifibotcontroller->setIsMovingForward(false);
}

void MainWindow::on_q_released()
{
    this->wifibotcontroller->setIsGoingLeft(false);
}

void MainWindow::on_s_released()
{
    this->wifibotcontroller->setIsMovingBack(false);
}

void MainWindow::on_d_released()
{
    this->wifibotcontroller->setIsGoingRight(false);
}
