#pragma once

#include <QDialog>
#include <QMessageBox>
#include "ui_inpdel.h"

class inpdel : public QDialog
{
	Q_OBJECT

public:
	inpdel(QWidget *parent = Q_NULLPTR);
	~inpdel();
	int get_num();

private slots:
	void on_okb_clicked();

private:
	Ui::inpdel ui;
};
