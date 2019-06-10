#include "QTest.h"
#include <qpushbutton.h>
#include <qlabel.h>

QTest::QTest(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//QWidget *w = ui.butt->parentWidget();
	//b.setText("Rondo");
	connect(this, SIGNAL(done(QString)), &w, SLOT(stupid(QString)));
	//connect(this, QTest::done(), w, scnd::stupid(QString));
}


void QTest::on_butt_clicked()
{
	QLabel l("I am really stupid", this);
	l.setGeometry(10, 10, 50, 50);
	l.show();
	emit done(l.text());
	w.show();
}

void QTest::on_lol_clicked()
{
	emit done("HOW????????????????");
}

