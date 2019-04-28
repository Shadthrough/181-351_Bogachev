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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_db
{
public:
    QGridLayout *gridLayout;
    QTableView *tableui;
    QVBoxLayout *verticalLayout;
    QPushButton *addb;
    QPushButton *findb;
    QPushButton *delb;
    QPushButton *refrb;
    QLineEdit *trainl;
    QLineEdit *pricel;
    QPushButton *editb;
    QLineEdit *compl;
    QLineEdit *soldl;

    void setupUi(QDialog *db)
    {
        if (db->objectName().isEmpty())
            db->setObjectName(QString::fromUtf8("db"));
        db->resize(462, 314);
        gridLayout = new QGridLayout(db);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableui = new QTableView(db);
        tableui->setObjectName(QString::fromUtf8("tableui"));
        tableui->setShowGrid(true);

        gridLayout->addWidget(tableui, 0, 0, 1, 4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addb = new QPushButton(db);
        addb->setObjectName(QString::fromUtf8("addb"));

        verticalLayout->addWidget(addb);

        findb = new QPushButton(db);
        findb->setObjectName(QString::fromUtf8("findb"));

        verticalLayout->addWidget(findb);

        delb = new QPushButton(db);
        delb->setObjectName(QString::fromUtf8("delb"));

        verticalLayout->addWidget(delb);


        gridLayout->addLayout(verticalLayout, 1, 0, 2, 1);

        refrb = new QPushButton(db);
        refrb->setObjectName(QString::fromUtf8("refrb"));

        gridLayout->addWidget(refrb, 1, 1, 1, 1);

        trainl = new QLineEdit(db);
        trainl->setObjectName(QString::fromUtf8("trainl"));

        gridLayout->addWidget(trainl, 1, 2, 1, 1);

        pricel = new QLineEdit(db);
        pricel->setObjectName(QString::fromUtf8("pricel"));

        gridLayout->addWidget(pricel, 1, 3, 1, 1);

        editb = new QPushButton(db);
        editb->setObjectName(QString::fromUtf8("editb"));

        gridLayout->addWidget(editb, 2, 1, 1, 1);

        compl = new QLineEdit(db);
        compl->setObjectName(QString::fromUtf8("compl"));

        gridLayout->addWidget(compl, 2, 2, 1, 1);

        soldl = new QLineEdit(db);
        soldl->setObjectName(QString::fromUtf8("soldl"));

        gridLayout->addWidget(soldl, 2, 3, 1, 1);


        retranslateUi(db);

        QMetaObject::connectSlotsByName(db);
    } // setupUi

    void retranslateUi(QDialog *db)
    {
        db->setWindowTitle(QApplication::translate("db", "db", nullptr));
        addb->setText(QApplication::translate("db", "Add", nullptr));
        findb->setText(QApplication::translate("db", "Find", nullptr));
        delb->setText(QApplication::translate("db", "Delete", nullptr));
        refrb->setText(QApplication::translate("db", "Refresh", nullptr));
        trainl->setPlaceholderText(QApplication::translate("db", "Train", nullptr));
        pricel->setPlaceholderText(QApplication::translate("db", "Price", nullptr));
        editb->setText(QApplication::translate("db", "Edit", nullptr));
        compl->setPlaceholderText(QApplication::translate("db", "Company", nullptr));
        soldl->setPlaceholderText(QApplication::translate("db", "Sold/Not sold", nullptr));
    } // retranslateUi

};

namespace Ui {
    class db: public Ui_db {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DB_H
