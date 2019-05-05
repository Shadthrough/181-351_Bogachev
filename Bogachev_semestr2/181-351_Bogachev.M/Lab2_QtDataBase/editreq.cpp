#include "editreq.h"

editreq::editreq(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

editreq::~editreq()
{
}

int editreq::get_num()
{
	int a = ui.numl->text().toInt();
	return a;
}

void editreq::on_okb_clicked()
{
	if (ui.numl->text() != "" && ui.numl->text().toInt())
		close();
	else
		QMessageBox::critical(this, "Alert", "Please, enter a number.");
}

