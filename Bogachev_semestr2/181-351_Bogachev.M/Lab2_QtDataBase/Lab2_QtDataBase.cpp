#include "stats.h"
#include "Lab2_QtDataBase.h"
#include <QMessageBox>


Lab2_QtDataBase::Lab2_QtDataBase(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	socket = new QTcpSocket;
	socket->connectToHost("127.0.0.1", 33333);
	connect(socket, &QTcpSocket::disconnected, this, &Lab2_QtDataBase::conact);
	connect(socket, &QTcpSocket::readyRead, this, &Lab2_QtDataBase::read);
	//st_win = new stats;
	//connect(socket, SIGNAL(disconnect()), this, SLOT(disconnected()));
}

QTcpSocket * Lab2_QtDataBase::get_socket()
{
	return socket;
}

void Lab2_QtDataBase::conact()
{
	QMessageBox::about(this, "Message", "You are disconnected");
	socket->close();
}

void Lab2_QtDataBase::read()
{
	while (socket->bytesAvailable() > 0)
	{
		data = socket->readAll();
		qDebug() << data;
		
	}
}

Lab2_QtDataBase::~Lab2_QtDataBase()
{
	socket->close();
}

void Lab2_QtDataBase::on_butt_clicked()
{
	QString login, password;
	login =	ui.log->text();
	password = ui.pass->text();

	std::fstream f;
	f.open("Users.txt");
	QString tlog, tpass;
	std::string tmp, str;
	std::string::size_type b, e;
	bool found = false;
	while (!f.eof())
	{
		std::getline(f, str);
		b = str.find(':');
		e = str.find(',');
		tmp = str.substr(b + 1, e - b - 1);
		tlog = QString::fromUtf8(tmp.c_str());
		str.erase(0, e + 1);
		b = str.find(':');
		e = str.find(',');
		tmp = str.substr(b + 1, e - b - 1);
		tpass = QString::fromUtf8(tmp.c_str());
		str.erase(0, e + 1);


		if (login == tlog && password == tpass)
		{
			hide();
			found = true;
			disconnect(socket, &QTcpSocket::readyRead, this, &Lab2_QtDataBase::read);
			//connect(socket, &QTcpSocket::readyRead, st_win, &stats::read); вот это у меня не заработало, подчеркивает конект,
			//говорит нет перегрузки
			st_win.set_socket(socket);
			//socket->disconnect();
			st_win.set_login(login);
			st_win.set_password(password);
			st_win.show();
		}
	}
	if (!found)
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
	QByteArray arr = "refresh|aaaaaa";
	socket->write(arr);
}

void Lab2_QtDataBase::on_regb_clicked()
{
	if (ui.passl->text() != ui.repassl->text())
	{
		QMessageBox::critical(this, "Alert", "Entered passwords do not match.");
		return;
	}
	std::string str;
	std::fstream f;
	f.open("Users.txt", std::ios::app);
	f << std::endl;
	str = "login:" + ui.logl->text().toStdString() + ",password:" + ui.passl->text().toStdString();
	f << str;
	QMessageBox::about(this, "Message", "Your regestration is successful.\n Use your login and password ti sign in.");
}
