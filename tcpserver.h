#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include<QTcpServer>
#include<QTcpSocket>
#include<QSharedPointer>
#include<QDebug>
#include"server.h"
#include"clientsocket.h"
#include"data.h"

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr,const QHostAddress& ip= QHostAddress::Any,const quint16& port =6666);

signals:
    void connecting(qintptr socketDescriptor);

public slots:

private:
    QHostAddress _ip;
    quint16 _port;

protected:
    virtual void incomingConnection(qintptr socketDescriptor) override;
};

#endif // TCPSERVER_H
