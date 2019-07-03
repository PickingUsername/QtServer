#include "server.h"

QHash<qint64,QSharedPointer<ClientSocket>>* Server::_tempClients = new QHash<qint64,QSharedPointer<ClientSocket>>;
QHash<QString,QSharedPointer<ClientSocket>>* Server::_clients = new QHash<QString,QSharedPointer<ClientSocket>>;
QQueue<QSharedPointer<ClientSocket>>* Server::_readyReadSockets = new QQueue<QSharedPointer<ClientSocket>>;
QByteArray* Server::_sendDate = new QByteArray;

QWaitCondition* Server::_tempClientsWaitCondition = new QWaitCondition;
QMutex* Server::_tempClientsMutex = new QMutex;

QWaitCondition* Server::_readyReadSocketCondition = new QWaitCondition;
QMutex* Server::_readyReadSocketMutex = new QMutex;


Server::Server(QObject *parent) : QObject(parent)
{

}

Server::~Server(){
    delete _tempClients;
    delete _clients;
    delete _readyReadSocket;
    delete _sendDate;

    _tempClients = nullptr;
    _clients = nullptr;
    _readyReadSocket = nullptr;
    _sendDate = nullptr;
}
