#pragma once

#include <QDialog>
#include "ui_inputw.h"

class inputw : public QDialog
{
	Q_OBJECT

public:
	inputw(QWidget *parent = Q_NULLPTR);
	~inputw();

private:
	Ui::inputw ui;
};
