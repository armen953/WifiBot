#include "wifibotcontroller.h"

/**
 * @brief Constructor of the class
 * @param parent
 */
WifiBotController::WifiBotController(QObject *parent) : QObject(parent)
{
    this->buffer = new QByteArray();
}

/**
 * @brief Destructor (free the memory alocated)
 */
WifiBotController::~WifiBotController()
{
    delete buffer;
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
    } else {
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
        this->buffer->append((char) 0b00010000); // left
    } else if (direction == Direction::back){
        this->buffer->append((char) 0b00000000); // back
    } else if (direction == Direction::right){
        this->buffer->append((char) 0b01000000); // right
    }

    //Calcul CRC
    unsigned short crc = Crc16((unsigned char* )this->buffer->constData(), this->buffer->length());
    // Char 8-9 is the CRC 16 bits (char 8 low char 9 high)
    this->buffer->append(crc);        // Char8 (00000000 <-|    00000000)
    this->buffer->append((crc>>8));   // Char9 (00000000   | -> 00000000)

    qDebug() << this->buffer; // show for debug



    this->mySocket->write(*this->buffer); // CHANGER ENDROIT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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

    this->buffer->clear();
    this->buffer->append(255);//char1 is 255
    this->buffer->append(0x07);//char2 is 0x07
    this->buffer->append(240);//char3 & char4 are the leftspeed control
    this->buffer->append(1);//char4
    this->buffer->append(120);//char5 & char6 are the rightspeed control
    this->buffer->append(1);//char6
    this->buffer->append(0b01010000);//char 7


    //Calcul du CRC
    unsigned short crc = Crc16((unsigned char* )this->buffer->constData(), this->buffer->length());
    this->buffer->append(crc); //8
    this->buffer->append((crc>>8)); //9

    qDebug() << this->buffer;
    this->mySocket->write(*this->buffer);
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

    // read the data from the socket
    qDebug() << mySocket->readAll();
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


