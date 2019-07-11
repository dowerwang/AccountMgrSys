/********************************************************************************
** Form generated from reading UI file 'SysSettings.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSSETTINGS_H
#define UI_SYSSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>

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
            SysSettings->setObjectName(QStringLiteral("SysSettings"));
        SysSettings->resize(574, 268);
        gridLayout = new QGridLayout(SysSettings);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame = new QFrame(SysSettings);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);

        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(SysSettings);

        QMetaObject::connectSlotsByName(SysSettings);
    } // setupUi

    void retranslateUi(QDialog *SysSettings)
    {
        SysSettings->setWindowTitle(QApplication::translate("SysSettings", "SysSettings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SysSettings: public Ui_SysSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSSETTINGS_H
