/********************************************************************************
** Form generated from reading UI file 'inpdel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPDEL_H
#define UI_INPDEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_inpdel
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *numl;
    QPushButton *okb;

    void setupUi(QDialog *inpdel)
    {
        if (inpdel->objectName().isEmpty())
            inpdel->setObjectName(QString::fromUtf8("inpdel"));
        inpdel->resize(208, 90);
        formLayout = new QFormLayout(inpdel);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(inpdel);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        numl = new QLineEdit(inpdel);
        numl->setObjectName(QString::fromUtf8("numl"));
        numl->setFont(font);

        verticalLayout->addWidget(numl);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        okb = new QPushButton(inpdel);
        okb->setObjectName(QString::fromUtf8("okb"));

        formLayout->setWidget(1, QFormLayout::LabelRole, okb);


        retranslateUi(inpdel);

        QMetaObject::connectSlotsByName(inpdel);
    } // setupUi

    void retranslateUi(QDialog *inpdel)
    {
        inpdel->setWindowTitle(QApplication::translate("inpdel", "inpdel", nullptr));
        label->setText(QApplication::translate("inpdel", "Insert the number of the line, you want to delete.", nullptr));
        okb->setText(QApplication::translate("inpdel", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inpdel: public Ui_inpdel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPDEL_H
