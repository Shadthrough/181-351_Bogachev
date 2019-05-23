#include "inputw.h"

inputw::inputw(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

inputw::~inputw()
{
}

void inputw::on_okb_clicked()
{
	if(ui.trainl->text() != "" && ui.compl->text() != "" && ui.pricel->text() != "")
		close();
	else
		QMessageBox::critical(this, "Alert", "Please, fill in all the lines.");
}

QString inputw::get_id()
{
	QString a;
	a = ui.idl->text();
	return a;
}

QString inputw::get_ride()
{
	QString a;
	a = ui.trainl->text();
	return a;
}

QString inputw::get_price()
{
	QString a;
	a = ui.pricel->text();
	return a;
}

QString inputw::get_comp()
{
	QString a;
	a = ui.compl->text();
	return a;
}

QString inputw::get_sold()
{
	QString a;
	a = ui.select->currentText();
	return a;
}
