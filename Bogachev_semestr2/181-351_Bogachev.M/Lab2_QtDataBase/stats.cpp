#include "stats.h"

stats::stats(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	socket = new QTcpSocket(this);
	/*socket = new QTcpSocket(this);*/
	//connect(socket, &QTcpSocket::connected, this, &stats::conact);
		//connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));
}

void stats::conact()
{
	QMessageBox::about(this, "Message", "You are connected");
}

void stats::read()
{
	while (socket->bytesAvailable() > 0)
	{
		data = socket->readAll();
		qDebug() << data;
	}
}

void stats::set_login(QString a)
{
	ui.usrnmv->setText(a);
}

void stats::set_password(QString a)
{
	ui.pssv->setText(a);
}

void stats::on_editb_clicked()
{
	QByteArray arr = "refresh|cad";
	socket->write(arr);
}

void stats::on_viewb_clicked()
{
	//db_win.setdb("DataBase.txt");
	//db_win.showdb(db.daba);
	//db_win.set_test("Zhopa:lisa, ruchka:listok");
	//db db_win;
	disconnect(socket, &QTcpSocket::readyRead, this, &stats::read);
	db_win.set_socket(socket);
	//socket->disconnect();
	emit db_win.on_show();
	db_win.show();
}

void stats::set_socket(QTcpSocket * a)
{
	socket = a;
	connect(socket, &QTcpSocket::readyRead, this, &stats::read);
}

stats::~stats()
{

}


////////////////////////////////	Forsed




/////////////////////////////////////////////serv

//void stats::on_ser_clicked()
//{
//	socket->connectToHost("127.0.0.1", 5555);
//}
//
//void stats::sockDisc()
//{
//	socket->deleteLater();
//}
//
//void stats::sockReady()
//{
//	if (socket->waitForConnected())
//	{
//		socket->waitForReadyRead();
//		Data = socket->readAll();
//		qDebug() << Data;
//	}
//}

