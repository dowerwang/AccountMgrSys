/********************************************************************************
** Form generated from reading UI file 'AccountAddDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTADDDIALOG_H
#define UI_ACCOUNTADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_AccountAddDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QLineEdit *lineEdit_7;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label;

    void setupUi(QDialog *AccountAddDialog)
    {
        if (AccountAddDialog->objectName().isEmpty())
            AccountAddDialog->setObjectName(QStringLiteral("AccountAddDialog"));
        AccountAddDialog->resize(358, 349);
        gridLayout = new QGridLayout(AccountAddDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(AccountAddDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(75, 0));
        label_2->setMaximumSize(QSize(75, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(AccountAddDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setFont(font);

        horizontalLayout->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(AccountAddDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(75, 0));
        label_4->setMaximumSize(QSize(75, 16777215));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        radioButton = new QRadioButton(AccountAddDialog);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setFont(font);

        horizontalLayout_3->addWidget(radioButton);

        radioButton_2 = new QRadioButton(AccountAddDialog);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setFont(font);

        horizontalLayout_3->addWidget(radioButton_2);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(AccountAddDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(75, 0));
        label_5->setMaximumSize(QSize(75, 16777215));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        radioButton_3 = new QRadioButton(AccountAddDialog);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setFont(font);

        horizontalLayout_4->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(AccountAddDialog);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setFont(font);

        horizontalLayout_4->addWidget(radioButton_4);


        gridLayout->addLayout(horizontalLayout_4, 4, 0, 1, 2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(AccountAddDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(75, 0));
        label_6->setMaximumSize(QSize(75, 16777215));
        label_6->setFont(font);

        horizontalLayout_5->addWidget(label_6);

        lineEdit_3 = new QLineEdit(AccountAddDialog);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setFont(font);

        horizontalLayout_5->addWidget(lineEdit_3);


        gridLayout->addLayout(horizontalLayout_5, 5, 0, 1, 2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(AccountAddDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(75, 0));
        label_7->setMaximumSize(QSize(75, 16777215));
        label_7->setFont(font);

        horizontalLayout_6->addWidget(label_7);

        lineEdit_4 = new QLineEdit(AccountAddDialog);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setFont(font);

        horizontalLayout_6->addWidget(lineEdit_4);


        gridLayout->addLayout(horizontalLayout_6, 6, 0, 1, 2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_8 = new QLabel(AccountAddDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setMinimumSize(QSize(75, 0));
        label_8->setMaximumSize(QSize(75, 16777215));
        label_8->setFont(font);

        horizontalLayout_7->addWidget(label_8);

        lineEdit_5 = new QLineEdit(AccountAddDialog);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setFont(font);

        horizontalLayout_7->addWidget(lineEdit_5);


        gridLayout->addLayout(horizontalLayout_7, 7, 0, 1, 2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_9 = new QLabel(AccountAddDialog);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMinimumSize(QSize(75, 0));
        label_9->setMaximumSize(QSize(75, 16777215));
        label_9->setFont(font);

        horizontalLayout_8->addWidget(label_9);

        lineEdit_6 = new QLineEdit(AccountAddDialog);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setFont(font);

        horizontalLayout_8->addWidget(lineEdit_6);


        gridLayout->addLayout(horizontalLayout_8, 8, 0, 1, 2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_10 = new QLabel(AccountAddDialog);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMinimumSize(QSize(75, 0));
        label_10->setMaximumSize(QSize(75, 16777215));
        label_10->setFont(font);

        horizontalLayout_9->addWidget(label_10);

        lineEdit_7 = new QLineEdit(AccountAddDialog);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setFont(font);

        horizontalLayout_9->addWidget(lineEdit_7);


        gridLayout->addLayout(horizontalLayout_9, 9, 0, 1, 2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        pushButton = new QPushButton(AccountAddDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font);

        horizontalLayout_10->addWidget(pushButton);

        pushButton_2 = new QPushButton(AccountAddDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFont(font);

        horizontalLayout_10->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout_10, 10, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(AccountAddDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(75, 0));
        label_3->setMaximumSize(QSize(75, 16777215));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        lineEdit_2 = new QLineEdit(AccountAddDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setFont(font);

        horizontalLayout_2->addWidget(lineEdit_2);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 2);

        label = new QLabel(AccountAddDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(13);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);


        retranslateUi(AccountAddDialog);

        QMetaObject::connectSlotsByName(AccountAddDialog);
    } // setupUi

    void retranslateUi(QDialog *AccountAddDialog)
    {
        AccountAddDialog->setWindowTitle(QApplication::translate("AccountAddDialog", "AccountAddDialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("AccountAddDialog", "\347\256\241\347\220\206\345\221\230ID\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("AccountAddDialog", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        radioButton->setText(QApplication::translate("AccountAddDialog", "\347\224\267", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("AccountAddDialog", "\345\245\263", Q_NULLPTR));
        label_5->setText(QApplication::translate("AccountAddDialog", "\347\256\241\347\220\206\345\221\230\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("AccountAddDialog", "\346\231\256\351\200\232", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("AccountAddDialog", "\350\266\205\347\272\247", Q_NULLPTR));
        label_6->setText(QApplication::translate("AccountAddDialog", "\350\272\253\344\273\275\350\257\201\345\217\267\347\240\201\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("AccountAddDialog", "\347\231\273\351\231\206\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("AccountAddDialog", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("AccountAddDialog", "\344\275\217\345\235\200\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("AccountAddDialog", "\346\217\217\350\277\260\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("AccountAddDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("AccountAddDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        label_3->setText(QApplication::translate("AccountAddDialog", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("AccountAddDialog", "\346\226\260\345\273\272\347\256\241\347\220\206\345\221\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AccountAddDialog: public Ui_AccountAddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTADDDIALOG_H
