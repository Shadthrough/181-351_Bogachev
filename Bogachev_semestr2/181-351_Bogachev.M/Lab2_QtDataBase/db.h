#pragma once

#include <QDialog>
#include <QWidget>
#include <QStandardItemModel>
#include <QTcpSocket>
#include <QByteArray>
#include <QDebug>
#include <QStandardItem>
#include <QTableView>
#include <QAbstractItemModel>
#include <QString>
#include <string>
#include <vector>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QCloseEvent>
//#include "Lab2_QtDataBase.h"
#include "crypto.h"
#include "editreq.h"
#include "inputw.h"
#include "inpdel.h"
#include "ui_db.h"
//										Maybe QObject as well

struct bdata
{
	QString id;
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
	//void connect_to_serv();
	void add(bdata a);
	void del(int a);
	bdata get_line_data(int a);
	void save();
	void refr();
	void set_socket(QTcpSocket * a);
	void closeEvent(QCloseEvent *event);

public slots:
	void on_show(QString lvl);

private slots:
	void on_addb_clicked();
	void on_editb_clicked();
	void on_delb_clicked();
	void on_editcancb_clicked();
	void on_editsubmb_clicked();
	void on_findb_clicked();
	void on_findb_2_clicked();
	void on_findcancb_clicked();
	void on_findsubmb_clicked();
	void on_findcancb_2_clicked();
	void on_findsubmb_2_clicked();
	void read();
	void on_close();

private:
	Ui::db ui;
	QStandardItemModel *table;
	QStandardItem *cell;
	std::vector<bdata> daba;
	QTcpSocket * socket;
	QByteArray data;
	//editinp eiwin;
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

bool check_ride(std::string ride);//������������ ������� - ������ �����; ���� ������� �� ���, ������ �� ����������.
bool check_price(std::string price);//����� ������ 10 ��������, ��� �� ������� �����;
bool check_company(std::string date);//��� ������ Date

class DataBase {

public:
	DataBase();//�����������
	///////////////////////////DataBase(std::string* tempDB); //����������� �� ������: �.�. �� ������, � ������� �������� ��, ��������� ��
	~DataBase();//����������
	bool add_data(data tempData);// �������� ������ ������ � ��
	bool open(std::string filename);//��������� ����
	bool download(std::string & res);//��������� ������ �� ����� � ������
	bool close();// �������� �����

	data parsing(std::string line);
	bool transformStr2BD(std::string strFromFile)// ����������� ������ � ��
	{
		//���� �� ������� ������
		std::string line;//����� ������ ������ �� �����
		//line = ...
		data tempData;
		tempData = parsing(line);
		add_data(tempData);
	}


	bool download()//��������� ������ �� ����� � ������
	{
		std::string strFromFile;
		//open(FileName);
		download(strFromFile);
		close();
		transformStr2BD(strFromFile);
	}

	bool del_data(std::string id);//������� ������ � �������� id

	template<typename T>
	std::vector<data> find(int criterior, T data2find);//������� ������ � �������� id

	bool change(std::string id, data tempData)
	{
		//db[id] = tempData;
	}

	bool write2file();

	/*DataBase()//�����������
	{

	}
	//DataBase(std::string* tempDB); //����������� �� ������: �.�. �� ������, � ������� �������� ��, ��������� ��
	~DataBase()//����������
	{

	}

private:
	std::vector<data> *db;
	FILE* fin;

protected:


};*/