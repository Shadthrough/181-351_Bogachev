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
#include <QtWidgets/QComboBox>
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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *idl;
    QLineEdit *trainl;
    QLineEdit *pricel;
    QLineEdit *compl;
    QComboBox *select;

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
        layoutWidget = new QWidget(inputw);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 18, 291, 97));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        idl = new QLineEdit(layoutWidget);
        idl->setObjectName(QString::fromUtf8("idl"));

        verticalLayout->addWidget(idl);

        trainl = new QLineEdit(layoutWidget);
        trainl->setObjectName(QString::fromUtf8("trainl"));

        verticalLayout->addWidget(trainl);

        pricel = new QLineEdit(layoutWidget);
        pricel->setObjectName(QString::fromUtf8("pricel"));

        verticalLayout->addWidget(pricel);

        compl = new QLineEdit(layoutWidget);
        compl->setObjectName(QString::fromUtf8("compl"));

        verticalLayout->addWidget(compl);

        select = new QComboBox(layoutWidget);
        select->addItem(QString());
        select->addItem(QString());
        select->setObjectName(QString::fromUtf8("select"));

        verticalLayout->addWidget(select);


        retranslateUi(inputw);

        select->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(inputw);
    } // setupUi

    void retranslateUi(QDialog *inputw)
    {
        inputw->setWindowTitle(QApplication::translate("inputw", "inputw", nullptr));
        okb->setText(QApplication::translate("inputw", "OK", nullptr));
        idl->setPlaceholderText(QApplication::translate("inputw", "ID", nullptr));
        trainl->setPlaceholderText(QApplication::translate("inputw", "Train", nullptr));
        pricel->setPlaceholderText(QApplication::translate("inputw", "Price", nullptr));
        compl->setPlaceholderText(QApplication::translate("inputw", "Company", nullptr));
        select->setItemText(0, QApplication::translate("inputw", "Sold", nullptr));
        select->setItemText(1, QApplication::translate("inputw", "Not sold", nullptr));

        select->setCurrentText(QApplication::translate("inputw", "Sold", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inputw: public Ui_inputw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTW_H
