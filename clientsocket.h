#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QObject>
#include<QTcpSocket>
#include<QDataStream>
#include <QEnableSharedFromThis>
#include"server.h"

class ClientSocket :public Server,public QEnableSharedFromThis<ClientSocket>
{
    Q_OBJECT
public:
    explicit ClientSocket(QObject *parent = nullptr);
    virtual ~ClientSocket();

    void initSocket(qintptr socketDescriptor);

signals:

public slots:
    void onReadyRead();

private:
    qint32 _dataLength = 0;
    qint32 _destID;//目的ID
    qint32 _srcID;//源ID

    QString* _cmdBuff;//请求命令
    QString* _contentBuff;

    QTcpSocket* _clientSocket = nullptr;
};
#endif // CLIENTSOCKET_H
