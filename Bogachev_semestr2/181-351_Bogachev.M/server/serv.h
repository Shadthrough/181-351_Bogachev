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
#include "crypto.h"

class MyTcpServer : public QObject
{
	Q_OBJECT
public:
	explicit MyTcpServer(QObject *parent = nullptr);
	~MyTcpServer();
	void add(std::string a, int desc);
	void edit(std::string a, int desc);
	void del(std::string a, int desc);
	void refresh(QTcpSocket * a);
	void Uadd(std::string a, int desc);
	void Uedit(std::string a, int desc);
	void Udel(std::string a, int desc);
	void Urefresh(QTcpSocket * a);
	void Ucheck(std::string a, QTcpSocket * sock);

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
