#include "Lab2_QtDataBase.h"
#include <QMessageBox>

Lab2_QtDataBase::Lab2_QtDataBase(QWidget *parent)
	: QMainWindow(parent)
{
	ui->setupUi(this);
}

void Lab2_QtDataBase::on_butt_clicked()
{
	QString login, password;
	login =	ui->log->text();
	password = ui->pass->text();
	st_win = new stats(this);
	st_win->show();
}