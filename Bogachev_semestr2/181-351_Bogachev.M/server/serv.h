#pragma once
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
	// QMap<int,QTcpSocket *> SClients; 
};
