#pragma once

#include <QDialog>
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

private slots:
	void on_viewb_clicked();

private:
	Ui::stats ui;
	db db_win;
};
