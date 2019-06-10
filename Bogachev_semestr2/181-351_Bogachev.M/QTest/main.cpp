#include "QTest.h"
#include <QtWidgets/QApplication>
#include <qdebug.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//QTest w;
	//w.show();
	QByteArray arr = "suk";
	//arr.remove(0, 4);
	qDebug() << arr.toBase64();
	return a.exec();
}
