#pragma once

#include <QDialog>
//#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>
#include "ui_stats.h"
#include "db.h"

class stats : public QDialog
{
	Q_OBJECT

public:
	stats(QWidget *parent = Q_NULLPTR);
	~stats();
	void set_login(QString a);
	void set_password(QString a);
	//QTcpSocket* socket;
	//QByteArray Data;

public slots:
	//void sockReady();
	//void sockDisc();

private slots:
	void on_viewb_clicked();
	//void on_ser_clicked();

private:
	Ui::stats ui;
	db db_win;
};
