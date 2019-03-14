#include "login_win.h"
#include "ui_login_win.h"

Login_win::Login_win(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login_win)
{
    ui->setupUi(this);
}

Login_win::~Login_win()
{
    delete ui;
}




/*void Login_win::on_Login_clicked(Login_win *a, stats *s)
{
    a->close();
    s->show();
}*/

void Login_win::on_Login_clicked()
{
    QApplication::quit();
}
