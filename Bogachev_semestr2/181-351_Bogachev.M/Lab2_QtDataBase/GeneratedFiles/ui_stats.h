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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stats
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *usrnm;
    QLabel *usrnmv;
    QLabel *pss;
    QLabel *pssv;
    QLabel *acclvl;
    QLabel *acl;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QPushButton *editb;
    QPushButton *viewb;

    void setupUi(QWidget *stats)
    {
        if (stats->objectName().isEmpty())
            stats->setObjectName(QString::fromUtf8("stats"));
        stats->resize(351, 188);
        groupBox = new QGroupBox(stats);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 300, 141));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 20, 171, 107));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        usrnm = new QLabel(layoutWidget);
        usrnm->setObjectName(QString::fromUtf8("usrnm"));

        formLayout->setWidget(0, QFormLayout::LabelRole, usrnm);

        usrnmv = new QLabel(layoutWidget);
        usrnmv->setObjectName(QString::fromUtf8("usrnmv"));
        usrnmv->setLayoutDirection(Qt::LeftToRight);
        usrnmv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, usrnmv);

        pss = new QLabel(layoutWidget);
        pss->setObjectName(QString::fromUtf8("pss"));

        formLayout->setWidget(1, QFormLayout::LabelRole, pss);

        pssv = new QLabel(layoutWidget);
        pssv->setObjectName(QString::fromUtf8("pssv"));
        pssv->setLayoutDirection(Qt::LeftToRight);
        pssv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, pssv);

        acclvl = new QLabel(layoutWidget);
        acclvl->setObjectName(QString::fromUtf8("acclvl"));

        formLayout->setWidget(2, QFormLayout::LabelRole, acclvl);

        acl = new QLabel(layoutWidget);
        acl->setObjectName(QString::fromUtf8("acl"));
        acl->setLayoutDirection(Qt::LeftToRight);
        acl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, acl);


        verticalLayout->addLayout(formLayout);

        line = new QFrame(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        editb = new QPushButton(layoutWidget);
        editb->setObjectName(QString::fromUtf8("editb"));
        editb->setAutoFillBackground(false);

        horizontalLayout->addWidget(editb);

        viewb = new QPushButton(layoutWidget);
        viewb->setObjectName(QString::fromUtf8("viewb"));

        horizontalLayout->addWidget(viewb);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(stats);

        QMetaObject::connectSlotsByName(stats);
    } // setupUi

    void retranslateUi(QWidget *stats)
    {
        stats->setWindowTitle(QApplication::translate("stats", "stats", nullptr));
        groupBox->setTitle(QApplication::translate("stats", "User data", nullptr));
        usrnm->setText(QApplication::translate("stats", "Username:", nullptr));
        usrnmv->setText(QApplication::translate("stats", "TextLabel", nullptr));
        pss->setText(QApplication::translate("stats", "Password:", nullptr));
        pssv->setText(QApplication::translate("stats", "TextLabel", nullptr));
        acclvl->setText(QApplication::translate("stats", "Access level:", nullptr));
        acl->setText(QApplication::translate("stats", "TextLabel", nullptr));
        editb->setText(QApplication::translate("stats", "View users table", nullptr));
        viewb->setText(QApplication::translate("stats", "View trains table", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stats: public Ui_stats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATS_H
