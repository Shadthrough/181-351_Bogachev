/*------------------------------------------------/

Bogachev Maksim 181-351

/------------------------------------------------*/
#include "Exam.h"

Exam::Exam(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void Exam::on_hashb_clicked()
{
	//ui.hash->setText(ui.line->text());
	QByteArray s = ui.line->text().toUtf8();

	char *ibuf = s.data();
	unsigned char obuf[20];

	SHA1((unsigned char*)ibuf, strlen(ibuf), obuf);

	s = QByteArray::fromRawData((char*)obuf, 20);
	ui.hash->setText(s.toHex());
}

void Exam::on_showb_clicked()
{
	QPixmap png;
	png.load("ARP.jpg");
	ui.png2->setPixmap(png);
}
