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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab2_QtDataBaseClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *sin;
    QPushButton *butt;
    QLabel *Logo;
    QRadioButton *show;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *Log_label;
    QLineEdit *log;
    QSpacerItem *verticalSpacer;
    QLabel *Pass_label;
    QLineEdit *pass;
    QWidget *sup;
    QWidget *widget;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *logl;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLineEdit *passl;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *repassl;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *regb;
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
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setTabBarAutoHide(false);
        sin = new QWidget();
        sin->setObjectName(QString::fromUtf8("sin"));
        butt = new QPushButton(sin);
        butt->setObjectName(QString::fromUtf8("butt"));
        butt->setGeometry(QRect(319, 189, 61, 21));
        QFont font;
        font.setPointSize(10);
        butt->setFont(font);
        Logo = new QLabel(sin);
        Logo->setObjectName(QString::fromUtf8("Logo"));
        Logo->setGeometry(QRect(29, 9, 231, 91));
        Logo->setPixmap(QPixmap(QString::fromUtf8("tutu-logo.png")));
        Logo->setScaledContents(true);
        show = new QRadioButton(sin);
        show->setObjectName(QString::fromUtf8("show"));
        show->setGeometry(QRect(189, 189, 91, 21));
        show->setFont(font);
        layoutWidget = new QWidget(sin);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 130, 249, 56));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        Log_label = new QLabel(layoutWidget);
        Log_label->setObjectName(QString::fromUtf8("Log_label"));
        QFont font1;
        font1.setPointSize(12);
        Log_label->setFont(font1);
        Log_label->setTextFormat(Qt::AutoText);

        formLayout->setWidget(0, QFormLayout::LabelRole, Log_label);

        log = new QLineEdit(layoutWidget);
        log->setObjectName(QString::fromUtf8("log"));
        log->setMaximumSize(QSize(16777215, 17));
        log->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, log);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::FieldRole, verticalSpacer);

        Pass_label = new QLabel(layoutWidget);
        Pass_label->setObjectName(QString::fromUtf8("Pass_label"));
        Pass_label->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, Pass_label);

        pass = new QLineEdit(layoutWidget);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setMaximumSize(QSize(16777215, 17));
        pass->setFont(font1);
        pass->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, pass);

        tabWidget->addTab(sin, QString());
        sup = new QWidget();
        sup->setObjectName(QString::fromUtf8("sup"));
        widget = new QWidget(sup);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(110, 50, 221, 111));
        formLayout_2 = new QFormLayout(widget);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        logl = new QLineEdit(widget);
        logl->setObjectName(QString::fromUtf8("logl"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, logl);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout_2->setItem(1, QFormLayout::FieldRole, horizontalSpacer_2);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_2);

        passl = new QLineEdit(widget);
        passl->setObjectName(QString::fromUtf8("passl"));
        passl->setEchoMode(QLineEdit::Password);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, passl);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout_2->setItem(3, QFormLayout::FieldRole, horizontalSpacer);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_3);

        repassl = new QLineEdit(widget);
        repassl->setObjectName(QString::fromUtf8("repassl"));
        repassl->setEchoMode(QLineEdit::Password);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, repassl);

        widget1 = new QWidget(sup);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(210, 170, 118, 19));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        regb = new QPushButton(widget1);
        regb->setObjectName(QString::fromUtf8("regb"));

        horizontalLayout->addWidget(regb);

        tabWidget->addTab(sup, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);

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

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Lab2_QtDataBaseClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lab2_QtDataBaseClass)
    {
        Lab2_QtDataBaseClass->setWindowTitle(QApplication::translate("Lab2_QtDataBaseClass", "Lab2_QtDataBase", nullptr));
        butt->setText(QApplication::translate("Lab2_QtDataBaseClass", "Log in", nullptr));
        Logo->setText(QString());
        show->setText(QApplication::translate("Lab2_QtDataBaseClass", "Show Password", nullptr));
        Log_label->setText(QApplication::translate("Lab2_QtDataBaseClass", "Login", nullptr));
        Pass_label->setText(QApplication::translate("Lab2_QtDataBaseClass", "Password", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(sin), QApplication::translate("Lab2_QtDataBaseClass", "Sign in", nullptr));
        label->setText(QApplication::translate("Lab2_QtDataBaseClass", "Enter login", nullptr));
        label_2->setText(QApplication::translate("Lab2_QtDataBaseClass", "Enter password", nullptr));
        label_3->setText(QApplication::translate("Lab2_QtDataBaseClass", "Re-enter passwword", nullptr));
        regb->setText(QApplication::translate("Lab2_QtDataBaseClass", "Register", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(sup), QApplication::translate("Lab2_QtDataBaseClass", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lab2_QtDataBaseClass: public Ui_Lab2_QtDataBaseClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB2_QTDATABASE_H
