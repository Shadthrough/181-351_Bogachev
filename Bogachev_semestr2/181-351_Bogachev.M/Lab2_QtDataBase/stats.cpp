#include "stats.h"

stats::stats(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	/*socket = new QTcpSocket(this);
		connect(socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
		connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));*/
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
	//db_win.setdb("DataBase.txt");
	//db_win.showdb(db.daba);
	//db_win.set_test("Zhopa:lisa, ruchka:listok");
	db_win.show();
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

