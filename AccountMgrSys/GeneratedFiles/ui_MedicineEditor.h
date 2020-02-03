/********************************************************************************
** Form generated from reading UI file 'MedicineEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDICINEEDITOR_H
#define UI_MEDICINEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MedicineEditor
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QRadioButton *radioButton;
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

    void setupUi(QDialog *MedicineEditor)
    {
        if (MedicineEditor->objectName().isEmpty())
            MedicineEditor->setObjectName(QStringLiteral("MedicineEditor"));
        MedicineEditor->resize(738, 428);
        verticalLayout = new QVBoxLayout(MedicineEditor);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_2 = new QFrame(MedicineEditor);
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

        radioButton = new QRadioButton(frame_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setFont(font);

        horizontalLayout->addWidget(radioButton);

        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setFont(font);

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addWidget(frame_2);

        frame = new QFrame(MedicineEditor);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(frame);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setFont(font);

        horizontalLayout_2->addWidget(tableView);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font);

        verticalLayout_2->addWidget(pushButton);

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


        verticalLayout->addWidget(frame);


        retranslateUi(MedicineEditor);

        QMetaObject::connectSlotsByName(MedicineEditor);
    } // setupUi

    void retranslateUi(QDialog *MedicineEditor)
    {
        MedicineEditor->setWindowTitle(QApplication::translate("MedicineEditor", "MedicineEditor", nullptr));
        radioButton->setText(QApplication::translate("MedicineEditor", "\346\214\211\350\215\257\345\223\201\345\220\215", nullptr));
        pushButton_3->setText(QApplication::translate("MedicineEditor", "\346\237\245\346\211\276", nullptr));
        pushButton->setText(QApplication::translate("MedicineEditor", "\346\267\273\345\212\240", nullptr));
        pushButton_4->setText(QApplication::translate("MedicineEditor", "\345\210\240\351\231\244", nullptr));
        pushButton_5->setText(QApplication::translate("MedicineEditor", "\346\217\220\344\272\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MedicineEditor: public Ui_MedicineEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDICINEEDITOR_H
