#include "scnd.h"

scnd::scnd(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

scnd::~scnd()
{
}

void scnd::stupid(QString a)
{
	ui.label->setText(a);
}
