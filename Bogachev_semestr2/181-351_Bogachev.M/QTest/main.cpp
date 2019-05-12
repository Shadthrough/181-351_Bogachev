#include <QtCore/QCoreApplication>
#include <fstream>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	std::ofstream f("Dude.txt");
	f.close();
	std::fstream q;
	q.open("Dude.txt");
	QByteArray arr = "Suck";
	arr.append("\n");
	arr.append("Nigger");
	q << arr.toStdString();
	q.close();

	return a.exec();
}
