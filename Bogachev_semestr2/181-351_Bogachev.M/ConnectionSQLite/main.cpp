#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);


	// создаем базу данных типа QSQLite
	// QSQLite - встроенный драйвер в QT
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("Test");
	if (!db.open())
		qDebug() << db.lastError().text();

	// добавить запись путем SQL запроса
	// создать запрос к БД
   /*
	создание таблицы

	Название: User
	Поля: login, password - хранятся значениия типа char[20] (массив символов длины 20)

	CREATE TABLE User(login VARCHAR(20) NOT NULL, password VARCHAR(20) NOT NULL)

	Зачем нужны типы данных?
		Пример: в поле age типа INTEGER в разных записях БД (строках таблицы) записано
				"123"
				34
				"a"
		Вопрос: как сравнивать? преобразуем к заданному типу INTEGER:
					"123" -> 123
					34 -> 34
					"a" -> 65 (код символа)

	Вставить запись в таблицу

	Название таблицы: User
	login: "admin"
	password: "123"

	INSERT INTO User(login, password) VALUES ("admin", "123")
*/
	QSqlQuery query(db);
	//создали таблицу
	query.exec("CREATE TABLE User("
		"login VARCHAR(20) NOT NULL, "
		"password VARCHAR(20) NOT NULL,"
		"level VARCHAR(20) NOT NULL"
		")");

	//добавить запись в таблицу
	/*query.prepare("INSERT INTO User(login, password) "
				  "VALUES (\"admin\", \"123\")");

*/
	query.prepare("INSERT INTO User(login, password, level) "
		"VALUES (:login, :password, :level)");

	query.bindValue(":password", "123");
	query.bindValue(":login", "admin");
	query.bindValue(":level", "1");
	query.exec();
	/*for (int i = 0; i < 10; i++)
	{
		query.bindValue(":password", QString::number(i) + QString::number(i));
		query.bindValue(":login", "manager" + QString::number(i));
		query.bindValue(":level", "2 ");
		query.exec();
	}
	for (int i = 0; i < 10; i++)
	{
		query.bindValue(":password", i);
		query.bindValue(":login", "user" + QString::number(i));
		query.bindValue(":level", "3");
		query.exec();
	}


	/*
	Выбрать все записи БД
	SELECT * FROM User

	Выбрать все записи БД с условием
	SELECT * FROM User WHERE .......
   *//*
	query.exec("SELECT * FROM User");


	// вывести на экран
	QSqlRecord rec = query.record();
	const int loginIndex = rec.indexOf("login");//номер "столбца"
	const int passwordIndex = rec.indexOf("password");
	const int levelIndex = rec.indexOf("level");

	while (query.next())
		qDebug() << query.value(loginIndex) << "\t" << query.value(passwordIndex) << "\t" << query.value(levelIndex) << "\n";

	//закрыть соединение
	//удалить таблицу*/
	//query.exec("DROP TABLE User");
	//закрываем базу данных
	db.close();
	return a.exec();
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include <QtCore/QCoreApplication>
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
	db.setDatabaseName("Test.txt");
	
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
	//query.exec("DROP TABLE User");


	// close connection
	db.close();
	return a.exec();
}*/
