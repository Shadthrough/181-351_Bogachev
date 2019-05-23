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
	query.exec("CREATE TABLE Users("
		"Login VARCHAR(20) NOT NULL, "
		"Password VARCHAR(25) NOT NULL,"
		"Access_level VARCHAR(20) NOT NULL"
		")");

	query.prepare("INSERT INTO Users(login, password, access_level) "
		"VALUES (:log, :pass, :status)");

	query.bindValue(":log", "admino");
	query.bindValue(":pass", "admin");
	query.bindValue(":status", "administrator");
	query.exec();
	//query.exec("DROP TABLE Pricelist");
	db.close();
	//qDebug() << "You suck";*/
	//std::string str = "3:12:123:SR:Sold";
	//add(str, 0);
}
void MyTcpServer::Urefresh(QTcpSocket * a)
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("DataBase");

	if (db.open())
		qDebug() << "db is open";

	QSqlQuery query(db);
	QByteArray data;
	query.exec("SELECT * FROM Users");
	data.clear();
	while (query.next())
	{
		data.append("Login:");
		data.append(query.value(0).toByteArray());
		data.append(",:");
		data.append(query.value(1).toByteArray());
		data.append(",:");
		data.append(query.value(2).toByteArray());
		data.append("\n");
	}
	if (data.isEmpty())
		data = "I was empty(((";
	data.append('|');
	crypto aes;
	QByteArray cryp = aes.encrypt(data);
	a->write(cryp);
	//a->write(data);
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
	crypto aes;
	QByteArray cryp = aes.encrypt(data);
	a->write(cryp);
	//a->write(data);
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
		QByteArray arr = clientSocket->readAll();
		crypto aes;
		QByteArray dec = aes.decrypt(arr);
		std::string message;
		message = dec.toStdString();
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
		}
		else if (func == "refresh")
			refresh(clientSocket);
		else if (func == "Urefresh")
			Urefresh(clientSocket);
		else if (func == "Uadd")
		{
			message.erase(0, message.find('|') + 1);
			Uadd(message, id);
		}
		else if (func == "Udelete")
		{
			message.erase(0, message.find('|') + 1);
			Udel(message, id);
		}
		else if (func == "Uedit")
		{
			message.erase(0, message.find('|') + 1);
			Uedit(message, id);
		}
		else if (func == "Ucheck")
		{
			message.erase(0, message.find('|') + 1);
			Ucheck(message, clientSocket);
		}
		else
			return;///////

	}
}

MyTcpServer::~MyTcpServer()
{
	//QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	//db.close();///////////////////////////////////////////////////////////////////////////////////////////////
	foreach (int i, SClients.keys()) 
	{
		QTextStream os(SClients[i]);/////////////////////////////////////////////////////////
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
	//QByteArray test;
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

void MyTcpServer::Uadd(std::string a, int desc)
{
	QString log, pass;
	log = QString::fromStdString(a.substr(0, a.find(':')));
	a.erase(0, a.find(":") + 1);
	pass = QString::fromStdString(a);
	//QString line = "";
	QByteArray arr = pass.toUtf8(), hash, rdy;
	hash = QCryptographicHash::hash(arr, QCryptographicHash::Md5);
	for (int i = 0; i < hash.size(); i++)
		rdy.append(hash[i]);
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("DataBase");
	if (!db.open())
		qDebug() << db.lastError().text();

	QSqlQuery query(db);
	query.exec("CREATE TABLE Users("
		"Login VARCHAR(20) NOT NULL, "
		"Password VARCHAR(25) NOT NULL,"
		"Access_level VARCHAR(20) NOT NULL"
		")");

	query.prepare("INSERT INTO Users(login, password, access_level) "
		"VALUES (:log, :pass, :acl)");
	//QByteArray test;
	query.bindValue(":log", log);
	query.bindValue(":pass", rdy);
	query.bindValue(":acl", "user");
	query.exec();
	//query.exec("DROP TABLE Pricelist");
	db.close();
	//qDebug() << "You suck";*/
	//Urefresh(SClients[desc]);
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

void MyTcpServer::Uedit(std::string a, int desk)
{
	QString id, train, price, comp, stat;
	id = QString::fromStdString(a.substr(0, a.find(':')));
	a.erase(0, a.find(":") + 1);
	stat = QString::fromStdString(a);
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("DataBase");
	if (!db.open())
		qDebug() << db.lastError().text();

	QSqlQuery query(db);
	query.exec("CREATE TABLE Users("
		"Login VARCHAR(20) NOT NULL, "
		"Password VARCHAR(25) NOT NULL,"
		"Access_level VARCHAR(20) NOT NULL"
		")");

	query.prepare("UPDATE Users SET access_level = :stat WHERE login = :id");
	query.bindValue(":id", id);
	query.bindValue(":stat", stat);
	query.exec();
	//query.exec("DROP TABLE Pricelist");
	db.close();
	//qDebug() << "You suck";*/
	Urefresh(SClients[desk]);
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

void MyTcpServer::Udel(std::string a, int desc)
{
	QString id = QString::fromStdString(a);
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("DataBase");
	if (!db.open())
		qDebug() << db.lastError().text();

	QSqlQuery query(db);
	query.exec("CREATE TABLE Users("
		"Login VARCHAR(20) NOT NULL, "
		"Password VARCHAR(25) NOT NULL,"
		"Access_level VARCHAR(20) NOT NULL"
		")");

	query.prepare("DELETE FROM Users WHERE login = :id");
	query.bindValue(":id", id);
	query.exec();
	//query.exec("DROP TABLE Pricelist");
	db.close();
	//qDebug() << "You suck";*/
	Urefresh(SClients[desc]);
}//*/

/*-----------------------Check----------------------------*/
void MyTcpServer::Ucheck(std::string a, QTcpSocket * sock)
{
	QString log, pass;
	log = QString::fromStdString(a.substr(0, a.find(':')));
	a.erase(0, a.find(":") + 1);
	pass = QString::fromStdString(a);
	//QString line = "";
	QByteArray arr = pass.toUtf8(), hash, rdy;
	hash = QCryptographicHash::hash(arr, QCryptographicHash::Md5);
	for (int i = 0; i < hash.size(); i++)
		rdy.append(hash[i]);
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("DataBase");
	if (!db.open())
		qDebug() << db.lastError().text();

	QSqlQuery query(db);
	query.exec("CREATE TABLE Users("
		"Login VARCHAR(20) NOT NULL, "
		"Password VARCHAR(25) NOT NULL,"
		"Access_level VARCHAR(20) NOT NULL"
		")");

	query.prepare("SELECT * FROM Users WHERE login = :log AND password = :pass");
	//QByteArray test;
	query.bindValue(":log", log);
	query.bindValue(":pass", rdy);
	query.exec();
	//query.exec("DROP TABLE Pricelist");
	QByteArray response;
	if (query.next())
	{
		response = "true|";
		response.append(query.value(2).toByteArray());
		crypto aes;
		QByteArray cryp = aes.encrypt(response);
		sock->write(cryp);
	}
	else
	{
		response = "false|";
		crypto aes;
		QByteArray cryp = aes.encrypt(response);
		sock->write(cryp);
	}
	db.close();
	//qDebug() << "You suck";*/
	//Urefresh(SClients[desc]);
}

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

