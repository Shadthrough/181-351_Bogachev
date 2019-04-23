#include "db.h"

db::db(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setdb("DataBase.txt");
	showdb(daba);
}

db::~db()
{
}

//DaBa::DaBa()
//{
//}

//DaBa::~DaBa()
//{
//}

bool db/*DaBa*/::setdb(std::string filename)
{
	std::fstream f;
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
	return true;
}


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
	head.append("Train");
	head.append("Price");
	head.append("Company");
	head.append("Status");

	table->setHorizontalHeaderLabels(head);
	
	bdata tmp;
	int row = 0, col;

	for (int i = 0; i < a.size(); i++)
	{
		tmp = a[i];
		col = 0;
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
	ui.testb->setText(parseunit(a)); ///////////////////////////	DO A Test check on parse here  /// done
}

bdata db/*DaBa*/::parse(std::string str)
{
	bdata a;
	QString temp;
	std::string tmp;
	std::string::size_type b, e;
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
