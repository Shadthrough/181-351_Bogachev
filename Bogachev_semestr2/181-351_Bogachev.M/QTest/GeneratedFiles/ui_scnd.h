/********************************************************************************
** Form generated from reading UI file 'scnd.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCND_H
#define UI_SCND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_scnd
{
public:
    QLabel *label;

    void setupUi(QWidget *scnd)
    {
        if (scnd->objectName().isEmpty())
            scnd->setObjectName(QString::fromUtf8("scnd"));
        scnd->resize(249, 245);
        label = new QLabel(scnd);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 171, 161));

        retranslateUi(scnd);

        QMetaObject::connectSlotsByName(scnd);
    } // setupUi

    void retranslateUi(QWidget *scnd)
    {
        scnd->setWindowTitle(QApplication::translate("scnd", "scnd", nullptr));
        label->setText(QApplication::translate("scnd", "Shit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class scnd: public Ui_scnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCND_H
