/********************************************************************************
** Form generated from reading UI file 'stats.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATS_H
#define UI_STATS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stats
{
public:
    QRadioButton *radioButton;
    QPushButton *pushButton;

    void setupUi(QWidget *stats)
    {
        if (stats->objectName().isEmpty())
            stats->setObjectName(QString::fromUtf8("stats"));
        stats->resize(400, 300);
        radioButton = new QRadioButton(stats);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(40, 150, 62, 14));
        pushButton = new QPushButton(stats);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(105, 80, 151, 51));

        retranslateUi(stats);

        QMetaObject::connectSlotsByName(stats);
    } // setupUi

    void retranslateUi(QWidget *stats)
    {
        stats->setWindowTitle(QApplication::translate("stats", "stats", nullptr));
        radioButton->setText(QApplication::translate("stats", "RadioButton", nullptr));
        pushButton->setText(QApplication::translate("stats", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stats: public Ui_stats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATS_H
