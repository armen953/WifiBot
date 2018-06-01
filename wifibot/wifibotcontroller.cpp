#include "wifibotcontroller.h"
#include "mainwindow.h"

/**
 * @brief Constructor of the class
 * @param parent
 */
WifiBotController::WifiBotController(QObject *parent) : QObject(parent)
{
    this->buffer = new QByteArray();
    this->isMovingForward = false;
    this->isMovingBack = false;
    this->isGoingLeft = false;
    this->isGoingRight = false;

    //timer for send buffer at regular interval
    timer = new QTimer(this);
    timer->setInterval(25);
    connect(timer, SIGNAL(timeout()),this,SLOT(sendData()));
}

/**
 * @brief Destructor (free the memory alocated)
 */
WifiBotController::~WifiBotController()
{
    delete buffer;
    delete timer;
    delete mySocket;
}

/**
 * @brief Attempt tcp connection with the wifibot
 * @param hostname: the ip adress of the host
 * @param port: the port number on witch the host is listening
 * @return a boolean which indicates if the connection is established
 */
bool WifiBotController::attemptConnection(QString hostname, int port)
{
    bool isConnected = false;
    this->mySocket = new QTcpSocket();

    qDebug() << "connecting...";

    // binding events
    connect(mySocket, SIGNAL(connected()),this, SLOT(whenConnected()));
    connect(mySocket, SIGNAL(disconnected()),this, SLOT(whenDisconnected()));
    connect(mySocket, SIGNAL(bytesWritten(qint64)),this, SLOT(whenBytesWritten(qint64)));
    connect(mySocket, SIGNAL(readyRead()),this, SLOT(whenReadyRead()));

    // this is not blocking call
    mySocket->connectToHost(hostname, port);

    // if we have no response in 5 sec then there is an error
    if(mySocket->waitForConnected(5000)){
        isConnected = true;
        this->timer->start();
    } else {
        isConnected = false;
        qDebug() << "Error: " << mySocket->errorString();
    }
    return isConnected;
}

/**
 * @brief WifiBotController::endConnection
 */
void WifiBotController::endConnection()
{
    this->mySocket->disconnectFromHost();
    this->timer->stop();
    this->buffer->clear();
}

void WifiBotController::moveWifibot(int direction, int leftspeed, int rightspeed)
{
    this->buffer->clear();
    this->buffer->append(255);        // Char1 (255)
    this->buffer->append(0x07);       // Char2 (0x07)
    this->buffer->append(leftspeed);  // Char3 leftspeed control
    this->buffer->append(1);          // Char4 leftspeed control
    this->buffer->append(rightspeed); // Char5 rightspeed control
    this->buffer->append(1);          // Char6 rightspeed control

//Char 7 is decomposed as follow (1 byte char -> 8 bits):
//  (128) Bit 7 Left  Side Closed Loop Speed control      :: 1 -> ON      / 0 -> OFF
//  (64)  Bit 6 Left  Side Forward / Backward speed flag  :: 1 -> Forward / 0 -> Reverse
//  (32)  Bit 5 Right Side Closed Loop Speed control      :: 1 -> ON      / 0 -> OFF
//  (16)  Bit 4 Right Side Forward / Backward speed flag  :: 1 -> Forward / 0 -> Reverse
//  (8)   Bit 3 Relay 4 On/Off (DSUB15 POWER Pin 13 and 14)
//  (4)   Bit 2 Relay 3 On/Off (DSUB15 POWER Pin 11 and 12)
//  (2)   Bit 1 Relay 2 On/Off (DSUB15 POWER Pin 4 and 5)
//  (1)   Bit 0 Relay 1 for Sensors. On/Off: 0 is OFF 1 is ON (DSUB15 POWER Pin 3)

    // for Char 7
    if (direction == Direction::up){//76543210
        this->buffer->append((char) 0b01010000); // up   101 (bit 6 et 4)
    } else if (direction == Direction::left){
        this->buffer->append((char) 0b00010000); // left  move only right wheels =>   01
    } else if (direction == Direction::back){
        this->buffer->append((char) 0b00000000); // back                              00
    } else if (direction == Direction::right){
        this->buffer->append((char) 0b01000000); // right  move only left wheels  =>  10
    }

    //Calcul CRC
    unsigned short crc = Crc16((unsigned char* )this->buffer->constData(), this->buffer->length());
    // Char 8-9 is the CRC 16 bits (char 8 low char 9 high)
    this->buffer->append(crc);        // Char8 (00000000 <-|    00000000)
    this->buffer->append((crc>>8));   // Char9 (00000000   | -> 00000000)

    //qDebug() << this->buffer; // show for debug

 //   this->mySocket->write(*this->buffer); // CHANGER ENDROIT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

/**
 * @brief A EFFACER (POUR TESTER) !!!!
 */
void WifiBotController::hello()
{
    qDebug() << "hello";
}

/**
 * @brief Event that happend the connection is established
 */
void WifiBotController::whenConnected()
{
    qDebug() << "connected";
}

/**
 * @brief Event that happend when disconnected from the host
 */
void WifiBotController::whenDisconnected()
{
    qDebug() << "disconnected...";
}

/**
 * @brief Event happend when Bytes are written through the socket
 * @param bytes
 */
void WifiBotController::whenBytesWritten(qint64 bytes)
{
    qDebug() << bytes << " bytes written...";
}

/**
 * @brief Event happend when reading on the socket
 */
void WifiBotController::whenReadyRead()
{
   qDebug() << "reading...";
   QByteArray recept = this->mySocket->readAll();
   this->updateBatterie((unsigned char)recept[2]);
   this->updateBackDist(recept[12], recept[4]); // backleft backright
   this->updateForwardDist(recept[3], recept[11]); // forwardleft forwardright

}

void WifiBotController::updateBatterie(unsigned char value)
{
    MainWindow* mv = MainWindow::getMainWinPtr();     // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! revoir
    int pbat = (value);
    qDebug() << value;
    mv->updateBatterieUi(pbat);

}

void WifiBotController::updateForwardDist(unsigned char leftDist, unsigned char rightDist)
{
    MainWindow* mv = MainWindow::getMainWinPtr();
    mv->updateDistanceForLeft((int)leftDist);
    mv->updateDistanceForRight((int)rightDist);
}

void WifiBotController::updateBackDist(unsigned char leftDist, unsigned char rightDist)
{
    MainWindow* mv = MainWindow::getMainWinPtr();
    mv->updateDistanceBackLeft((int)leftDist);
    mv->updateDistanceBackRight((int)rightDist);
}

/**
 * @brief Calculate the crc of a given buffer
 * @param Adresse_tab a pointer to the buffer
 * @param Taille_max the buffer length
 * @return calculed crc
 */
short WifiBotController::Crc16(unsigned char *Adresse_tab , unsigned char Taille_max)
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



void WifiBotController::sendData()
{
    MainWindow* mv = MainWindow::getMainWinPtr();
    if (this->isMovingForward && !this->isGoingLeft && !this->isMovingBack && !this->isGoingRight) {
        moveWifibot(Direction::up, mv->getVitesse(), mv->getVitesse());       // the car move forward
    } else if (this->isMovingBack && !this->isMovingForward && !this->isGoingLeft && !this->isGoingRight) {
        moveWifibot(Direction::back, mv->getVitesse(), mv->getVitesse());    // the car move back
    } else if (this->isGoingLeft && !this->isMovingForward && !this->isMovingBack && !this->isGoingRight) {
        moveWifibot(Direction::left, mv->getVitesse(), mv->getVitesse());   // the car move left
    } else if (this->isGoingRight && !this->isMovingForward && !this->isMovingBack && !this->isGoingLeft) {
        moveWifibot(Direction::right, mv->getVitesse(), mv->getVitesse());  // the car move right
    } else if (this->isMovingForward && this->isGoingLeft && !this->isGoingRight && !this->isMovingBack) {
        // the car move forward left

    } else if (this->isMovingForward && this->isGoingRight && !this->isGoingLeft && !this->isMovingBack) {
        // the car move forward right

    } else if (this->isMovingBack && this->isGoingLeft && !this->isGoingRight && this->isMovingForward) {
        // the car move back left

    } else if (this->isMovingBack && this->isGoingRight && !this->isGoingLeft && this->isMovingForward) {
        // the car move back right

    } else {
        moveWifibot(Direction::dontMove, 0, 0);  // the car dont move
    }

    this->mySocket->write(* this->buffer);

}

/*==================================================================
#                       Getters AND Setters                        #
===================================================================*/

QTcpSocket *WifiBotController::getMySocket() const
{
    return mySocket;
}

void WifiBotController::setMySocket(QTcpSocket *value)
{
    mySocket = value;
}

QString WifiBotController::getHostname() const
{
    return hostname;
}

void WifiBotController::setHostname(const QString &value)
{
    hostname = value;
}

int WifiBotController::getPort() const
{
    return port;
}

void WifiBotController::setPort(int value)
{
    port = value;
}

QByteArray *WifiBotController::getBuffer() const
{
    return buffer;
}

void WifiBotController::setBuffer(QByteArray *value)
{
    buffer = value;
}

bool WifiBotController::getIsMovingForward() const
{
    return isMovingForward;
}

void WifiBotController::setIsMovingForward(bool value)
{
    isMovingForward = value;
}

bool WifiBotController::getIsMovingBack() const
{
    return isMovingBack;
}

void WifiBotController::setIsMovingBack(bool value)
{
    isMovingBack = value;
}

bool WifiBotController::getIsGoingLeft() const
{
    return isGoingLeft;
}

void WifiBotController::setIsGoingLeft(bool value)
{
    isGoingLeft = value;
}

bool WifiBotController::getIsGoingRight() const
{
    return isGoingRight;
}

void WifiBotController::setIsGoingRight(bool value)
{
    isGoingRight = value;
}
