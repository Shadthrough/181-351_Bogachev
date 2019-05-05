#pragma once

#include <QDialog>
#include <qmessagebox.h>
#include "ui_editreq.h"

class editreq : public QDialog
{
	Q_OBJECT

public:
	editreq(QWidget *parent = Q_NULLPTR);
	~editreq();
	int get_num();
private slots:
	void on_okb_clicked();

signals:
	void stop();

private:
	Ui::editreq ui;
};
