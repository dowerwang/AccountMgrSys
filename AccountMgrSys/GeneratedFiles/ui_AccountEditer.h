/********************************************************************************
** Form generated from reading UI file 'AccountEditer.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTEDITER_H
#define UI_ACCOUNTEDITER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountEditer
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *AccountEditer)
    {
        if (AccountEditer->objectName().isEmpty())
            AccountEditer->setObjectName(QString::fromUtf8("AccountEditer"));
        AccountEditer->resize(738, 430);
        verticalLayout = new QVBoxLayout(AccountEditer);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_2 = new QFrame(AccountEditer);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 0, -1);
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        lineEdit->setFont(font);

        horizontalLayout->addWidget(lineEdit);

        radioButton = new QRadioButton(frame_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setFont(font);

        horizontalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(frame_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setFont(font);

        horizontalLayout->addWidget(radioButton_2);

        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font);

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addWidget(frame_2);

        frame = new QFrame(AccountEditer);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(frame);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setFont(font);
        tableView->setStyleSheet(QString::fromUtf8("QTableView QAbstractItemView\n"
"{\n"
"text-align: center;\n"
"}"));

        horizontalLayout_2->addWidget(tableView);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        verticalLayout_2->addWidget(pushButton);

        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font);

        verticalLayout_2->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font);

        verticalLayout_2->addWidget(pushButton_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout->addWidget(frame);


        retranslateUi(AccountEditer);

        QMetaObject::connectSlotsByName(AccountEditer);
    } // setupUi

    void retranslateUi(QWidget *AccountEditer)
    {
        AccountEditer->setWindowTitle(QCoreApplication::translate("AccountEditer", "AccountEditer", nullptr));
        radioButton->setText(QCoreApplication::translate("AccountEditer", "\346\214\211\345\247\223\345\220\215", nullptr));
        radioButton_2->setText(QCoreApplication::translate("AccountEditer", "\346\214\211ID", nullptr));
        pushButton_3->setText(QCoreApplication::translate("AccountEditer", "\346\237\245\346\211\276", nullptr));
        pushButton->setText(QCoreApplication::translate("AccountEditer", "\346\267\273\345\212\240", nullptr));
        pushButton_4->setText(QCoreApplication::translate("AccountEditer", "\345\210\240\351\231\244", nullptr));
        pushButton_5->setText(QCoreApplication::translate("AccountEditer", "\346\217\220\344\272\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountEditer: public Ui_AccountEditer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTEDITER_H
