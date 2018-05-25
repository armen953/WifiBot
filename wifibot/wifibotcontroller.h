#ifndef WIFIBOTCONTROLLER_H
#define WIFIBOTCONTROLLER_H


#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QTimer>

#include "direction.h"

class WifiBotController: public QObject
{
    Q_OBJECT

public:
    explicit WifiBotController(QObject *parent = 0);
    ~WifiBotController();
    bool attemptConnection(QString hostname, int port);
    void endConnection();
    void moveWifibot(int direction, int leftspeed, int rightspeed);
    short Crc16(unsigned char *Adresse_tab , unsigned char Taille_max);

    void hello();

// getters and setters
    QTcpSocket *getMySocket() const;
    void setMySocket(QTcpSocket *value);

    QString getHostname() const;
    void setHostname(const QString &value);

    int getPort() const;
    void setPort(int value);

    QByteArray *getBuffer() const;
    void setBuffer(QByteArray *value);


    bool getIsMovingForward() const;
    void setIsMovingForward(bool value);
    bool getIsMovingBack() const;
    void setIsMovingBack(bool value);
    bool getIsGoingLeft() const;
    void setIsGoingLeft(bool value);
    bool getIsGoingRight() const;
    void setIsGoingRight(bool value);

private:
    int port;
    QString hostname;
    QTcpSocket* mySocket;
    QByteArray* buffer;
    QTimer* timer;
    // bool for know what the robot is doing
    bool isMovingForward;
    bool isMovingBack;
    bool isGoingLeft;
    bool isGoingRight;

private slots:
    void whenConnected();
    void whenDisconnected();
    void whenBytesWritten(qint64 bytes);
    void whenReadyRead();
public slots:
    void sendData();

};

#endif // WIFIBOTCONTROLLER_H
