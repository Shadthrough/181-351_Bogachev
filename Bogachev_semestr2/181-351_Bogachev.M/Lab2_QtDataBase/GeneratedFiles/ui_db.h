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
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_db
{
public:
    QLabel *test;
    QTextBrowser *testb;

    void setupUi(QDialog *db)
    {
        if (db->objectName().isEmpty())
            db->setObjectName(QString::fromUtf8("db"));
        db->resize(400, 300);
        test = new QLabel(db);
        test->setObjectName(QString::fromUtf8("test"));
        test->setGeometry(QRect(20, 70, 91, 20));
        testb = new QTextBrowser(db);
        testb->setObjectName(QString::fromUtf8("testb"));
        testb->setGeometry(QRect(130, 50, 256, 192));

        retranslateUi(db);

        QMetaObject::connectSlotsByName(db);
    } // setupUi

    void retranslateUi(QDialog *db)
    {
        db->setWindowTitle(QApplication::translate("db", "db", nullptr));
        test->setText(QApplication::translate("db", "TextLabel", nullptr));
        testb->setHtml(QApplication::translate("db", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Rofl</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class db: public Ui_db {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DB_H
