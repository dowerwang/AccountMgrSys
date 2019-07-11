/********************************************************************************
** Form generated from reading UI file 'PatientAddDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTADDDIALOG_H
#define UI_PATIENTADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PatientAddDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *PatientAddDialog)
    {
        if (PatientAddDialog->objectName().isEmpty())
            PatientAddDialog->setObjectName(QStringLiteral("PatientAddDialog"));
        PatientAddDialog->resize(359, 342);
        verticalLayout = new QVBoxLayout(PatientAddDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(PatientAddDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(13);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);


        verticalLayout->addWidget(frame);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(PatientAddDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(60, 0));

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(PatientAddDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(PatientAddDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(60, 0));

        horizontalLayout_3->addWidget(label_3);

        radioButton = new QRadioButton(PatientAddDialog);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        radioButton->setFont(font1);

        horizontalLayout_3->addWidget(radioButton);

        radioButton_2 = new QRadioButton(PatientAddDialog);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setFont(font1);

        horizontalLayout_3->addWidget(radioButton_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(PatientAddDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(60, 0));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_3 = new QLineEdit(PatientAddDialog);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_4->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(PatientAddDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(60, 0));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_4 = new QLineEdit(PatientAddDialog);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        horizontalLayout_5->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(PatientAddDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(60, 0));

        horizontalLayout_6->addWidget(label_6);

        lineEdit_5 = new QLineEdit(PatientAddDialog);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        horizontalLayout_6->addWidget(lineEdit_5);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(PatientAddDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(60, 0));

        horizontalLayout_7->addWidget(label_7);

        lineEdit_6 = new QLineEdit(PatientAddDialog);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        horizontalLayout_7->addWidget(lineEdit_6);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(PatientAddDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setMinimumSize(QSize(60, 0));

        horizontalLayout_8->addWidget(label_8);

        textEdit = new QTextEdit(PatientAddDialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout_8->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        pushButton = new QPushButton(PatientAddDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font1);

        horizontalLayout_10->addWidget(pushButton);

        pushButton_2 = new QPushButton(PatientAddDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFont(font1);

        horizontalLayout_10->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_10);


        retranslateUi(PatientAddDialog);

        QMetaObject::connectSlotsByName(PatientAddDialog);
    } // setupUi

    void retranslateUi(QDialog *PatientAddDialog)
    {
        PatientAddDialog->setWindowTitle(QApplication::translate("PatientAddDialog", "PatientAddDialog", Q_NULLPTR));
        label->setText(QApplication::translate("PatientAddDialog", "\346\267\273\345\212\240\344\272\272\345\221\230", Q_NULLPTR));
        label_2->setText(QApplication::translate("PatientAddDialog", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("PatientAddDialog", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        radioButton->setText(QApplication::translate("PatientAddDialog", "\347\224\267", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("PatientAddDialog", "\345\245\263", Q_NULLPTR));
        label_4->setText(QApplication::translate("PatientAddDialog", "\346\210\267\344\270\273\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("PatientAddDialog", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("PatientAddDialog", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("PatientAddDialog", "\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("PatientAddDialog", "\346\217\217\350\277\260\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("PatientAddDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("PatientAddDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PatientAddDialog: public Ui_PatientAddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTADDDIALOG_H
