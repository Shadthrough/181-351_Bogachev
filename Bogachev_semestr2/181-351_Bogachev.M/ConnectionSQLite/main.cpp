#include <QtCore/QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QVariant>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("Test");
	
	if (db.open())
		qDebug() << "db is open";

	QSqlQuery query(db);
	query.exec("CREATE TABLE User(login VARCHAR (20) NOT NULL, password VARCHAR (20) NOT NULL)");
	//to write ' " ' in sql use /"
	//query.prepare("INSERT INTO User(login, password) VALUES(\"admin\", \"123\")");
	//query.exec();
		//Using variables
	query.prepare("INSERT INTO User(login, password) VALUES(:login, :password)");
	query.bindValue(":login", "admin");
	query.bindValue(":password", "123");
	query.exec();
	// add a line with SQL
	/*
	CREATE TABLE User(login VARCHAR (20) NOT NULL,/separated with ','[comma]/ password VARCHAR/type/ (20)/max length/ NOT NULL/can not be empty/)
	
	INSERT INTO User(login, password) VALUES ("admin", "123")
	
	SELECT * FROM User

	//IF//
	SELECT * FROM User WHERE ............


	*/

	// create request

	// show on screen
	query.exec("SELECT * FROM User");
	QSqlRecord rec = query.record();
	const int loginIndex = rec.indexOf("login");// its a numer of col
	const int passwordIndex = rec.indexOf("password");
	//qDebug() << query.value(loginIndex);
	while (query.next())
	{
		qDebug() << query.value(loginIndex) << '\t' << query.value(passwordIndex) << '\t';
	}
	// del table
	query.exec("DROP TABLE User");


	// close connection
	db.close();
	return a.exec();
}
