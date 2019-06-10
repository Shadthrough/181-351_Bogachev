/********************************************************************************
** Form generated from reading UI file 'QTest.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTEST_H
#define UI_QTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTestClass
{
public:
    QWidget *centralWidget;
    QPushButton *butt;
    QPushButton *lol;

    void setupUi(QMainWindow *QTestClass)
    {
        if (QTestClass->objectName().isEmpty())
            QTestClass->setObjectName(QString::fromUtf8("QTestClass"));
        QTestClass->resize(261, 174);
        centralWidget = new QWidget(QTestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        butt = new QPushButton(centralWidget);
        butt->setObjectName(QString::fromUtf8("butt"));
        butt->setGeometry(QRect(90, 70, 81, 31));
        lol = new QPushButton(centralWidget);
        lol->setObjectName(QString::fromUtf8("lol"));
        lol->setGeometry(QRect(100, 40, 56, 17));
        QTestClass->setCentralWidget(centralWidget);

        retranslateUi(QTestClass);

        QMetaObject::connectSlotsByName(QTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QTestClass)
    {
        QTestClass->setWindowTitle(QApplication::translate("QTestClass", "QTest", nullptr));
        butt->setText(QApplication::translate("QTestClass", "PushButton", nullptr));
        lol->setText(QApplication::translate("QTestClass", "LOL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QTestClass: public Ui_QTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTEST_H
