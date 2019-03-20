/********************************************************************************
** Form generated from reading UI file 'RecordFrame.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDFRAME_H
#define UI_RECORDFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_RecordFrame
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;

    void setupUi(QFrame *RecordFrame)
    {
        if (RecordFrame->objectName().isEmpty())
            RecordFrame->setObjectName(QStringLiteral("RecordFrame"));
        RecordFrame->resize(810, 67);
        label = new QLabel(RecordFrame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 54, 12));
        label_2 = new QLabel(RecordFrame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 30, 54, 12));
        label_3 = new QLabel(RecordFrame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(135, 30, 54, 12));
        label_4 = new QLabel(RecordFrame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(210, 30, 54, 12));
        label_5 = new QLabel(RecordFrame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(280, 30, 54, 12));
        label_6 = new QLabel(RecordFrame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(320, 30, 54, 12));
        label_7 = new QLabel(RecordFrame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(380, 30, 54, 12));
        label_8 = new QLabel(RecordFrame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(445, 30, 54, 12));
        label_9 = new QLabel(RecordFrame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(495, 30, 54, 12));
        label_10 = new QLabel(RecordFrame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(555, 30, 54, 12));

        retranslateUi(RecordFrame);

        QMetaObject::connectSlotsByName(RecordFrame);
    } // setupUi

    void retranslateUi(QFrame *RecordFrame)
    {
        RecordFrame->setWindowTitle(QApplication::translate("RecordFrame", "RecordFrame", Q_NULLPTR));
        label->setText(QApplication::translate("RecordFrame", "\347\216\213\345\260\217\344\272\214", Q_NULLPTR));
        label_2->setText(QApplication::translate("RecordFrame", "\350\256\260\345\275\225\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("RecordFrame", "138\345\205\203", Q_NULLPTR));
        label_4->setText(QApplication::translate("RecordFrame", "\350\215\257\345\223\201\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("RecordFrame", "3", Q_NULLPTR));
        label_6->setText(QApplication::translate("RecordFrame", "\350\256\260\345\275\225\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("RecordFrame", "\346\234\252\347\273\223", Q_NULLPTR));
        label_8->setText(QApplication::translate("RecordFrame", "\350\256\260\345\275\225\345\221\230\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("RecordFrame", "\346\235\216\345\260\217\344\272\214", Q_NULLPTR));
        label_10->setText(QApplication::translate("RecordFrame", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RecordFrame: public Ui_RecordFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDFRAME_H
