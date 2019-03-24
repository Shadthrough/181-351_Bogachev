#include "Lab2_QtDataBase.h"
#include "db.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Lab2_QtDataBase w;
	db q;
	q.close();
	w.show();
	return a.exec();
}
