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

QT_BEGIN_NAMESPACE

class Ui_inputw
{
public:

    void setupUi(QDialog *inputw)
    {
        if (inputw->objectName().isEmpty())
            inputw->setObjectName(QString::fromUtf8("inputw"));
        inputw->resize(400, 300);

        retranslateUi(inputw);

        QMetaObject::connectSlotsByName(inputw);
    } // setupUi

    void retranslateUi(QDialog *inputw)
    {
        inputw->setWindowTitle(QApplication::translate("inputw", "inputw", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inputw: public Ui_inputw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTW_H
