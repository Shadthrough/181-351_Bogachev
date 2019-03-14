#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab2_QtDataBase.h"
#include "stats.h"

class Lab2_QtDataBase : public QMainWindow
{
	Q_OBJECT

public:
	Lab2_QtDataBase(QWidget *parent = Q_NULLPTR);

private slots:
	void on_butt_clicked();

private:
	Ui::Lab2_QtDataBaseClass *ui;
	stats *st_win;
};
