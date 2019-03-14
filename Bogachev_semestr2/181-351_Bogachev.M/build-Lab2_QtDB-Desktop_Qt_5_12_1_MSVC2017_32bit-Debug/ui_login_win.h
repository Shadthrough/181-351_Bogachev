/********************************************************************************
** Form generated from reading UI file 'login_win.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_WIN_H
#define UI_LOGIN_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login_win
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *log_label;
    QLabel *pass_label;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *Login;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Login_win)
    {
        if (Login_win->objectName().isEmpty())
            Login_win->setObjectName(QString::fromUtf8("Login_win"));
        Login_win->resize(364, 281);
        centralWidget = new QWidget(Login_win);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        log_label = new QLabel(centralWidget);
        log_label->setObjectName(QString::fromUtf8("log_label"));
        QFont font;
        font.setPointSize(12);
        log_label->setFont(font);

        verticalLayout->addWidget(log_label);

        pass_label = new QLabel(centralWidget);
        pass_label->setObjectName(QString::fromUtf8("pass_label"));
        pass_label->setFont(font);

        verticalLayout->addWidget(pass_label);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        Login = new QPushButton(centralWidget);
        Login->setObjectName(QString::fromUtf8("Login"));
        QFont font1;
        font1.setPointSize(10);
        Login->setFont(font1);

        gridLayout->addWidget(Login, 2, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8("tutu-logo.png")));
        label->setScaledContents(true);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        Login_win->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Login_win);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 364, 17));
        Login_win->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Login_win);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Login_win->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Login_win);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Login_win->setStatusBar(statusBar);

        retranslateUi(Login_win);

        QMetaObject::connectSlotsByName(Login_win);
    } // setupUi

    void retranslateUi(QMainWindow *Login_win)
    {
        Login_win->setWindowTitle(QApplication::translate("Login_win", "Login_win", nullptr));
        log_label->setText(QApplication::translate("Login_win", "Login", nullptr));
        pass_label->setText(QApplication::translate("Login_win", "Password", nullptr));
        Login->setText(QApplication::translate("Login_win", "Log in", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login_win: public Ui_Login_win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_WIN_H
