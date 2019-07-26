/********************************************************************************
** Form generated from reading UI file 'landwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANDWIDGET_H
#define UI_LANDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LandWidget
{
public:
    QCheckBox *remember;
    QPushButton *registeButton;
    QPushButton *send;
    QLabel *label_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *id;
    QLabel *label_2;
    QLineEdit *password;
    QLabel *label_4;

    void setupUi(QWidget *LandWidget)
    {
        if (LandWidget->objectName().isEmpty())
            LandWidget->setObjectName(QString::fromUtf8("LandWidget"));
        LandWidget->resize(440, 499);
        remember = new QCheckBox(LandWidget);
        remember->setObjectName(QString::fromUtf8("remember"));
        remember->setGeometry(QRect(170, 410, 171, 16));
        registeButton = new QPushButton(LandWidget);
        registeButton->setObjectName(QString::fromUtf8("registeButton"));
        registeButton->setGeometry(QRect(80, 450, 93, 28));
        send = new QPushButton(LandWidget);
        send->setObjectName(QString::fromUtf8("send"));
        send->setGeometry(QRect(290, 450, 93, 28));
        label_3 = new QLabel(LandWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 410, 60, 16));
        widget = new QWidget(LandWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(100, 290, 230, 101));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        id = new QLineEdit(widget);
        id->setObjectName(QString::fromUtf8("id"));

        gridLayout->addWidget(id, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        password = new QLineEdit(widget);
        password->setObjectName(QString::fromUtf8("password"));

        gridLayout->addWidget(password, 1, 1, 1, 1);

        label_4 = new QLabel(LandWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 441, 291));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/pic/psbBVYTYGJ0.jpg")));

        retranslateUi(LandWidget);

        QMetaObject::connectSlotsByName(LandWidget);
    } // setupUi

    void retranslateUi(QWidget *LandWidget)
    {
        LandWidget->setWindowTitle(QApplication::translate("LandWidget", "Form", nullptr));
        remember->setText(QString());
        registeButton->setText(QApplication::translate("LandWidget", "\346\263\250\345\206\214", nullptr));
        send->setText(QApplication::translate("LandWidget", "\347\231\273\351\231\206", nullptr));
        label_3->setText(QApplication::translate("LandWidget", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        label->setText(QApplication::translate("LandWidget", "\350\264\246\345\217\267", nullptr));
        id->setText(QString());
        label_2->setText(QApplication::translate("LandWidget", "\345\257\206\347\240\201", nullptr));
        password->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LandWidget: public Ui_LandWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANDWIDGET_H
