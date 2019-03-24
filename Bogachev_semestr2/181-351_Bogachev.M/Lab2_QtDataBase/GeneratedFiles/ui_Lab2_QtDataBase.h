/********************************************************************************
** Form generated from reading UI file 'Lab2_QtDataBase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB2_QTDATABASE_H
#define UI_LAB2_QTDATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab2_QtDataBaseClass
{
public:
    QWidget *centralWidget;
    QLabel *Logo;
    QPushButton *butt;
    QRadioButton *show;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *Log_label;
    QLineEdit *log;
    QSpacerItem *verticalSpacer;
    QLabel *Pass_label;
    QLineEdit *pass;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lab2_QtDataBaseClass)
    {
        if (Lab2_QtDataBaseClass->objectName().isEmpty())
            Lab2_QtDataBaseClass->setObjectName(QString::fromUtf8("Lab2_QtDataBaseClass"));
        Lab2_QtDataBaseClass->resize(504, 297);
        centralWidget = new QWidget(Lab2_QtDataBaseClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(504, 253));
        Logo = new QLabel(centralWidget);
        Logo->setObjectName(QString::fromUtf8("Logo"));
        Logo->setGeometry(QRect(30, 20, 231, 91));
        Logo->setPixmap(QPixmap(QString::fromUtf8("tutu-logo.png")));
        Logo->setScaledContents(true);
        butt = new QPushButton(centralWidget);
        butt->setObjectName(QString::fromUtf8("butt"));
        butt->setGeometry(QRect(320, 200, 61, 21));
        QFont font;
        font.setPointSize(10);
        butt->setFont(font);
        show = new QRadioButton(centralWidget);
        show->setObjectName(QString::fromUtf8("show"));
        show->setGeometry(QRect(190, 200, 91, 21));
        show->setFont(font);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(131, 141, 249, 56));
        formLayout = new QFormLayout(widget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        Log_label = new QLabel(widget);
        Log_label->setObjectName(QString::fromUtf8("Log_label"));
        QFont font1;
        font1.setPointSize(12);
        Log_label->setFont(font1);
        Log_label->setTextFormat(Qt::AutoText);

        formLayout->setWidget(0, QFormLayout::LabelRole, Log_label);

        log = new QLineEdit(widget);
        log->setObjectName(QString::fromUtf8("log"));
        log->setMaximumSize(QSize(16777215, 17));
        log->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, log);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::FieldRole, verticalSpacer);

        Pass_label = new QLabel(widget);
        Pass_label->setObjectName(QString::fromUtf8("Pass_label"));
        Pass_label->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, Pass_label);

        pass = new QLineEdit(widget);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setMaximumSize(QSize(16777215, 17));
        pass->setFont(font1);
        pass->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, pass);

        Lab2_QtDataBaseClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Lab2_QtDataBaseClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 504, 18));
        Lab2_QtDataBaseClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lab2_QtDataBaseClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Lab2_QtDataBaseClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Lab2_QtDataBaseClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Lab2_QtDataBaseClass->setStatusBar(statusBar);

        retranslateUi(Lab2_QtDataBaseClass);

        QMetaObject::connectSlotsByName(Lab2_QtDataBaseClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lab2_QtDataBaseClass)
    {
        Lab2_QtDataBaseClass->setWindowTitle(QApplication::translate("Lab2_QtDataBaseClass", "Lab2_QtDataBase", nullptr));
        Logo->setText(QString());
        butt->setText(QApplication::translate("Lab2_QtDataBaseClass", "Log in", nullptr));
        show->setText(QApplication::translate("Lab2_QtDataBaseClass", "Show Password", nullptr));
        Log_label->setText(QApplication::translate("Lab2_QtDataBaseClass", "Login", nullptr));
        Pass_label->setText(QApplication::translate("Lab2_QtDataBaseClass", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lab2_QtDataBaseClass: public Ui_Lab2_QtDataBaseClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB2_QTDATABASE_H
