#include "siska.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	siska w;
	w.show();
	return a.exec();
}
