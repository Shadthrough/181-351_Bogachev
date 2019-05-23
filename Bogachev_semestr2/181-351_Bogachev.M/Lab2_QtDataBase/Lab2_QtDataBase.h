#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab2_QtDataBase.h"
#include "stats.h"
#include "db.h"

class Lab2_QtDataBase : public QMainWindow
{
	Q_OBJECT

public:
	Lab2_QtDataBase(QWidget *parent = Q_NULLPTR);
	QTcpSocket * get_socket();
	~Lab2_QtDataBase();
	void aftlog();

private slots:
	void on_butt_clicked();
	void on_show_clicked();
	void on_regb_clicked();
	void read();
	void conact();

private:
	Ui::Lab2_QtDataBaseClass ui;
	stats st_win;
	QTcpSocket * socket;
	QByteArray data;
	QString lvl;
};
