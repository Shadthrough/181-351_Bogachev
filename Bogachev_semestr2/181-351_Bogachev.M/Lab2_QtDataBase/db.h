#pragma once

#include <QDialog>
#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
#include <QAbstractItemModel>
#include <QString>
#include <string>
#include <vector>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include "ui_db.h"

struct bdata
{
	QString ride;
	QString price;
	QString comp;
	QString sold;
};


class db : public QDialog//, public Ui::db
{
	Q_OBJECT

public:
	db(QWidget *parent = Q_NULLPTR);
	void set_test(std::string a);
	~db();
	bool setdb(std::string filename);
	bdata parse(std::string str);
	QString parseunit(std::string str);
	void showdb(std::vector<bdata> a);
	QStandardItem * toItem(QString a);
	////////////////// NEED TO WATCH HOW DOES VECTOR WORK YO BRING OUT DATA FROM IT TO WIDGET

private:
	Ui::db ui;
	QStandardItemModel *table;
	QStandardItem *cell;
	std::vector<bdata> daba;
};










						//		Before stupid attempt		//
						/*
class db : public QDialog//, public Ui::db
{
	Q_OBJECT

public:
	db(QWidget *parent = Q_NULLPTR);
	void set_test(std::string a);
	~db();


private:
	Ui::db ui;
};

struct bdata
{
	QString ride;
	QString price;
	QString comp;
	QString sold;
};

class DaBa
{
public:
	DaBa();
	~DaBa();
	bool setdb(std::string filename);
	bdata parse(std::string str);
	friend QString parseunit(std::string str);

private:
	std::vector<bdata> db;
};						*/

/*DaBa::DaBa()
{
}

DaBa::~DaBa()
{
}*/




/*												//////////BOTTLE////////////
struct data {
	std::string race;
	std::string price;
	std::string company;
};

bool check_ride(std::string ride);//Используемые символы - только буквы; Если регистр не тот, меняем на правильный.
bool check_price(std::string price);//длина строки 10 символов, все из которых цифры;
bool check_company(std::string date);//тип данных Date

class DataBase {

public:
	DataBase();//конструктор
	///////////////////////////DataBase(std::string* tempDB); //конструктор по строке: т.е. по строке, в которой записана БД, формируем БД
	~DataBase();//деструктор
	bool add_data(data tempData);// добавить строку данных в БД
	bool open(std::string filename);//открываем файл
	bool download(std::string & res);//загружаем данные из файла в строку
	bool close();// закрытие файла

	data parsing(std::string line);
	bool transformStr2BD(std::string strFromFile)// преобразует строку в БД
	{
		//Цикл по входной строке
		std::string line;//взять перфую запись из файла
		//line = ...
		data tempData;
		tempData = parsing(line);
		add_data(tempData);
	}


	bool download()//загружаем данные из файла в строку
	{
		std::string strFromFile;
		//open(FileName);
		download(strFromFile);
		close();
		transformStr2BD(strFromFile);
	}

	bool del_data(std::string id);//удалить запись с заданным id

	template<typename T>
	std::vector<data> find(int criterior, T data2find);//удалить запись с заданным id

	bool change(std::string id, data tempData)
	{
		//db[id] = tempData;
	}

	bool write2file();

	/*DataBase()//конструктор
	{

	}
	//DataBase(std::string* tempDB); //конструктор по строке: т.е. по строке, в которой записана БД, формируем БД
	~DataBase()//деструктор
	{

	}

private:
	std::vector<data> *db;
	FILE* fin;

protected:


};*/