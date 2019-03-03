#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_siska.h"

class siska : public QMainWindow
{
	Q_OBJECT

public:
	siska(QWidget *parent = Q_NULLPTR);

private:
	Ui::siskaClass ui;
};
