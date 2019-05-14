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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QPushButton *addb;
    QPushButton *delb;
    QPushButton *editb;
    QPushButton *findb;
    QPushButton *findb_2;
    QGroupBox *edit;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *numt;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *trainel;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLineEdit *pricel;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLineEdit *compel;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QLineEdit *soldel;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *editsubmb;
    QPushButton *editcancb;
    QGroupBox *find;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *findl;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *findsubmb;
    QPushButton *findcancb;
    QGroupBox *find_2;
    QFormLayout *formLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QLineEdit *trainel_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_7;
    QLineEdit *pricel_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_8;
    QLineEdit *compel_2;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_9;
    QLineEdit *soldel_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *findsubmb_2;
    QPushButton *findcancb_2;

    void setupUi(QDialog *db)
    {
        if (db->objectName().isEmpty())
            db->setObjectName(QString::fromUtf8("db"));
        db->resize(441, 439);
        gridLayout = new QGridLayout(db);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableui = new QTableView(db);
        tableui->setObjectName(QString::fromUtf8("tableui"));
        tableui->setShowGrid(true);
        tableui->verticalHeader()->setVisible(false);
        tableui->verticalHeader()->setProperty("showSortIndicator", QVariant(true));

        gridLayout->addWidget(tableui, 0, 0, 1, 5);

        addb = new QPushButton(db);
        addb->setObjectName(QString::fromUtf8("addb"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        addb->setFont(font);

        gridLayout->addWidget(addb, 1, 0, 1, 1);

        delb = new QPushButton(db);
        delb->setObjectName(QString::fromUtf8("delb"));
        delb->setFont(font);

        gridLayout->addWidget(delb, 1, 1, 1, 1);

        editb = new QPushButton(db);
        editb->setObjectName(QString::fromUtf8("editb"));
        editb->setFont(font);

        gridLayout->addWidget(editb, 1, 2, 1, 1);

        findb = new QPushButton(db);
        findb->setObjectName(QString::fromUtf8("findb"));
        findb->setFont(font);

        gridLayout->addWidget(findb, 1, 3, 1, 1);

        findb_2 = new QPushButton(db);
        findb_2->setObjectName(QString::fromUtf8("findb_2"));
        findb_2->setFont(font);

        gridLayout->addWidget(findb_2, 1, 4, 1, 1);

        edit = new QGroupBox(db);
        edit->setObjectName(QString::fromUtf8("edit"));
        formLayout = new QFormLayout(edit);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(edit);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        numt = new QLabel(edit);
        numt->setObjectName(QString::fromUtf8("numt"));

        formLayout->setWidget(1, QFormLayout::LabelRole, numt);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(edit);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        trainel = new QLineEdit(edit);
        trainel->setObjectName(QString::fromUtf8("trainel"));

        verticalLayout->addWidget(trainel);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(edit);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);

        pricel = new QLineEdit(edit);
        pricel->setObjectName(QString::fromUtf8("pricel"));

        verticalLayout_4->addWidget(pricel);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(edit);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        compel = new QLineEdit(edit);
        compel->setObjectName(QString::fromUtf8("compel"));

        verticalLayout_3->addWidget(compel);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_5 = new QLabel(edit);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        soldel = new QLineEdit(edit);
        soldel->setObjectName(QString::fromUtf8("soldel"));

        verticalLayout_2->addWidget(soldel);


        horizontalLayout->addLayout(verticalLayout_2);


        formLayout->setLayout(3, QFormLayout::SpanningRole, horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        editsubmb = new QPushButton(edit);
        editsubmb->setObjectName(QString::fromUtf8("editsubmb"));

        horizontalLayout_3->addWidget(editsubmb);

        editcancb = new QPushButton(edit);
        editcancb->setObjectName(QString::fromUtf8("editcancb"));

        horizontalLayout_3->addWidget(editcancb);


        formLayout->setLayout(4, QFormLayout::LabelRole, horizontalLayout_3);


        gridLayout->addWidget(edit, 2, 0, 1, 5);

        find = new QGroupBox(db);
        find->setObjectName(QString::fromUtf8("find"));
        horizontalLayout_2 = new QHBoxLayout(find);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        findl = new QLineEdit(find);
        findl->setObjectName(QString::fromUtf8("findl"));

        horizontalLayout_2->addWidget(findl);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        findsubmb = new QPushButton(find);
        findsubmb->setObjectName(QString::fromUtf8("findsubmb"));

        horizontalLayout_6->addWidget(findsubmb);

        findcancb = new QPushButton(find);
        findcancb->setObjectName(QString::fromUtf8("findcancb"));

        horizontalLayout_6->addWidget(findcancb);


        horizontalLayout_2->addLayout(horizontalLayout_6);


        gridLayout->addWidget(find, 3, 0, 1, 3);

        find_2 = new QGroupBox(db);
        find_2->setObjectName(QString::fromUtf8("find_2"));
        formLayout_2 = new QFormLayout(find_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_6 = new QLabel(find_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_5->addWidget(label_6);

        trainel_2 = new QLineEdit(find_2);
        trainel_2->setObjectName(QString::fromUtf8("trainel_2"));

        verticalLayout_5->addWidget(trainel_2);


        horizontalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_7 = new QLabel(find_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_6->addWidget(label_7);

        pricel_2 = new QLineEdit(find_2);
        pricel_2->setObjectName(QString::fromUtf8("pricel_2"));

        verticalLayout_6->addWidget(pricel_2);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_8 = new QLabel(find_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_7->addWidget(label_8);

        compel_2 = new QLineEdit(find_2);
        compel_2->setObjectName(QString::fromUtf8("compel_2"));

        verticalLayout_7->addWidget(compel_2);


        horizontalLayout_4->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_9 = new QLabel(find_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_8->addWidget(label_9);

        soldel_2 = new QLineEdit(find_2);
        soldel_2->setObjectName(QString::fromUtf8("soldel_2"));

        verticalLayout_8->addWidget(soldel_2);


        horizontalLayout_4->addLayout(verticalLayout_8);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        findsubmb_2 = new QPushButton(find_2);
        findsubmb_2->setObjectName(QString::fromUtf8("findsubmb_2"));

        horizontalLayout_5->addWidget(findsubmb_2);

        findcancb_2 = new QPushButton(find_2);
        findcancb_2->setObjectName(QString::fromUtf8("findcancb_2"));

        horizontalLayout_5->addWidget(findcancb_2);


        formLayout_2->setLayout(1, QFormLayout::LabelRole, horizontalLayout_5);


        gridLayout->addWidget(find_2, 4, 0, 1, 5);


        retranslateUi(db);

        QMetaObject::connectSlotsByName(db);
    } // setupUi

    void retranslateUi(QDialog *db)
    {
        db->setWindowTitle(QApplication::translate("db", "db", nullptr));
        addb->setText(QApplication::translate("db", "Add", nullptr));
        delb->setText(QApplication::translate("db", "Delete", nullptr));
        editb->setText(QApplication::translate("db", "Edit", nullptr));
        findb->setText(QApplication::translate("db", "Find Text", nullptr));
        findb_2->setText(QApplication::translate("db", "Find", nullptr));
        edit->setTitle(QApplication::translate("db", "Edit", nullptr));
        label->setText(QApplication::translate("db", "Line number:", nullptr));
        numt->setText(QApplication::translate("db", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("db", "Train", nullptr));
        trainel->setPlaceholderText(QString());
        label_3->setText(QApplication::translate("db", "Price", nullptr));
        pricel->setPlaceholderText(QString());
        label_4->setText(QApplication::translate("db", "Company", nullptr));
        compel->setPlaceholderText(QString());
        label_5->setText(QApplication::translate("db", "Sold/Not sold", nullptr));
        soldel->setPlaceholderText(QString());
        editsubmb->setText(QApplication::translate("db", "Edit", nullptr));
        editcancb->setText(QApplication::translate("db", "Cancel", nullptr));
        find->setTitle(QApplication::translate("db", "Find Text", nullptr));
        findl->setPlaceholderText(QApplication::translate("db", "Search", nullptr));
        findsubmb->setText(QApplication::translate("db", "Find", nullptr));
        findcancb->setText(QApplication::translate("db", "Cancel", nullptr));
        find_2->setTitle(QApplication::translate("db", "Find", nullptr));
        label_6->setText(QApplication::translate("db", "Train", nullptr));
        trainel_2->setPlaceholderText(QString());
        label_7->setText(QApplication::translate("db", "Price", nullptr));
        pricel_2->setPlaceholderText(QString());
        label_8->setText(QApplication::translate("db", "Company", nullptr));
        compel_2->setPlaceholderText(QString());
        label_9->setText(QApplication::translate("db", "Sold/Not sold", nullptr));
        soldel_2->setPlaceholderText(QString());
        findsubmb_2->setText(QApplication::translate("db", "Find", nullptr));
        findcancb_2->setText(QApplication::translate("db", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class db: public Ui_db {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DB_H
