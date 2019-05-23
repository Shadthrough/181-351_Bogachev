#pragma once

#include <QDialog>
#include "ui_usdb.h"
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
#include "inpdel.h"


struct udata
{
	QString login;
	QString password;
	QString status;
};

class usdb : public QDialog
{
	Q_OBJECT

public:
	usdb(QWidget *parent = Q_NULLPTR);
	~usdb();
	bool setdb(std::string filename);
	udata parse(std::string str);
	void showdb(std::vector<udata> a);
	QStandardItem * toItem(QString a);
	void set_socket(QTcpSocket * a);
	//void on_ushow(QString lvl);
	void refr();
	void closeEvent(QCloseEvent *event);
	void set_lvl(QString a);

public slots:
	void on_ushow();

private slots:
	void on_delb_clicked();
	void on_editsubmb_clicked();
	void on_findcancb_clicked();
	void on_findsubmb_clicked();
	void read();
	void on_close();

private:
	Ui::usdb ui;
	QStandardItemModel *table;
	QStandardItem *cell;
	std::vector<udata> daba;
	QTcpSocket * socket;
	QByteArray data;
	//editinp eiwin;
	QString lvl;
};
//-----------------------Do a hash on serv + do a client part on the main window------------------------------------