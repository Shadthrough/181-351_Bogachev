#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QVariant>

class MyTcpServer : public QObject
{
	Q_OBJECT
public:
	explicit MyTcpServer(QObject *parent = nullptr);
	~MyTcpServer();
	void add(std::string a);
	void edit(std::string a);
	void del(std::string a);
	void refresh(QTcpSocket * a);

public slots:
	void slotNewConnection();
	void slotClientDisconnected();
	void slotReadSocket();

private:
	QTcpServer * server;
	int server_status;
	QMap<int, QTcpSocket *> SClients;
};
#endif // MYTCPSERVER_H







/*#pragma once
//

#include <QObject> 
#include <QTcpServer> 
#include <QTcpSocket> 

class MyTcpServer : public QObject
{
	Q_OBJECT
public:
	explicit MyTcpServer(QObject *parent = nullptr);
	~MyTcpServer();

public slots:
	void slotNewConnection();
	void slotClientDisconnected();
	void slotServerRead();
private:
	QTcpServer *mTcpServer;
	QTcpSocket *mTcpSocket;

	int server_status;
	QMap<int,QTcpSocket *> SClients; 
};*/
