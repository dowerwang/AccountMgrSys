/********************************************************************************
** Form generated from reading UI file 'AddRecordDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRECORDDIALOG_H
#define UI_ADDRECORDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <completelineedit.h>

QT_BEGIN_NAMESPACE

class Ui_AddRecordDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QFrame *line;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *line_2;
    QLabel *label_5;
    QLabel *label_6;
    QFrame *line_3;
    QLabel *label_7;
    QLabel *label_8;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QFrame *line_4;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    CompleteLineEdit *lineEdit;
    QFrame *line_10;
    QLabel *label_18;
    QLineEdit *lineEdit_4;
    QFrame *line_5;
    QLabel *label_10;
    QLineEdit *lineEdit_2;
    QLabel *label_11;
    QFrame *line_6;
    QLabel *label_12;
    QLineEdit *lineEdit_3;
    QLabel *label_15;
    QFrame *line_7;
    QPushButton *pushButton;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_Unpaid;
    QPushButton *pushButton_Paid;
    QFrame *line_8;
    QLabel *label_13;
    QLabel *label_14;
    QFrame *line_9;
    QLabel *label_16;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;

    void setupUi(QDialog *AddRecordDialog)
    {
        if (AddRecordDialog->objectName().isEmpty())
            AddRecordDialog->setObjectName(QStringLiteral("AddRecordDialog"));
        AddRecordDialog->resize(930, 506);
        verticalLayout = new QVBoxLayout(AddRecordDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(AddRecordDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout->addWidget(label_8);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(AddRecordDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, 0, 9, 0);
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setFocusPolicy(Qt::ClickFocus);

        verticalLayout_2->addWidget(tableView);

        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout = new QGridLayout(groupBox_5);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, -1);
        textEdit = new QTextEdit(groupBox_5);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMaximumSize(QSize(16777215, 50));
        textEdit->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_5);


        verticalLayout->addWidget(groupBox_2);

        line_4 = new QFrame(AddRecordDialog);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        groupBox_3 = new QGroupBox(AddRecordDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(5, -1, -1, 5);
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_3->addWidget(label_9);

        lineEdit = new CompleteLineEdit(groupBox_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_3->addWidget(lineEdit);

        line_10 = new QFrame(groupBox_3);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_10);

        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_3->addWidget(label_18);

        lineEdit_4 = new QLineEdit(groupBox_3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_3->addWidget(lineEdit_4);

        line_5 = new QFrame(groupBox_3);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_5);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_3->addWidget(label_10);

        lineEdit_2 = new QLineEdit(groupBox_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_3->addWidget(lineEdit_2);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_3->addWidget(label_11);

        line_6 = new QFrame(groupBox_3);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_6);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_3->addWidget(label_12);

        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_3->addWidget(lineEdit_3);

        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_3->addWidget(label_15);

        line_7 = new QFrame(groupBox_3);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_7);

        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout->addWidget(groupBox_3);

        frame = new QFrame(AddRecordDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        groupBox_4 = new QGroupBox(frame);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_Unpaid = new QPushButton(groupBox_4);
        pushButton_Unpaid->setObjectName(QStringLiteral("pushButton_Unpaid"));
        pushButton_Unpaid->setFocusPolicy(Qt::ClickFocus);
        pushButton_Unpaid->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(pushButton_Unpaid);

        pushButton_Paid = new QPushButton(groupBox_4);
        pushButton_Paid->setObjectName(QStringLiteral("pushButton_Paid"));
        pushButton_Paid->setFocusPolicy(Qt::ClickFocus);
        pushButton_Paid->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(pushButton_Paid);

        line_8 = new QFrame(groupBox_4);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_8);

        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_4->addWidget(label_13);

        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_4->addWidget(label_14);

        line_9 = new QFrame(groupBox_4);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_9);

        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_4->addWidget(label_16);

        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_4->addWidget(label_17);


        horizontalLayout_5->addWidget(groupBox_4);

        horizontalSpacer = new QSpacerItem(333, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_2);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, 21, -1, -1);
        pushButton_5 = new QPushButton(frame_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_6->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(frame_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_6->addWidget(pushButton_4);


        horizontalLayout_5->addWidget(frame_2);


        verticalLayout->addWidget(frame);


        retranslateUi(AddRecordDialog);

        QMetaObject::connectSlotsByName(AddRecordDialog);
    } // setupUi

    void retranslateUi(QDialog *AddRecordDialog)
    {
        AddRecordDialog->setWindowTitle(QApplication::translate("AddRecordDialog", "AddRecordDialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("AddRecordDialog", "\344\272\272\345\221\230\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("AddRecordDialog", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddRecordDialog", "\345\260\217\346\230\216", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddRecordDialog", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddRecordDialog", "\347\224\267", Q_NULLPTR));
        label_5->setText(QApplication::translate("AddRecordDialog", "\345\271\264\351\276\204\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("AddRecordDialog", "18\345\262\201", Q_NULLPTR));
        label_7->setText(QApplication::translate("AddRecordDialog", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("AddRecordDialog", "123456789146", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("AddRecordDialog", "\350\215\257\345\223\201\345\210\227\350\241\250", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("AddRecordDialog", "\345\244\207\346\263\250", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("AddRecordDialog", "\346\267\273\345\212\240\350\215\257\345\223\201", Q_NULLPTR));
        label_9->setText(QApplication::translate("AddRecordDialog", "\350\215\257\345\223\201\345\220\215\357\274\232", Q_NULLPTR));
        label_18->setText(QApplication::translate("AddRecordDialog", "\345\215\225\344\273\267\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("AddRecordDialog", "\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("AddRecordDialog", "\347\233\222", Q_NULLPTR));
        label_12->setText(QApplication::translate("AddRecordDialog", "\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        label_15->setText(QApplication::translate("AddRecordDialog", "\345\205\203", Q_NULLPTR));
        pushButton->setText(QApplication::translate("AddRecordDialog", "\347\241\256\345\256\232\346\267\273\345\212\240", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("AddRecordDialog", "\350\256\260\345\275\225\347\212\266\346\200\201", Q_NULLPTR));
        pushButton_Unpaid->setText(QApplication::translate("AddRecordDialog", "\346\234\252\347\273\223", Q_NULLPTR));
        pushButton_Paid->setText(QApplication::translate("AddRecordDialog", "\345\267\262\347\273\223", Q_NULLPTR));
        label_13->setText(QApplication::translate("AddRecordDialog", "\345\275\223\345\211\215\347\212\266\346\200\201\344\270\272\357\274\232", Q_NULLPTR));
        label_14->setText(QApplication::translate("AddRecordDialog", "\345\267\262\347\273\223", Q_NULLPTR));
        label_16->setText(QApplication::translate("AddRecordDialog", "\346\200\273\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        label_17->setText(QApplication::translate("AddRecordDialog", "0\345\205\203", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("AddRecordDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("AddRecordDialog", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddRecordDialog: public Ui_AddRecordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRECORDDIALOG_H
