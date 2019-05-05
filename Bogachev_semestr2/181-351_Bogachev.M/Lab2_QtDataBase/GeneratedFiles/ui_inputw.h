/********************************************************************************
** Form generated from reading UI file 'inputw.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTW_H
#define UI_INPUTW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inputw
{
public:
    QPushButton *okb;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *trainl;
    QLineEdit *pricel;
    QLineEdit *compl;
    QLineEdit *soldl;

    void setupUi(QDialog *inputw)
    {
        if (inputw->objectName().isEmpty())
            inputw->setObjectName(QString::fromUtf8("inputw"));
        inputw->resize(312, 169);
        okb = new QPushButton(inputw);
        okb->setObjectName(QString::fromUtf8("okb"));
        okb->setGeometry(QRect(230, 120, 71, 31));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        okb->setFont(font);
        widget = new QWidget(inputw);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 18, 291, 91));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        trainl = new QLineEdit(widget);
        trainl->setObjectName(QString::fromUtf8("trainl"));

        verticalLayout->addWidget(trainl);

        pricel = new QLineEdit(widget);
        pricel->setObjectName(QString::fromUtf8("pricel"));

        verticalLayout->addWidget(pricel);

        compl = new QLineEdit(widget);
        compl->setObjectName(QString::fromUtf8("compl"));

        verticalLayout->addWidget(compl);

        soldl = new QLineEdit(widget);
        soldl->setObjectName(QString::fromUtf8("soldl"));

        verticalLayout->addWidget(soldl);


        retranslateUi(inputw);

        QMetaObject::connectSlotsByName(inputw);
    } // setupUi

    void retranslateUi(QDialog *inputw)
    {
        inputw->setWindowTitle(QApplication::translate("inputw", "inputw", nullptr));
        okb->setText(QApplication::translate("inputw", "OK", nullptr));
        trainl->setPlaceholderText(QApplication::translate("inputw", "Train", nullptr));
        pricel->setPlaceholderText(QApplication::translate("inputw", "Price", nullptr));
        compl->setPlaceholderText(QApplication::translate("inputw", "Company", nullptr));
        soldl->setPlaceholderText(QApplication::translate("inputw", "Sold/Not sold", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inputw: public Ui_inputw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTW_H
