#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent,const QHostAddress& ip,const quint16& port) : QTcpServer(parent)
{
    if(!this->listen(ip,port)){
        qDebug()<<"监听失败!"<<endl;
    }
}

void TcpServer::incomingConnection(qintptr socketDescriptor){
    emit this->connecting(socketDescriptor);
}
