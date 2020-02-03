/********************************************************************************
** Form generated from reading UI file 'PatientBrowseDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTBROWSEDIALOG_H
#define UI_PATIENTBROWSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientBrowseDialog
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QPushButton *pushButton_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QTreeView *treeView;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *PatientBrowseDialog)
    {
        if (PatientBrowseDialog->objectName().isEmpty())
            PatientBrowseDialog->setObjectName(QStringLiteral("PatientBrowseDialog"));
        PatientBrowseDialog->resize(776, 510);
        gridLayout = new QGridLayout(PatientBrowseDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame_2 = new QFrame(PatientBrowseDialog);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 0, -1);
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        lineEdit->setFont(font);

        horizontalLayout->addWidget(lineEdit);

        radioButton_3 = new QRadioButton(frame_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setFont(font);

        horizontalLayout->addWidget(radioButton_3);

        radioButton_2 = new QRadioButton(frame_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setFont(font);

        horizontalLayout->addWidget(radioButton_2);

        radioButton = new QRadioButton(frame_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setFont(font);

        horizontalLayout->addWidget(radioButton);

        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setFont(font);

        horizontalLayout->addWidget(pushButton_3);


        gridLayout->addWidget(frame_2, 0, 0, 1, 1);

        frame = new QFrame(PatientBrowseDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        treeView = new QTreeView(frame);
        treeView->setObjectName(QStringLiteral("treeView"));

        horizontalLayout_2->addWidget(treeView);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font);

        verticalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFont(font);

        verticalLayout_2->addWidget(pushButton_2);

        pushButton_7 = new QPushButton(frame);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setFont(font);

        verticalLayout_2->addWidget(pushButton_7);

        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setFont(font);

        verticalLayout_2->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setFont(font);

        verticalLayout_2->addWidget(pushButton_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_2);


        gridLayout->addWidget(frame, 1, 0, 1, 1);


        retranslateUi(PatientBrowseDialog);

        QMetaObject::connectSlotsByName(PatientBrowseDialog);
    } // setupUi

    void retranslateUi(QWidget *PatientBrowseDialog)
    {
        PatientBrowseDialog->setWindowTitle(QApplication::translate("PatientBrowseDialog", "PatientBrowseDialog", nullptr));
        radioButton_3->setText(QApplication::translate("PatientBrowseDialog", "\346\214\211\350\272\253\344\273\275\350\257\201", nullptr));
        radioButton_2->setText(QApplication::translate("PatientBrowseDialog", "\346\214\211\346\202\243\350\200\205", nullptr));
        radioButton->setText(QApplication::translate("PatientBrowseDialog", "\346\214\211\346\210\267\344\270\273", nullptr));
        pushButton_3->setText(QApplication::translate("PatientBrowseDialog", "\346\237\245\346\211\276", nullptr));
        pushButton->setText(QApplication::translate("PatientBrowseDialog", "\346\267\273\345\212\240\346\235\221", nullptr));
        pushButton_2->setText(QApplication::translate("PatientBrowseDialog", "\346\267\273\345\212\240\347\273\204", nullptr));
        pushButton_7->setText(QApplication::translate("PatientBrowseDialog", "\346\267\273\345\212\240\346\202\243\350\200\205", nullptr));
        pushButton_4->setText(QApplication::translate("PatientBrowseDialog", "\345\210\240\351\231\244", nullptr));
        pushButton_5->setText(QApplication::translate("PatientBrowseDialog", "\346\217\220\344\272\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientBrowseDialog: public Ui_PatientBrowseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTBROWSEDIALOG_H
