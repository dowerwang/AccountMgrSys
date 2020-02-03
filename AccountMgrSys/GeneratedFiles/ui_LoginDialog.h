/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_password;
    QLabel *label;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_login;
    QPushButton *pushButton_exit;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(748, 457);
        LoginDialog->setStyleSheet(QStringLiteral("font-family: \"Microsoft YaHei\";"));
        gridLayout = new QGridLayout(LoginDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame = new QFrame(LoginDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 1, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 1, 1, 1);

        lineEdit_name = new QLineEdit(frame);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        gridLayout_2->addWidget(lineEdit_name, 1, 1, 1, 1);

        lineEdit_password = new QLineEdit(frame);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));

        gridLayout_2->addWidget(lineEdit_password, 2, 1, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_login = new QPushButton(frame_2);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));

        horizontalLayout->addWidget(pushButton_login);

        pushButton_exit = new QPushButton(frame_2);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));

        horizontalLayout->addWidget(pushButton_exit);


        gridLayout_2->addWidget(frame_2, 3, 1, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "LoginDialog", nullptr));
        label_2->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        label->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        pushButton_login->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        pushButton_exit->setText(QApplication::translate("LoginDialog", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
