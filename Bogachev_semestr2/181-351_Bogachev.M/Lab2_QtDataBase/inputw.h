#pragma once

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "ui_inputw.h"

class inputw : public QDialog
{
	Q_OBJECT

public:
	inputw(QWidget *parent = Q_NULLPTR);
	~inputw();
	QString get_id();
	QString get_ride();
	QString get_price();
	QString get_comp();
	QString get_sold();

private slots:
	void on_okb_clicked();

private:
	Ui::inputw ui;
};
