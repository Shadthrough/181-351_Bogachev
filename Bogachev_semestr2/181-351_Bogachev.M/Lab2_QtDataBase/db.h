#pragma once

#include <QDialog>
#include <string>
#include <vector>
#include <QFile>
#include <QTextStream>
#include "ui_db.h"

class db : public QDialog//, public Ui::db
{
	Q_OBJECT

public:
	db(QWidget *parent = Q_NULLPTR);
	void set_test(QString a);
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
};

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