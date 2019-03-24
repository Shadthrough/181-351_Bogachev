#include "Lab2_QtDataBase.h"
#include <QMessageBox>
#include "stats.h"

Lab2_QtDataBase::Lab2_QtDataBase(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void Lab2_QtDataBase::on_butt_clicked()
{
	QString login, password;
	login =	ui.log->text();
	password = ui.pass->text();
	if (login == "admin" && password == "admin")
	{
		st_win.set_login(login);
		st_win.set_password(password);
		st_win.show();
	}
	else
		QMessageBox::critical(this, "Error", "Incorrect login or password");
}

bool sight = false;

void Lab2_QtDataBase::on_show_clicked()
{
	if (!sight)
	{
		ui.pass->setEchoMode(QLineEdit::Normal);
		sight = true;
	}
	else
	{
		ui.pass->setEchoMode(QLineEdit::Password);
		sight = false;
	}
}
