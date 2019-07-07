/********************************************************************************
** Form generated from reading UI file 'SysSettings.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSSETTINGS_H
#define UI_SYSSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SysSettings
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;

    void setupUi(QDialog *SysSettings)
    {
        if (SysSettings->objectName().isEmpty())
            SysSettings->setObjectName(QString::fromUtf8("SysSettings"));
        SysSettings->resize(574, 268);
        gridLayout = new QGridLayout(SysSettings);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(SysSettings);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);

        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(SysSettings);

        QMetaObject::connectSlotsByName(SysSettings);
    } // setupUi

    void retranslateUi(QDialog *SysSettings)
    {
        SysSettings->setWindowTitle(QCoreApplication::translate("SysSettings", "SysSettings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SysSettings: public Ui_SysSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSSETTINGS_H
