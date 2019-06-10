#pragma once

#include <QWidget>
#include "ui_scnd.h"

class scnd : public QWidget
{
	Q_OBJECT

public:
	scnd(QWidget *parent = Q_NULLPTR);
	~scnd();

public slots:
	void stupid(QString);

private:
	Ui::scnd ui;
};
