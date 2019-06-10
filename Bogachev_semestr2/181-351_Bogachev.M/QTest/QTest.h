#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QTest.h"
#include "scnd.h"

class QTest : public QMainWindow
{
	Q_OBJECT

public:
	QTest(QWidget *parent = Q_NULLPTR);

public slots:
	void on_butt_clicked();
	void on_lol_clicked();

private:
	Ui::QTestClass ui;
	scnd w;

signals:
	void done(QString);

};
