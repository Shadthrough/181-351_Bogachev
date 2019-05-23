#include <QtCore/QCoreApplication>
#include <fstream>
#include <qcryptographichash.h>
#include <qdebug.h>
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QString line = "ZHOPA";
	QByteArray arr = line.toUtf8(), hash;
	hash = QCryptographicHash::hash(arr, QCryptographicHash::Md5);
	for (int i = 0; i < hash.size(); i++)
	qDebug() << hash[i];

	return a.exec();
}
