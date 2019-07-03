#include "data.h"

Data::Data(const qint32& dataLength,const qint32& destID,
           const qint32& srcID,const QString& cmd,
           const QString& content,QObject *parent) : QObject(parent)
{
    //new出成员变量
    _dataLength = new qint32;
    _destID = new qint32;
    _srcID = new qint32;
    _cmd = new QString;
    _content = new QString;

    //给成员变量赋初值
    *_dataLength = dataLength;
    *_destID = destID;
    *_srcID = srcID;
    *_cmd = cmd;
    *_content = content;
}

QString Data::getCMD(){
    return *_cmd;
}

QString Data::getContent(){
    return *_content;
}
