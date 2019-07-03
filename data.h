#ifndef DATA_H
#define DATA_H

#include <QObject>
#include<vector>

class Data : public QObject
{
    Q_OBJECT
public:
    explicit Data(const qint32& dataLength=0,const qint32& destID=0,
                  const qint32& srcID=0,const QString& cmd="NULL",
                  const QString& content="NULL",QObject *parent = nullptr);
    QString getCMD();
    QString getContent();

signals:

public slots:

private:
    qint32* _dataLength;//数据总大小
    qint32* _destID;//目的ID
    qint32* _srcID;//源ID

    QString* _cmd;//请求命令
    QString* _content;//消息内容
};

#endif // DATA_H
