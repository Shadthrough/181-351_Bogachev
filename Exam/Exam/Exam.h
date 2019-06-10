#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Exam.h"
#include <openssl/sha.h>
#include <string>
#include <qdebug.h>

class Exam : public QMainWindow
{
	Q_OBJECT

public:
	Exam(QWidget *parent = Q_NULLPTR);
public slots:
	void on_hashb_clicked();
	void on_showb_clicked();

private:
	Ui::ExamClass ui;
};
