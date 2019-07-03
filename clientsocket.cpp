#include "clientsocket.h"

ClientSocket::ClientSocket(QObject *parent) : Server(parent)
{
    _cmdBuff = new QString;
    _contentBuff = new QString;


}

void ClientSocket::onReadyRead(){
    _readyReadSocketMutex->lock();
    QSharedPointer<ClientSocket> sharedThis = this->sharedFromThis();

    _readyReadSocketCondition->wakeAll();
    _readyReadSocketMutex->unlock();
}

ClientSocket::~ClientSocket(){
    delete _clientSocket;
    _clientSocket = nullptr;
}

void ClientSocket::initSocket(qintptr socketDescriptor){
    _clientSocket = new QTcpSocket;
    _clientSocket->setSocketDescriptor(socketDescriptor);
    connect(_clientSocket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
}
