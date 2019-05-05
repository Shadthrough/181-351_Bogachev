#include "serv.h"
#include <QDebug>
#include <QCoreApplication>
#include <Qstring>

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent) {
	mTcpServer = new QTcpServer(this);
	connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

	if (!mTcpServer->listen(QHostAddress::Any, 33333)) {
		qDebug() << "server is not started";
	}
	else {
		server_status = 1;
		qDebug() << "server is started";
	}
}

void MyTcpServer::slotNewConnection() {
	if (server_status == 1) {
		QTcpSocket* clientSocket = mTcpServer->nextPendingConnection();
		int id_user_socs = (int)clientSocket->socketDescriptor();
		SClients[id_user_socs] = clientSocket;
		SClients[id_user_socs]->write("Hello!\n");
		connect(SClients[id_user_socs], &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
		connect(SClients[id_user_socs], &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
	}
}

void MyTcpServer::slotServerRead() {
	QTcpSocket *clientSocket = (QTcpSocket*)sender();
	int id = (int)clientSocket->socketDescriptor();
	while (clientSocket->bytesAvailable() > 0)
	{
		QByteArray array = clientSocket->readAll();
		/*std::string log = "";
		//std::string pass = "";*/
		std::string message;
		message = array.toStdString();
		qDebug() << QString::fromStdString(message);
		message.find('::');


		/*// <name_of_function>&<log>&<pass>

			//find name_of_function;
		//int pos = message.find("&");
		//name_of function = message.substr(0,pos);
		//message.erase(0, pos + 1);

		//find login:
		//pos = message.find("&");
		//log = message.substr(0, pos);
		//message.erase(0, pos + 1);

		//find login:
		/*pos = message.find("&");
		pass = message.substr(0, pos);
		message.erase(0, pos + 1);*/
		/*
				//Пока работаем с putty убираем "лишние" символы
				pass.pop_back();
				pass.pop_back();
		*/
		/*qDebug() << "login = " << QString::fromStdString(log)
			<< " password = " << QString::fromStdString(pass)
			<< " result = " << authorize(log, pass);

		array.clear();
		array.append(authorize(log, pass));

		clientSocket->write(array);*/
	}
}

MyTcpServer::~MyTcpServer()
{
	foreach(int i, SClients.keys()) {
		QTextStream os(SClients[i]);
		SClients[i]->close();
		SClients.remove(i);
	}
	server_status = 0;
	mTcpServer->close();
}

void MyTcpServer::slotClientDisconnected() {
	QTcpSocket *clientSocket = (QTcpSocket*)sender();
	int id = (int)clientSocket->socketDescriptor();
	clientSocket->close();
	SClients.remove(id);
	qDebug() << QString::fromUtf8("Client is disconnected \n");
}

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

/*///////////////////////////////////////////////////////////////////////// OLD
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
	os « "";*//*
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
*/