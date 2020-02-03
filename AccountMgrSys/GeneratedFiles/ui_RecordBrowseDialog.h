/********************************************************************************
** Form generated from reading UI file 'RecordBrowseDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDBROWSEDIALOG_H
#define UI_RECORDBROWSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RecordBrowseDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_16;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QFrame *line_11;
    QPushButton *pushButton_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *dateEdit;
    QLabel *label_2;
    QDateEdit *dateEdit_2;
    QTableView *tableView;

    void setupUi(QDialog *RecordBrowseDialog)
    {
        if (RecordBrowseDialog->objectName().isEmpty())
            RecordBrowseDialog->setObjectName(QStringLiteral("RecordBrowseDialog"));
        RecordBrowseDialog->resize(873, 531);
        verticalLayout = new QVBoxLayout(RecordBrowseDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_6 = new QFrame(RecordBrowseDialog);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_16 = new QHBoxLayout(frame_6);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 5, 0, 5);
        lineEdit_2 = new QLineEdit(frame_6);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_16->addWidget(lineEdit_2);

        pushButton = new QPushButton(frame_6);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_16->addWidget(pushButton);

        line_11 = new QFrame(frame_6);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setFrameShape(QFrame::VLine);
        line_11->setFrameShadow(QFrame::Sunken);

        horizontalLayout_16->addWidget(line_11);

        pushButton_2 = new QPushButton(frame_6);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_16->addWidget(pushButton_2);


        verticalLayout->addWidget(frame_6);

        frame = new QFrame(RecordBrowseDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        dateEdit = new QDateEdit(frame);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        horizontalLayout->addWidget(dateEdit);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_2);

        dateEdit_2 = new QDateEdit(frame);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));

        horizontalLayout->addWidget(dateEdit_2);


        verticalLayout->addWidget(frame);

        tableView = new QTableView(RecordBrowseDialog);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);


        retranslateUi(RecordBrowseDialog);

        QMetaObject::connectSlotsByName(RecordBrowseDialog);
    } // setupUi

    void retranslateUi(QDialog *RecordBrowseDialog)
    {
        RecordBrowseDialog->setWindowTitle(QApplication::translate("RecordBrowseDialog", "RecordBrowseDialog", nullptr));
        pushButton->setText(QApplication::translate("RecordBrowseDialog", "\351\253\230\347\272\247\346\220\234\347\264\242", nullptr));
        pushButton_2->setText(QApplication::translate("RecordBrowseDialog", "\345\210\240\351\231\244\346\211\200\351\200\211", nullptr));
        label->setText(QApplication::translate("RecordBrowseDialog", "\350\265\267\345\247\213\346\227\245\346\234\237\357\274\232", nullptr));
        label_2->setText(QApplication::translate("RecordBrowseDialog", "\347\273\223\346\235\237\346\227\245\346\234\237\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecordBrowseDialog: public Ui_RecordBrowseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDBROWSEDIALOG_H
