#include "mytcpserver.h"
#include <QCoreApplication>

MyTcpServer::~MyTcpServer()
{

    mTcpServer->close();
    //server_status=0;
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        //server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
 //   if(server_status==1){
        QTcpSocket* val_socket;
        val_socket = mTcpServer->nextPendingConnection();
        val_socket->write("Hello, World!!! I am echo server!\r\n");
        connect(val_socket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
        connect(val_socket, &QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
        mTcpSocket.insert(val_socket->socketDescriptor(),val_socket);
   // }
}

void MyTcpServer::slotServerRead(){
    QString res = "";
    QTcpSocket* val_socket = mTcpSocket[((QTcpSocket*)sender())->socketDescriptor()];
    while(val_socket->bytesAvailable()>0)
    {
        QByteArray array =val_socket->readAll();
        qDebug()<<array<<"\n";
        if(array=="\x01")
        {
            val_socket->write(parse(res.toUtf8()));
            res = "";
        }
        else
            res.append(array);
    }

    val_socket->write(parse(res.toUtf8()));
}

void MyTcpServer::slotClientDisconnected(){
    int key = ((QTcpSocket*)sender())->socketDescriptor();
    mTcpSocket[key]->close();
    mTcpSocket.remove(key);
}
