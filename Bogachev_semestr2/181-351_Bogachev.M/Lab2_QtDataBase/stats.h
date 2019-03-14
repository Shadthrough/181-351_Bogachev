#pragma once

#include <QDialog>
#include "ui_stats.h"

class stats : public QDialog
{
	Q_OBJECT

public:
	stats(QWidget *parent = Q_NULLPTR);
	~stats();

private:
	Ui::stats ui;
};
