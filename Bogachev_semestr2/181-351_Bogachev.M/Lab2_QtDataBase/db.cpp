#include "db.h"
/*	TBD
Refresh must be done on it; // DONE
Do a find on a separate units; // DONE
*/

db::db(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	socket = new QTcpSocket;
	//emit read();
	ui.edit->close();
	ui.find->close();
	ui.find_2->close();
}

void db::read()
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

db::~db()
{
	//socket->disconnect();
	//disconnect(socket, &QTcpSocket::readyRead, this, &db::read);
}

void db::closeEvent(QCloseEvent *event)
{
	emit on_close();
	event->accept();
}

void db::on_close()
{
	disconnect(socket, &QTcpSocket::readyRead, this, &db::read);
	daba.clear();
}

void db::on_show(QString lvl)
{
	if (lvl == "user")
	{
		ui.addb->close();
		ui.delb->close();
		ui.editb->close();
	}
	QByteArray arr = "refresh|";
	crypto aes;
	QByteArray cryp = aes.encrypt(arr);
	socket->write(cryp);
}

void db::set_socket(QTcpSocket * a)
{
	socket = a;
	connect(socket, &QTcpSocket::readyRead, this, &db::read);
}

//set db
bool db::setdb(std::string filename)
{
	/*std::fstream f;
	f.open(filename);
	if (!f)
	{
		return false;
	}
	std::string tmp;
	while (!f.eof())
	{
		std::getline(f, tmp);
		daba.push_back(parse(tmp));
	}
	f.close();
	return true;*/

	std::string tmp;
	std::ofstream kostil("Temp.txt");
	kostil.close();
	std::fstream f;
	f.open("Temp.txt");
	std::string str = data.toStdString().substr(0, data.toStdString().find('|') + 1);
	f << str;
	f.close();
	f.open("Temp.txt");
	std::getline(f, tmp);
	while (tmp != "|")
	{
		daba.push_back(parse(tmp));
		std::getline(f, tmp);
	}
	f.close();
	remove("Temp.txt");
	return true;
}


//void db::connect_to_serv()
//{
//	socket->connectToHost("127.0.0.1", 33333);
//}

QString db::parseunit(std::string str)
{
	QString temp;
	std::string tmp;
	std::string::size_type b, e;
	b = str.find(':');
	e = str.find(',');
	tmp = str.substr(b + 1, e - b - 1);
	temp = QString::fromUtf8(tmp.c_str());
	return temp;
}

QStandardItem * db::toItem(QString a)
{
	QStandardItem * item;
	item = new QStandardItem(a);
	return item;
}

void db::showdb(std::vector<bdata> a)
{
	table = new QStandardItemModel;
	QStringList head;
	head.append("ID");
	head.append("Train");
	head.append("Price, $");
	head.append("Company");
	head.append("Status");

	table->setHorizontalHeaderLabels(head);
	
	bdata tmp;
	int row = 0, col;

	for (int i = 0; i < a.size(); i++)
	{
		tmp = a[i];
		col = 0;
		table->setItem(row, col, toItem(tmp.id));
		col++;
		table->setItem(row, col, toItem(tmp.ride));
		col++;
		table->setItem(row, col, toItem(tmp.price));
		col++;
		table->setItem(row, col, toItem(tmp.comp));
		col++;
		table->setItem(row, col, toItem(tmp.sold));
		row++;
	}

	ui.tableui->setModel(table);
	ui.tableui->resizeRowsToContents();
	ui.tableui->resizeColumnsToContents();
}

void db::set_test(std::string a)
{
	//ui.testb->setText(parseunit(a)); ///////////////////////////	DO A Test check on parse here  /// done
}

void db::add(bdata a)
{
	std::fstream f;
	f.open("DataBase.txt", std::ios::app);
	std::string str, tmp;
	str = "ride:";
	tmp = a.ride.toUtf8().constData();
	str.append(tmp + ",price:");
	tmp = a.price.toUtf8().constData();
	str.append(tmp + ",comp:");
	tmp = a.comp.toUtf8().constData();
	str.append(tmp + ",sold:");
	tmp = a.sold.toUtf8().constData();
	str.append(tmp);
	f << std::endl << str;
	f.close();
}

void db::on_addb_clicked()
{
	bdata a;
	inputw win;
	win.setModal(true);
	win.exec();
	a.id = win.get_id();
	a.ride = win.get_ride();//win.trainl->text();
	a.price = win.get_price();//a.price = win.pricel->text();
	a.comp = win.get_comp();//a.comp = win.compl->text();
	a.sold = win.get_sold();//a.sold = win.soldl->text();
	if (a.comp != "" && a.price != "" && a.ride != "" && a.sold != "")
	{
		//add(a);
		QByteArray arr = "add|";
		arr.append(a.id);
		arr.append(":");
		arr.append(a.ride);
		arr.append(":");
		arr.append(a.price);
		arr.append(":");
		arr.append(a.comp);
		arr.append(":");
		arr.append(a.sold);
		crypto aes;
		QByteArray cryp = aes.encrypt(arr);
		socket->write(cryp);
		daba.clear();
	}
	//refr();
}

bdata db::get_line_data(int a)
{
	bdata tmp;
	/*int i = 0;
	QModelIndex indx = ui.tableui->model()->index(a, i);
	tmp.ride = indx.data().toString;
	i++;
	indx = ui.tableui->model()->index(a, i);
	tmp.price = indx.data().toString;
	i++;
	indx = ui.tableui->model()->index(a, i);
	tmp.comp = indx.data().toString;
	i++;
	indx = ui.tableui->model()->index(a, i);
	tmp.sold = indx.data().toString;*/
	return tmp;
}

void db::save()
{
	remove("Database.txt");
	std::ofstream kostil("DataBase.txt");
	kostil.close();
	std::fstream f;
	f.open("DataBase.txt");
	std::string str, tmp;
	for (int i = 0; i < daba.size(); i++)
	{
	
		str = "ride:";
		tmp = daba[i].ride.toStdString();
		str.append(tmp + ",price:");
		tmp = daba[i].price.toStdString();
		str.append(tmp + ",comp:");
		tmp = daba[i].comp.toStdString();
		str.append(tmp + ",sold:");
		tmp = daba[i].sold.toStdString();
		str.append(tmp);
		f << str;
		if (i != daba.size() - 1)
			f << std::endl;
	}
	f.close();
}

void db::on_editcancb_clicked()
{
	ui.edit->close();
}

void db::on_editsubmb_clicked()
{
	QString i = ui.numt->text();//.toInt() -1;
	/*daba[i].ride = ui.trainel->text();
	daba[i].price = ui.pricel->text();
	daba[i].comp = ui.compel->text();
	daba[i].sold = ui.soldel->text();
	//save();
	//QMessageBox::about(this, "Info", "Editing was successful, please press the refresh button.");*/
	ui.edit->close();
	//refr();
	QByteArray arr = "edit|";
	arr.append(i);
	arr.append(":");
	arr.append(ui.trainel->text());
	arr.append(":");
	arr.append(ui.pricel->text());
	arr.append(":");
	arr.append(ui.compel->text());
	arr.append(":");
	arr.append(ui.eselect->currentText());
	crypto aes;
	QByteArray cryp = aes.encrypt(arr);
	socket->write(cryp);
	daba.clear();
}

void db::on_editb_clicked()
{
	editreq win;
	win.setModal(true);
	win.exec();
	//eiwin.set_train(ui.tableui->)
	int num = win.get_num();
	if (num == NULL)
		return;
	ui.edit->show();
	std::string stnum;
	//char * chn;
	//itoa(num, chn, 10);
	stnum = std::to_string(num);
	QString snum = QString::fromStdString(stnum);
	ui.numt->setText(snum);
	int j;
	bool found = false;
	for (int i = 0; i < daba.size(); i++)
	{
		if (snum == daba[i].id)
		{
			j = i;
			found = true;
		}
	}
	if (!found)
	{
		QMessageBox::critical(this, "Alert", "There is so such ID");
		ui.edit->close();
		return;
	}
	ui.trainel->setText(daba[j].ride);
	ui.pricel->setText(daba[j].price);
	ui.compel->setText(daba[j].comp);
	//ui.soldel->setText(daba[j].sold);
}

void db::del(int a)
{
	remove("Database.txt");
	std::ofstream kostil("DataBase.txt");
	kostil.close();
	std::fstream f;
	f.open("DataBase.txt");
	std::string str, tmp;
	for (int i = 0; i < daba.size(); i++)
	{
		if (i != a - 1)
		{
			str = "ride:";
			tmp = daba[i].ride.toStdString();
			str.append(tmp + ",price:");
			tmp = daba[i].price.toStdString();
			str.append(tmp + ",comp:");
			tmp = daba[i].comp.toStdString();
			str.append(tmp + ",sold:");
			tmp = daba[i].sold.toStdString();
			str.append(tmp);
			f << str;
			if(i != daba.size() - 1)
				f << std::endl;
		}
	}
	f.close();
}

void db::on_findb_2_clicked()
{
	ui.find_2->show();
}

void db::on_findcancb_2_clicked()
{
	refr();
	ui.find_2->close();
}

void db::on_findsubmb_2_clicked()
{
	bool not_found;
	for (int i = 0; i < daba.size(); i++)
	{
		if ((daba[i].ride != ui.trainel_2->text() && ui.trainel_2->text() != "")
			|| (daba[i].price != ui.pricel_2->text() && ui.pricel_2->text() != "")
			|| (daba[i].comp != ui.compel_2->text() && ui.compel_2->text() != "")
			|| (daba[i].sold != ui.fselect->currentText() && ui.fselect->currentText() != ""))
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

void db::on_delb_clicked()
{
	inpdel win;
	win.setModal(true);
	win.exec();
	//del(win.get_num());
	//refr();
	int id = win.get_num();
	QByteArray arr = "delete|";
	std::string kostil = std::to_string(id);
	QString anotherOne = QString::fromStdString(kostil);
	arr.append(anotherOne);
	crypto aes;
	QByteArray cryp = aes.encrypt(arr);
	socket->write(cryp);
	daba.clear();
}

void db::on_findsubmb_clicked()
{
	bool not_found;
	for (int i = 0; i < daba.size(); i++)
	{
		if (daba[i].ride != ui.findl->text()
		&& daba[i].price != ui.findl->text()
		&& daba[i].comp != ui.findl->text()
		&& daba[i].sold != ui.findl->text())
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

void db::on_findcancb_clicked()
{
	refr();
	ui.find->close();
}

void db::on_findb_clicked()
{
	ui.find->show();
}

void db::refr()
{
	daba.clear();
	setdb("DataBase.txt");
	showdb(daba);
}

//parse
bdata db::parse(std::string str)
{
	bdata a;
	QString temp;
	std::string tmp;
	std::string::size_type b, e;
	b = str.find(':');
	e = str.find(',');
	tmp = str.substr(b + 1, e - b - 1);
	temp = QString::fromUtf8(tmp.c_str());
	a.id = temp;
	str.erase(0, e + 1);
	b = str.find(':');
	e = str.find(',');
	tmp = str.substr(b + 1, e - b - 1);
	temp = QString::fromUtf8(tmp.c_str());
	a.ride = temp;
	str.erase(0, e + 1);
	b = str.find(':');
	e = str.find(',');
	tmp = str.substr(b + 1, e - b - 1);
	temp = QString::fromUtf8(tmp.c_str());
	a.price = temp;
	str.erase(0, e + 1);
	b = str.find(':');
	e = str.find(',');
	tmp = str.substr(b + 1, e - b - 1);
	temp = QString::fromUtf8(tmp.c_str());
	a.comp = temp;
	str.erase(0, e + 1);
	b = str.find(':');
	e = str.find(',');
	tmp = str.substr(b + 1, e - b - 1);
	temp = QString::fromUtf8(tmp.c_str());
	a.sold = temp;
	str.erase(0, e);
	return a;
}






										/////////////BOTTLE//////////////////


/*bool check_ride(std::string ride)//Используемые символы - только буквы; Если регистр не тот, меняем на правильный.
{

	return true;
}
bool check_price(std::string price)//длина строки 10 символов, все из которых цифры;
{

	return true;
}
bool check_company(std::string comp)//тип данных Date
{

	return true;
}

bool add_data(data tempData)// добавить строку данных в БД
{

	return true;
}
bool open(std::string filename)//открываем файл
{

	return true;
}
bool download(std::string & res)//загружаем данные из файла в строку
{

	return true;
}
bool close()// закрытие файла
{
	
	return true;
}

data parsing(std::string line)
{
	data tmp;
	return tmp;
}

*/

												////////////STEPHEN/////////////////
/*
bool DataBase::add_data(datas tempData)//÷¸òêî
{
	//download(sdb);
	db.push_back(tempData);
	//transformStr2BD(sdb);
	//sdb +="\n"+ tempData.pred+"\t" + tempData.otr+"\t"  + tempData.date+ "\t"  + tempData.nal+"\t" + tempData.sum;
	return true;
}

bool DataBase::download(std::string & res) //ðàáîòàåò ÷¸òêî
{
	QFile fin("database.txt");
	fin.open(QIODevice::ReadOnly | QIODevice::Text);
	if (!fin.isOpen())
	{
		return false;
	}
	res = fin.readAll();
	fin.close();
	return true;
}

void DataBase::transformStr2BD(std::string sdb)// ÷¸òêî
{
	int i = 0;
	datas td;
	std::string line;//âçÿòü ïåðâóþ çàïèñü èç ôàéëà
	while (true) {
		while (sdb[i] != '\t') {
			line += sdb[i];
			i++;
		}
		td.pred = line;
		line.clear();
		i++;
		while (sdb[i] != '\t') {
			line += sdb[i];
			i++;
		}
		td.otr = line;
		line.clear();
		i++;
		while (sdb[i] != '\t') {
			line += sdb[i];
			i++;
		}
		td.date = line;
		line.clear();
		i++;
		while (sdb[i] != '\t') {
			line += sdb[i];
			i++;
		}
		td.nal = line;
		line.clear();
		i++;
		while (sdb[i] != '\n') {
			line += sdb[i];
			i++;
			if (i >= sdb.size())
				break;
		}
		td.sum = line;
		line.clear();
		i++;
		add_data(td);
		if (i >= sdb.size())
			break;
	}
	//tempData = parsing(line);

	//othercompany	food	13.05.2006	dan	1000
}

bool DataBase::write2file()//áëåñòÿùå
{

	QFile fout("database.txt");
	fout.open(QIODevice::WriteOnly | QIODevice::Text);
	if (!fout.isOpen())
	{
		return false;
	}
	QTextStream writeStream(&fout);
	int i = 0;
	sdb.clear();
	while (i < db.size())
	{
		sdb += db[i].pred + "\t" + db[i].otr + "\t" + db[i].date + "\t" + db[i].nal + "\t" + db[i].sum + "\n";
		i++;
	}
	QString str = str.fromStdString(sdb);
	writeStream << str;
}*/
