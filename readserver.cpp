#include "readserver.h"

ReadServer::ReadServer(QObject *parent) : Server(parent)
{

}

void ReadServer::handlePackage(){


}

void ReadServer::handleCMD(Data& data){
    if("Login" == data.getCMD()){

    }
    else if("Logout" == data.getCMD()){

    }

}
