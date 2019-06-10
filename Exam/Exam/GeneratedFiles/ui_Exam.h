/********************************************************************************
** Form generated from reading UI file 'Exam.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAM_H
#define UI_EXAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamClass
{
public:
    QWidget *centralWidget;
    QLabel *png1;
    QLabel *png2;
    QLineEdit *line;
    QLabel *hash;
    QPushButton *hashb;
    QPushButton *showb;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *ExamClass)
    {
        if (ExamClass->objectName().isEmpty())
            ExamClass->setObjectName(QString::fromUtf8("ExamClass"));
        ExamClass->resize(442, 250);
        centralWidget = new QWidget(ExamClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        png1 = new QLabel(centralWidget);
        png1->setObjectName(QString::fromUtf8("png1"));
        png1->setGeometry(QRect(10, 10, 191, 151));
        png1->setPixmap(QPixmap(QString::fromUtf8("ARP.jpg")));
        png1->setScaledContents(true);
        png2 = new QLabel(centralWidget);
        png2->setObjectName(QString::fromUtf8("png2"));
        png2->setGeometry(QRect(230, 10, 191, 151));
        png2->setScaledContents(true);
        line = new QLineEdit(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 170, 191, 20));
        hash = new QLabel(centralWidget);
        hash->setObjectName(QString::fromUtf8("hash"));
        hash->setGeometry(QRect(230, 170, 201, 20));
        hashb = new QPushButton(centralWidget);
        hashb->setObjectName(QString::fromUtf8("hashb"));
        hashb->setGeometry(QRect(40, 200, 141, 20));
        showb = new QPushButton(centralWidget);
        showb->setObjectName(QString::fromUtf8("showb"));
        showb->setGeometry(QRect(250, 200, 151, 20));
        ExamClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(ExamClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ExamClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(ExamClass);

        QMetaObject::connectSlotsByName(ExamClass);
    } // setupUi

    void retranslateUi(QMainWindow *ExamClass)
    {
        ExamClass->setWindowTitle(QApplication::translate("ExamClass", "Exam", nullptr));
        png1->setText(QString());
        png2->setText(QString());
        hash->setText(QString());
        hashb->setText(QApplication::translate("ExamClass", "Get hash", nullptr));
        showb->setText(QApplication::translate("ExamClass", "Embend into image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExamClass: public Ui_ExamClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAM_H
