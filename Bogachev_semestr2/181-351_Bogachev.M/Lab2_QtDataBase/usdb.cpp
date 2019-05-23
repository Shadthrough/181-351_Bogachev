#include "usdb.h"

usdb::usdb(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(this, &QWidget::close, this, &usdb::on_close);
}

usdb::~usdb()
{
}

void usdb::closeEvent(QCloseEvent *event)
{
	emit on_close();
	event->accept();
}

void usdb::on_close()
{
	disconnect(socket, &QTcpSocket::readyRead, this, &usdb::read);
	daba.clear();
}

bool usdb::setdb(std::string filename)
{
	std::string tmp;
	std::ofstream kostil("UTemp.txt");
	kostil.close();
	std::fstream f;
	f.open("UTemp.txt");
	std::string str = data.toStdString().substr(0, data.toStdString().find('|') + 1);
	f << str;
	f.close();
	f.open("UTemp.txt");
	std::getline(f, tmp);
	while (tmp != "|")
	{
		daba.push_back(parse(tmp));
		std::getline(f, tmp);
	}
	f.close();
	remove("UTemp.txt");
	return true;
}

udata usdb::parse(std::string str)
{
	udata a;
	QString temp;
	std::string tmp;
	std::string::size_type b, e;
	b = str.find(':');
	e = str.find(',');
	tmp = str.substr(b + 1, e - b - 1);
	temp = QString::fromUtf8(tmp.c_str());
	a.login = temp;
	str.erase(0, e + 1);
	b = str.find(':');
	e = str.find(',');
	tmp = str.substr(b + 1, e - b - 1);
	temp = QString::fromUtf8(tmp.c_str());
	a.password = temp;
	str.erase(0, e + 1);
	b = str.find(':');
	e = str.find(',');
	tmp = str.substr(b + 1, e - b - 1);
	temp = QString::fromUtf8(tmp.c_str());
	a.status = temp;
	return a;
}

void usdb::showdb(std::vector<udata> a)
{
	table = new QStandardItemModel;
	QStringList head;
	head.append("Login");
	head.append("Password");
	head.append("Status");

	table->setHorizontalHeaderLabels(head);

	udata tmp;
	int row = 0, col;

	for (int i = 0; i < a.size(); i++)
	{
		tmp = a[i];
		col = 0;
		table->setItem(row, col, toItem(tmp.login));
		col++;
		table->setItem(row, col, toItem(tmp.password));
		col++;
		table->setItem(row, col, toItem(tmp.status));
		row++;
	}

	ui.tableui->setModel(table);
	ui.tableui->resizeRowsToContents();
	ui.tableui->resizeColumnsToContents();
}

QStandardItem * usdb::toItem(QString a)
{
	QStandardItem * item;
	item = new QStandardItem(a);
	return item;
}

void usdb::set_socket(QTcpSocket * a)
{
	socket = a;
	connect(socket, &QTcpSocket::readyRead, this, &usdb::read);
}

void usdb::set_lvl(QString a)
{
	lvl = a;
}

void usdb::on_ushow()
{
	if (lvl == "manager")
	{
		ui.delb->close();
		ui.delloginl->close();
		ui.edit->close();
	}
	QByteArray arr = "Urefresh|";
	crypto aes;
	QByteArray cryp = aes.encrypt(arr);
	socket->write(cryp);
}


/*if (lvl == "manager")
{
	ui.delb->close();
	ui.delloginl->close();
	ui.edit->close();
}
QByteArray arr = "Urefresh|";
crypto aes;
QByteArray cryp = aes.encrypt(arr);
socket->write(cryp);*/

void usdb::on_delb_clicked()
{
	QString log = ui.delloginl->text();
	bool found = false;
	for (int i = 0; i < daba.size(); i++)
	{
		if (daba[i].login == log)
		{
			found = true;
			break;
		}
	}
	if (!found)
	{
		QMessageBox::critical(this, "Alert", "There is no such login.");
		return;
	}
	QByteArray arr = "Udelete|";
	arr.append(log);
	crypto aes;
	QByteArray cryp = aes.encrypt(arr);
	socket->write(cryp);
	daba.clear();
}

void usdb::on_editsubmb_clicked()
{
	//ui.edit->close();
	QString a = ui.statl->text();
	QString b = ui.logl->text();
	if (a != "administrator" && a != "manager" && a != "user")
	{
		QMessageBox::critical(this, "Alert", "There is no such status");
		return;
	}
	bool found = false;
	for (int i = 0; i < daba.size(); i++)
	{
		if (daba[i].login == b)
		{
			found = true;
			break;
		}
	}
	if (!found)
	{
		QMessageBox::critical(this, "Alert", "There is no such login.");
		return;
	}
	QByteArray arr = "Uedit|";
	arr.append(ui.logl->text());
	arr.append(":");
	arr.append(ui.statl->text());
	crypto aes;
	QByteArray cryp = aes.encrypt(arr);
	socket->write(cryp);
	daba.clear();
}

void usdb::refr()
{
	daba.clear();
	setdb("DataBase.txt");
	showdb(daba);
}

void usdb::on_findcancb_clicked()
{
	refr();
}

void usdb::on_findsubmb_clicked()
{
	bool not_found;
	for (int i = 0; i < daba.size(); i++)
	{
		if (daba[i].login != ui.findl->text())
		{
			daba.erase(daba.begin() + i);
			i--;
		}
	}
	if (daba.empty())
		QMessageBox::critical(this, "Alert", "No matches found.");
	else
		showdb(daba);
	daba.clear();
	setdb("DataBase.txt");
}

void usdb::read()
{
	while (socket->bytesAvailable() > 0)
	{
		QByteArray cryp = socket->readAll();
		crypto aes;
		data = aes.decrypt(cryp);
		qDebug() << data;
	}
	setdb("DataBase.txt");
	showdb(daba);
}
