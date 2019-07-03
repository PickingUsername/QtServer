#ifndef READSERVER_H
#define READSERVER_H

#include <QObject>
#include"server.h"
#include"data.h"

class ReadServer : public Server
{
    Q_OBJECT
public:
    explicit ReadServer(QObject *parent = nullptr);
    void handleCMD(Data& data);

signals:

public slots:
    void handlePackage();

private:
};

#endif // READSERVER_H
