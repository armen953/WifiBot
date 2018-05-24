#ifndef WIFIBOTCONTROLLER_H
#define WIFIBOTCONTROLLER_H


#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

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

private:
    int port;
    QString hostname;
    QTcpSocket* mySocket;
    QByteArray* buffer;

private slots:
    void whenConnected();
    void whenDisconnected();
    void whenBytesWritten(qint64 bytes);
    void whenReadyRead();
};

#endif // WIFIBOTCONTROLLER_H
