/********************************************************************************
** Form generated from reading UI file 'editreq.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITREQ_H
#define UI_EDITREQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editreq
{
public:
    QLabel *label;
    QLineEdit *numl;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *okb;
    QPushButton *cancb;

    void setupUi(QDialog *editreq)
    {
        if (editreq->objectName().isEmpty())
            editreq->setObjectName(QString::fromUtf8("editreq"));
        editreq->resize(219, 82);
        label = new QLabel(editreq);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(22, 5, 193, 28));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setWordWrap(true);
        numl = new QLineEdit(editreq);
        numl->setObjectName(QString::fromUtf8("numl"));
        numl->setGeometry(QRect(20, 37, 193, 18));
        numl->setFont(font);
        layoutWidget = new QWidget(editreq);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 60, 118, 19));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        okb = new QPushButton(layoutWidget);
        okb->setObjectName(QString::fromUtf8("okb"));

        horizontalLayout->addWidget(okb);

        cancb = new QPushButton(layoutWidget);
        cancb->setObjectName(QString::fromUtf8("cancb"));

        horizontalLayout->addWidget(cancb);


        retranslateUi(editreq);

        QMetaObject::connectSlotsByName(editreq);
    } // setupUi

    void retranslateUi(QDialog *editreq)
    {
        editreq->setWindowTitle(QApplication::translate("editreq", "editreq", nullptr));
        label->setText(QApplication::translate("editreq", "Insert the ID of the line, you want to edit.", nullptr));
        okb->setText(QApplication::translate("editreq", "OK", nullptr));
        cancb->setText(QApplication::translate("editreq", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editreq: public Ui_editreq {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITREQ_H
