#ifndef LOGIN_WIN_H
#define LOGIN_WIN_H

#include <QMainWindow>

namespace Ui {
class Login_win;
}

class Login_win : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login_win(QWidget *parent = nullptr);
    ~Login_win();

//private slots:
    /*void on_Login_clicked(Login_win *a, stats *s);*/

private slots:
    void on_Login_clicked();

private:
    Ui::Login_win *ui;
};

#endif // LOGIN_WIN_H
