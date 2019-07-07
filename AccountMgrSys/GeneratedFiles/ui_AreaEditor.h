/********************************************************************************
** Form generated from reading UI file 'AreaEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AREAEDITOR_H
#define UI_AREAEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_AreaEditor
{
public:

    void setupUi(QDialog *AreaEditor)
    {
        if (AreaEditor->objectName().isEmpty())
            AreaEditor->setObjectName(QString::fromUtf8("AreaEditor"));
        AreaEditor->resize(400, 300);

        retranslateUi(AreaEditor);

        QMetaObject::connectSlotsByName(AreaEditor);
    } // setupUi

    void retranslateUi(QDialog *AreaEditor)
    {
        AreaEditor->setWindowTitle(QCoreApplication::translate("AreaEditor", "AreaEditor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AreaEditor: public Ui_AreaEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AREAEDITOR_H
