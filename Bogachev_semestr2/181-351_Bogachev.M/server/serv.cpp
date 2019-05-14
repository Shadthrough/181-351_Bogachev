//#define Q_FOREACH
#include "serv.h"
#include <QCoreApplication>
#include <Qstring>


MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent) {
	server = new QTcpServer(this);
	connect(server, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

	if (!server->listen(QHostAddress::Any, 33333)) 
	{
		qDebug() << "server is not started";
	}
	else 
	{
		server_status = 1;
		qDebug() << "server is started";
	}


	/*QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("DataBase");
	if (!db.open())
		qDebug() << db.lastError().text();

	QSqlQuery query(db);
	//создали таблицу
	query.exec("CREATE TABLE Pricelist("
		"ID INT NOT NULL, "
		"Train INT NOT NULL,"
		"Price MONEY NOT NULL,"
		"Company VARCHAR (20) NOT NULL,"
		"Status VARCHAR(10) NOT NULL"
		")");

	query.exec("INSERT INTO Pricelist(id, train, price, company, status) "
		"VALUES (:id, :train, :price, :company, :status)");

	query.bindValue(":id", "12");
	query.bindValue(":train", "177");
	query.bindValue(":price", "1200");
	query.bindValue(":company", "Google");
	query.bindValue(":status", "Sold");
	query.exec();
	//query.exec("DROP TABLE Pricelist");
	db.close();
	//qDebug() << "You suck";*/
	//std::string str = "3:12:123:SR:Sold";
	//add(str, 0);
}

void MyTcpServer::refresh(QTcpSocket * a)
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("DataBase");

	if (db.open())
		qDebug() << "db is open";

	QSqlQuery query(db);
	//query.exec("CREATE TABLE Pricelist(ID INT NOT NULL, Train INT NOT NULL, Price MONEY NOT NULL, Company VARCHAR(20) NOT NULL, Status VARCHAR(10))");
	//query.exec("INERT INTO Priselist VALUES (1, 125, 200, SR, Sold)");
	QByteArray data;
	query.exec("SELECT * FROM Pricelist");
	data.clear();
	while (query.next())
	{
		data.append("ID:");
		data.append(query.value(0).toByteArray());
		data.append(",:");
		data.append(query.value(1).toByteArray());
		data.append(",:");
		data.append(query.value(2).toByteArray());
		data.append(",:");
		data.append(query.value(3).toByteArray());
		data.append(",:");
		data.append(query.value(4).toByteArray());
		data.append("\n");
	}
	if (data.isEmpty())
		data = "I was empty(((";
	data.append('|');
	a->write(data);
}

void MyTcpServer::slotNewConnection() 
{
	if (server_status == 1) 
	{
		QTcpSocket* clientSocket = server->nextPendingConnection();
		int id_user_socs = (int)clientSocket->socketDescriptor();
		SClients[id_user_socs] = clientSocket;
		//SClients[id_user_socs]->write("Hello!\n");
		connect(SClients[id_user_socs], &QTcpSocket::readyRead, this, &MyTcpServer::slotReadSocket);/////////DO A KOSTIL' FOR REDIRECTION
		connect(SClients[id_user_socs], &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
		qDebug() << id_user_socs << "Client connected";
	}
}

void MyTcpServer::slotReadSocket() 
{
	QTcpSocket *clientSocket = (QTcpSocket*)sender();
	int id = (int)clientSocket->socketDescriptor();
	while (clientSocket->bytesAvailable() > 0)
	{
		QByteArray array = clientSocket->readAll();
		std::string message;
		message = array.toStdString();
		qDebug() << QString::fromStdString(message);
		std::string func = message.substr(0, message.find('|'));
		std::string str;
		if (func == "add")
		{
			message.erase(0, message.find('|') + 1);
			add(message, id);
		}
		else if (func == "delete")
		{
			message.erase(0, message.find('|') + 1);
			del(message, id);
		}
		else if (func == "edit")
		{
			message.erase(0, message.find('|') + 1);
			edit(message, id);
		}		//else if (func == "findtext")
		//	find_text(message.erase(0, message.find('|') + 1));
		//else if (func == "find")
		//	find(message.erase(0, message.find('|') + 1));
		else if (func == "refresh")
			refresh(clientSocket);
		//else if (func == "showusers")
		//	showUsers
		//else
		//	retrn;///////

		/*<name_of_function>&<log>&<pass>

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
	//QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	//db.close();///////////////////////////////////////////////////////////////////////////////////////////////
	foreach (int i, SClients.keys()) 
	{
		QTextStream os(SClients[i]);
		SClients[i]->close();
		SClients.remove(i);
	}
	server_status = 0;
	server->close();
}

void MyTcpServer::slotClientDisconnected() 
{
	QTcpSocket *clientSocket = (QTcpSocket*)sender();
	int id = (int)clientSocket->socketDescriptor();
	SClients.remove(id);
	qDebug() << "Client " << id << " has disconnected";
	clientSocket->close();
}

/*------------------Add----------------------;*/
void MyTcpServer::add(std::string a, int desc)
{
	QString id, train, price, comp, stat;
	id = QString::fromStdString(a.substr(0, a.find(':')));
	a.erase(0, a.find(":") + 1);
	train = QString::fromStdString(a.substr(0, a.find(':')));
	a.erase(0, a.find(":") + 1);
	price = QString::fromStdString(a.substr(0, a.find(':')));
	a.erase(0, a.find(":") + 1);
	comp = QString::fromStdString(a.substr(0, a.find(':')));
	a.erase(0, a.find(":") + 1);
	stat = QString::fromStdString(a);
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("DataBase");
	if (!db.open())
		qDebug() << db.lastError().text();

	QSqlQuery query(db);
	query.exec("CREATE TABLE Pricelist("
		"ID INT NOT NULL, "
		"Train INT NOT NULL,"
		"Price MONEY NOT NULL,"
		"Company VARCHAR (20) NOT NULL,"
		"Status VARCHAR(10) NOT NULL"
		")");

	query.prepare("INSERT INTO Pricelist(id, train, price, company, status) "
		"VALUES (:id, :train, :price, :company, :status)");

	query.bindValue(":id", id);
	query.bindValue(":train", train);
	query.bindValue(":price", price);
	query.bindValue(":company", comp);
	query.bindValue(":status", stat);
	query.exec();
	//query.exec("DROP TABLE Pricelist");
	db.close();
	//qDebug() << "You suck";*/
	refresh(SClients[desc]);
}

/*-------------------------Edit--------------------------*/
void MyTcpServer::edit(std::string a, int desk)
{
	QString id, train, price, comp, stat;
	id = QString::fromStdString(a.substr(0, a.find(':')));
	a.erase(0, a.find(":") + 1);
	train = QString::fromStdString(a.substr(0, a.find(':')));
	a.erase(0, a.find(":") + 1);
	price = QString::fromStdString(a.substr(0, a.find(':')));
	a.erase(0, a.find(":") + 1);
	comp = QString::fromStdString(a.substr(0, a.find(':')));
	a.erase(0, a.find(":") + 1);
	stat = QString::fromStdString(a);
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("DataBase");
	if (!db.open())
		qDebug() << db.lastError().text();

	QSqlQuery query(db);
	query.exec("CREATE TABLE Pricelist("
		"ID INT NOT NULL, "
		"Train INT NOT NULL,"
		"Price MONEY NOT NULL,"
		"Company VARCHAR (20) NOT NULL,"
		"Status VARCHAR(10) NOT NULL"
		")");

	query.prepare("UPDATE Pricelist SET train = :train WHERE id = :id");
	query.bindValue(":id", id);
	query.bindValue(":train", train);
	query.exec();
	query.prepare("UPDATE Pricelist SET price = :price WHERE id = :id");
	query.bindValue(":id", id);
	query.bindValue(":price", price);
	query.exec();
	query.prepare("UPDATE Pricelist SET company = :company WHERE id = :id");
	query.bindValue(":id", id);
	query.bindValue(":company", comp);
	query.exec();
	query.prepare("UPDATE Pricelist SET status = :status WHERE id = :id");
	query.bindValue(":id", id);
	query.bindValue(":status", stat);
	query.exec();
	//query.exec("DROP TABLE Pricelist");
	db.close();
	//qDebug() << "You suck";*/
	refresh(SClients[desk]);
}//*/

/*------------------------Delete-------------------------*/
void MyTcpServer::del(std::string a, int desc)
{
	QString id = QString::fromStdString(a);
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("DataBase");
	if (!db.open())
		qDebug() << db.lastError().text();

	QSqlQuery query(db);
	query.exec("CREATE TABLE Pricelist("
		"ID INT NOT NULL, "
		"Train INT NOT NULL,"
		"Price MONEY NOT NULL,"
		"Company VARCHAR (20) NOT NULL,"
		"Status VARCHAR(10) NOT NULL"
		")");

	query.prepare("DELETE FROM Pricelist WHERE id = :id");
	query.bindValue(":id", id);
	query.exec();
	//query.exec("DROP TABLE Pricelist");
	db.close();
	//qDebug() << "You suck";*/
	refresh(SClients[desc]);
}//*/

/*-----------------FindText------------------------
void db::on_findsubmb_clicked()
{
	bool not_found;
	for (int i = 0; i < daba.size(); i++)
	{
		if (daba[i].ride != ui.findl->text()
			&& daba[i].price != ui.findl->text()
			&& daba[i].comp != ui.findl->text()
			&& daba[i].sold != ui.findl->text())
		{
			daba.erase(daba.begin() + i);
			i--;
		}
	}
	if (daba.empty())
		QMessageBox::critical(this, "Alert", "No matches found.");
	else
		showdb(daba);
	daba.clear();
	setdb("DataBase.txt");
}*/

/*------------------Find--------------------------------
void db::on_findsubmb_2_clicked()
{
	bool not_found;
	for (int i = 0; i < daba.size(); i++)
	{
		if ((daba[i].ride != ui.trainel_2->text() && ui.trainel_2->text() != "")
			|| (daba[i].price != ui.pricel_2->text() && ui.pricel_2->text() != "")
			|| (daba[i].comp != ui.compel_2->text() && ui.compel_2->text() != "")
			|| (daba[i].sold != ui.soldel_2->text() && ui.soldel_2->text() != ""))
		{
			daba.erase(daba.begin() + i);
			i--;
		}
	}
	if (daba.empty())
		QMessageBox::critical(this, "Alert", "No matches found.");
	else
		showdb(daba);
	daba.clear();
	setdb("DataBase.txt");
}*/




/*
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

///////////////////////////////////////////////////////////////////////// OLD
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
	QTextStream os(mTcpSocket);
	os.setAutoDetectUnicode(true);
	os « "";
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
}*/
