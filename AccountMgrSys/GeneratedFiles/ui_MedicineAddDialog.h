/********************************************************************************
** Form generated from reading UI file 'MedicineAddDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDICINEADDDIALOG_H
#define UI_MEDICINEADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MedicineAddDialog
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
    QLineEdit *lineEdit_2;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *MedicineAddDialog)
    {
        if (MedicineAddDialog->objectName().isEmpty())
            MedicineAddDialog->setObjectName(QString::fromUtf8("MedicineAddDialog"));
        MedicineAddDialog->resize(331, 348);
        verticalLayout = new QVBoxLayout(MedicineAddDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(MedicineAddDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(13);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);


        verticalLayout->addWidget(frame);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(MedicineAddDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(90, 0));
        label_2->setMaximumSize(QSize(90, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(MedicineAddDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font1);

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(MedicineAddDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(90, 0));
        label_3->setMaximumSize(QSize(90, 16777215));
        label_3->setFont(font1);

        horizontalLayout_3->addWidget(label_3);

        lineEdit_2 = new QLineEdit(MedicineAddDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFont(font1);

        horizontalLayout_3->addWidget(lineEdit_2);

        label_7 = new QLabel(MedicineAddDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        horizontalLayout_3->addWidget(label_7);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(MedicineAddDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(90, 0));
        label_4->setMaximumSize(QSize(90, 16777215));
        label_4->setFont(font1);

        horizontalLayout_4->addWidget(label_4);

        comboBox = new QComboBox(MedicineAddDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setFont(font1);

        horizontalLayout_4->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(MedicineAddDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(90, 0));
        label_5->setMaximumSize(QSize(90, 16777215));
        label_5->setFont(font1);

        horizontalLayout_5->addWidget(label_5);

        lineEdit_4 = new QLineEdit(MedicineAddDialog);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setFont(font1);

        horizontalLayout_5->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(MedicineAddDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(90, 0));
        label_6->setMaximumSize(QSize(90, 16777215));
        label_6->setFont(font1);

        horizontalLayout_6->addWidget(label_6);

        textEdit = new QTextEdit(MedicineAddDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout_6->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        pushButton = new QPushButton(MedicineAddDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font1);

        horizontalLayout_7->addWidget(pushButton);

        pushButton_2 = new QPushButton(MedicineAddDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font1);

        horizontalLayout_7->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_7);


        retranslateUi(MedicineAddDialog);

        QMetaObject::connectSlotsByName(MedicineAddDialog);
    } // setupUi

    void retranslateUi(QDialog *MedicineAddDialog)
    {
        MedicineAddDialog->setWindowTitle(QCoreApplication::translate("MedicineAddDialog", "MedicineAddDialog", nullptr));
        label->setText(QCoreApplication::translate("MedicineAddDialog", "\346\226\260\345\242\236\350\215\257\345\223\201", nullptr));
        label_2->setText(QCoreApplication::translate("MedicineAddDialog", "\350\215\257\345\223\201\345\220\215\347\247\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MedicineAddDialog", "\350\215\257\345\223\201\345\215\225\344\273\267\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("MedicineAddDialog", "\345\215\225\344\275\215\357\274\232\345\205\203", nullptr));
        label_4->setText(QCoreApplication::translate("MedicineAddDialog", "\350\215\257\345\223\201\350\256\241\351\207\217\345\215\225\344\275\215\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MedicineAddDialog", "\350\215\257\345\223\201\345\275\223\345\211\215\345\272\223\345\255\230\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("MedicineAddDialog", "\350\215\257\345\223\201\346\217\217\350\277\260\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("MedicineAddDialog", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MedicineAddDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MedicineAddDialog: public Ui_MedicineAddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDICINEADDDIALOG_H
