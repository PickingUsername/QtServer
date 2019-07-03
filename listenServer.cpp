#include "listenServer.h"

ListenServer::ListenServer(QObject *parent,const QHostAddress& ip,const quint16& port) : Server(parent)
{
    _listenSocket = new TcpServer(this);
    connect(_listenSocket,SIGNAL(connecting()),this,SLOT(joinTempContainer()));
    if(!_listenSocket->listen(ip,port)){
        qDebug()<<"监听失败!"<<endl;
    }
}

void ListenServer::joinTempContainer(qintptr socketDescriptor){
    QSharedPointer<ClientSocket> client(new ClientSocket());
    client->initSocket(socketDescriptor);


    //把客户端添加到临时客户端列表中，等待客户端发送其ID，再将其加入正式客户端列表
    _tempClientsMutex->lock();
    _tempClients->insert(socketDescriptor,client);
    _tempClientsWaitCondition->wakeAll();
    _tempClientsMutex->unlock();
}
