/********************************************************************************
** Form generated from reading UI file 'AddsSelectWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSSELECTWIDGET_H
#define UI_ADDSSELECTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddsSelectWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QLabel *label_4;
    QComboBox *comboBox_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QComboBox *comboBox_4;
    QLabel *label_7;
    QComboBox *comboBox_5;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *AddsSelectWidget)
    {
        if (AddsSelectWidget->objectName().isEmpty())
            AddsSelectWidget->setObjectName(QStringLiteral("AddsSelectWidget"));
        AddsSelectWidget->resize(311, 100);
        gridLayout = new QGridLayout(AddsSelectWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        frame = new QFrame(AddsSelectWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(20, 0));
        label_2->setMaximumSize(QSize(20, 16777215));

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(20, 0));
        label_3->setMaximumSize(QSize(20, 16777215));

        horizontalLayout->addWidget(label_3);

        comboBox_2 = new QComboBox(frame);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        horizontalLayout->addWidget(comboBox_2);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(20, 0));
        label_4->setMaximumSize(QSize(20, 16777215));

        horizontalLayout->addWidget(label_4);

        comboBox_3 = new QComboBox(frame);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        horizontalLayout->addWidget(comboBox_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(20, 0));
        label_6->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_2->addWidget(label_6);

        comboBox_4 = new QComboBox(frame);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        horizontalLayout_2->addWidget(comboBox_4);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(20, 0));
        label_7->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_2->addWidget(label_7);

        comboBox_5 = new QComboBox(frame);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));

        horizontalLayout_2->addWidget(comboBox_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(AddsSelectWidget);

        QMetaObject::connectSlotsByName(AddsSelectWidget);
    } // setupUi

    void retranslateUi(QWidget *AddsSelectWidget)
    {
        AddsSelectWidget->setWindowTitle(QApplication::translate("AddsSelectWidget", "AddsSelectWidget", Q_NULLPTR));
        label->setText(QApplication::translate("AddsSelectWidget", "\350\275\257\344\273\266\346\223\215\344\275\234\345\234\260\345\214\272\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddsSelectWidget", "\347\234\201\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddsSelectWidget", "\345\270\202\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddsSelectWidget", "\345\214\272\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("AddsSelectWidget", "\347\256\241\347\220\206\351\225\207\346\235\221\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("AddsSelectWidget", "\351\225\207\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("AddsSelectWidget", "\346\235\221\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddsSelectWidget: public Ui_AddsSelectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSSELECTWIDGET_H
