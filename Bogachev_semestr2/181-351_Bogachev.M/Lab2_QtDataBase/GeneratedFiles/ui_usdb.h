/********************************************************************************
** Form generated from reading UI file 'usdb.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USDB_H
#define UI_USDB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_usdb
{
public:
    QFormLayout *formLayout;
    QTableView *tableui;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *delloginl;
    QPushButton *delb;
    QGroupBox *edit;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *logl;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *statl;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *editsubmb;
    QGroupBox *find;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *findl;
    QPushButton *findsubmb;
    QPushButton *findcancb;

    void setupUi(QDialog *usdb)
    {
        if (usdb->objectName().isEmpty())
            usdb->setObjectName(QString::fromUtf8("usdb"));
        usdb->resize(484, 203);
        formLayout = new QFormLayout(usdb);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        tableui = new QTableView(usdb);
        tableui->setObjectName(QString::fromUtf8("tableui"));
        tableui->setShowGrid(true);
        tableui->verticalHeader()->setVisible(false);
        tableui->verticalHeader()->setProperty("showSortIndicator", QVariant(true));

        formLayout->setWidget(0, QFormLayout::LabelRole, tableui);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        delloginl = new QLineEdit(usdb);
        delloginl->setObjectName(QString::fromUtf8("delloginl"));

        horizontalLayout_4->addWidget(delloginl);

        delb = new QPushButton(usdb);
        delb->setObjectName(QString::fromUtf8("delb"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        delb->setFont(font);

        horizontalLayout_4->addWidget(delb);


        verticalLayout_2->addLayout(horizontalLayout_4);

        edit = new QGroupBox(usdb);
        edit->setObjectName(QString::fromUtf8("edit"));
        verticalLayout_4 = new QVBoxLayout(edit);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(edit);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        logl = new QLineEdit(edit);
        logl->setObjectName(QString::fromUtf8("logl"));

        verticalLayout->addWidget(logl);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(edit);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        statl = new QLineEdit(edit);
        statl->setObjectName(QString::fromUtf8("statl"));

        verticalLayout_3->addWidget(statl);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        editsubmb = new QPushButton(edit);
        editsubmb->setObjectName(QString::fromUtf8("editsubmb"));

        horizontalLayout_3->addWidget(editsubmb);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(edit);

        find = new QGroupBox(usdb);
        find->setObjectName(QString::fromUtf8("find"));
        horizontalLayout_2 = new QHBoxLayout(find);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        findl = new QLineEdit(find);
        findl->setObjectName(QString::fromUtf8("findl"));

        horizontalLayout_2->addWidget(findl);

        findsubmb = new QPushButton(find);
        findsubmb->setObjectName(QString::fromUtf8("findsubmb"));

        horizontalLayout_2->addWidget(findsubmb);

        findcancb = new QPushButton(find);
        findcancb->setObjectName(QString::fromUtf8("findcancb"));

        horizontalLayout_2->addWidget(findcancb);


        verticalLayout_2->addWidget(find);


        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout_2);


        retranslateUi(usdb);

        QMetaObject::connectSlotsByName(usdb);
    } // setupUi

    void retranslateUi(QDialog *usdb)
    {
        usdb->setWindowTitle(QApplication::translate("usdb", "usdb", nullptr));
        delloginl->setPlaceholderText(QApplication::translate("usdb", "Login", nullptr));
        delb->setText(QApplication::translate("usdb", "Delete", nullptr));
        edit->setTitle(QApplication::translate("usdb", "Edit", nullptr));
        label_2->setText(QApplication::translate("usdb", "Login", nullptr));
        logl->setPlaceholderText(QString());
        label_3->setText(QApplication::translate("usdb", "New Status", nullptr));
        statl->setPlaceholderText(QString());
        editsubmb->setText(QApplication::translate("usdb", "Edit", nullptr));
        find->setTitle(QApplication::translate("usdb", "Find", nullptr));
        findl->setPlaceholderText(QApplication::translate("usdb", "Search", nullptr));
        findsubmb->setText(QApplication::translate("usdb", "Find", nullptr));
        findcancb->setText(QApplication::translate("usdb", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class usdb: public Ui_usdb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USDB_H
