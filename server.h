#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include<QVector>
#include<QHash>
#include<QQueue>
#include<QTcpSocket>
#include<QSharedPointer>
#include<QThread>
#include<QMutex>
#include<QWaitCondition>
//#include"clientsocket.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    virtual ~Server();

signals:

public slots:

protected:
    //临时客户端容器
    static QHash<qint64,QSharedPointer<ClientSocket>>* _tempClients;
    //客户端容器
    static QHash<QString,QSharedPointer<ClientSocket>>* _clients;
    //可读客户端队列
    static QQueue<QSharedPointer<ClientSocket>>* _readyReadSockets;
    //待发送数据缓冲区
    static QByteArray* _sendDate;



    //临时客户端容器条件变量
    static QWaitCondition* _tempClientsWaitCondition;
    //临时客户端容器互斥锁
    static QMutex* _tempClientsMutex;
    //可读客户端队列条件变量
    static QWaitCondition* _readyReadSocketCondition;
    //可读客户端队列互斥锁
    static QMutex* _readyReadSocketMutex;
private:

};

#endif // SERVER_H
