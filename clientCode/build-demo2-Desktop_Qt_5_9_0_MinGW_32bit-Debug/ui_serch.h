/********************************************************************************
** Form generated from reading UI file 'serch.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERCH_H
#define UI_SERCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Serch
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QWidget *Serch)
    {
        if (Serch->objectName().isEmpty())
            Serch->setObjectName(QStringLiteral("Serch"));
        Serch->resize(280, 206);
        pushButton = new QPushButton(Serch);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 140, 80, 26));
        lineEdit = new QLineEdit(Serch);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 60, 113, 26));
        label = new QLabel(Serch);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 54, 18));

        retranslateUi(Serch);

        QMetaObject::connectSlotsByName(Serch);
    } // setupUi

    void retranslateUi(QWidget *Serch)
    {
        Serch->setWindowTitle(QApplication::translate("Serch", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Serch", "\346\220\234\347\264\242", Q_NULLPTR));
        label->setText(QApplication::translate("Serch", "\350\264\246\345\217\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Serch: public Ui_Serch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERCH_H
