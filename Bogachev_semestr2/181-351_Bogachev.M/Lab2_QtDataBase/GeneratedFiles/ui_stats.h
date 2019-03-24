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
    QLabel *acclvlv;
    QLabel *regdatev;
    QLabel *regdate;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QPushButton *editb;
    QPushButton *viewb;

    void setupUi(QWidget *stats)
    {
        if (stats->objectName().isEmpty())
            stats->setObjectName(QString::fromUtf8("stats"));
        stats->resize(400, 300);
        groupBox = new QGroupBox(stats);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 40, 300, 141));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 20, 120, 107));
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

        formLayout->setWidget(0, QFormLayout::FieldRole, usrnmv);

        pss = new QLabel(layoutWidget);
        pss->setObjectName(QString::fromUtf8("pss"));

        formLayout->setWidget(1, QFormLayout::LabelRole, pss);

        pssv = new QLabel(layoutWidget);
        pssv->setObjectName(QString::fromUtf8("pssv"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pssv);

        acclvl = new QLabel(layoutWidget);
        acclvl->setObjectName(QString::fromUtf8("acclvl"));

        formLayout->setWidget(2, QFormLayout::LabelRole, acclvl);

        acclvlv = new QLabel(layoutWidget);
        acclvlv->setObjectName(QString::fromUtf8("acclvlv"));

        formLayout->setWidget(2, QFormLayout::FieldRole, acclvlv);

        regdatev = new QLabel(layoutWidget);
        regdatev->setObjectName(QString::fromUtf8("regdatev"));

        formLayout->setWidget(3, QFormLayout::FieldRole, regdatev);

        regdate = new QLabel(layoutWidget);
        regdate->setObjectName(QString::fromUtf8("regdate"));

        formLayout->setWidget(3, QFormLayout::LabelRole, regdate);


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
        acclvlv->setText(QApplication::translate("stats", "TextLabel", nullptr));
        regdatev->setText(QApplication::translate("stats", "TextLabel", nullptr));
        regdate->setText(QApplication::translate("stats", "Registration date:", nullptr));
        editb->setText(QApplication::translate("stats", "Edit list", nullptr));
        viewb->setText(QApplication::translate("stats", "View list", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stats: public Ui_stats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATS_H
