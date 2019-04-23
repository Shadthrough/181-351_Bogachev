#include "serv.h"

//myserver::myserver() {}
//
//myserver::~myserver() {}
//
//void myserver::startServer()
//{
//	if (this->listen(QHostAddress::Any, 5555))
//	{
//		qDebug() << "Listening";
//	}
//	else
//	{
//		qDebug() << "Not listening";
//	}
//}
//
//void myserver::incomingConnection(int socketDescriptor)
//{
//	socket = new QTcpSocket(this);
//	socket->setSocketDescriptor(socketDescriptor);
//
//	connect(socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
//	connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));
//
//	qDebug() << socketDescriptor << " Client connected";
//
//	socket->write("You are connected");
//	qDebug() << "Send client connect status - YES";
//}
//
//void myserver::sockReady()
//{
//
//}
//
//void myserver::sockDisc()
//{
//	qDebug() << "Disconnect";
//	socket->deleteLater();
//}


#include <QDebug> 

MyTcpServer::~MyTcpServer()
{
	server_status = 0;
}

MyTcpServer::MyTcpServer(QObject *parent) :QObject(parent) {
	mTcpServer = new QTcpServer(this);

	connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

	if (!mTcpServer->listen(QHostAddress::Any, 33333) && server_status == 0) {
		qDebug() << "server isn't started";
	}
	else {
		server_status = 1;
		qDebug() << "server is started";
	}
}

void MyTcpServer::slotServerRead() {
	QByteArray array;
	//char temp; 
	while (mTcpSocket->bytesAvailable() > 0) {
		array = mTcpSocket->readAll();
		// temp = *array.data(); 
		// temp++; 
	}
	mTcpSocket->write(array);
	// QByteArray::fromStdString((std::string)&temp) 
	/* QTextStream os(mTcpSocket);
	os.setAutoDetectUnicode(true);
	os « "";*/
}

void MyTcpServer::slotNewConnection() {
	if (server_status == 1) {
		mTcpSocket = mTcpServer->nextPendingConnection();
		mTcpSocket->write("Hello, World!" "I'm echo server!\r\n");
		connect(mTcpSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
		connect(mTcpSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
	}
}

void MyTcpServer::slotClientDisconnected() {
	if (server_status == 1) {
		mTcpSocket->close();
		qDebug() << QString::fromUtf8("stop");
		server_status = 0;
	}
}
