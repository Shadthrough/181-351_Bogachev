/********************************************************************************
** Form generated from reading UI file 'db.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DB_H
#define UI_DB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_db
{
public:
    QTableView *tableui;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *db)
    {
        if (db->objectName().isEmpty())
            db->setObjectName(QString::fromUtf8("db"));
        db->resize(400, 300);
        tableui = new QTableView(db);
        tableui->setObjectName(QString::fromUtf8("tableui"));
        tableui->setGeometry(QRect(40, 20, 301, 211));
        tableui->setShowGrid(true);
        widget = new QWidget(db);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 240, 271, 19));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        retranslateUi(db);

        QMetaObject::connectSlotsByName(db);
    } // setupUi

    void retranslateUi(QDialog *db)
    {
        db->setWindowTitle(QApplication::translate("db", "db", nullptr));
        pushButton->setText(QApplication::translate("db", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("db", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("db", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class db: public Ui_db {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DB_H
