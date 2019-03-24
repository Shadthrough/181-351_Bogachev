#include "stats.h"

stats::stats(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

void stats::set_login(QString a)
{
	ui.usrnmv->setText(a);
}

void stats::set_password(QString a)
{
	ui.pssv->setText(a);
}

void stats::on_viewb_clicked()
{
	db_win.set_test("Zhopa:lisa, ruchka:listok");
	db_win.show();
}

stats::~stats()
{

}


