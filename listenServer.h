#ifndef READSERVER_H
#define READSERVER_H

#include <QObject>
#include<QTcpServer>
#include<QTcpSocket>
#include<QSharedPointer>
#include<QDebug>
#include"tcpserver.h"
#include"server.h"
#include"clientsocket.h"
#include"data.h"

class ListenServer : public Server
{
    Q_OBJECT
public:
    explicit ListenServer(QObject *parent,const QHostAddress& ip,const quint16& port);

signals:

public slots:
    void joinTempContainer(qintptr socketDescriptor);

private:
    QHostAddress _ip;
    quint16 _port;
    TcpServer* _listenSocket;

};

#endif // READSERVER_H
