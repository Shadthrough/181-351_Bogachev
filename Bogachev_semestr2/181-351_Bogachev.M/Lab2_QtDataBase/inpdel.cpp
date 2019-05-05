#include "inpdel.h"

inpdel::inpdel(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

inpdel::~inpdel()
{
}

int inpdel::get_num()
{
	int a;
	a = ui.numl->text().toInt();
	return a;
}

void inpdel::on_okb_clicked()
{
	if (ui.numl->text().toInt())
		close();
	else
		QMessageBox::critical(this, "Alert", "What you have entered is not a number.");
}
