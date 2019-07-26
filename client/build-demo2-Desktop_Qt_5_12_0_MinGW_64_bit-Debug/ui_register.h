/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_6;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *name;
    QLineEdit *user;
    QLineEdit *signature;
    QLineEdit *email;
    QLineEdit *pass;
    QLineEdit *pass_;
    QPushButton *pushButton;
    QLabel *label_7;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(441, 507);
        widget = new QWidget(Register);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(90, 130, 72, 311));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        widget_2 = new QWidget(Register);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(200, 130, 126, 321));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        name = new QLineEdit(widget_2);
        name->setObjectName(QString::fromUtf8("name"));

        verticalLayout_2->addWidget(name);

        user = new QLineEdit(widget_2);
        user->setObjectName(QString::fromUtf8("user"));

        verticalLayout_2->addWidget(user);

        signature = new QLineEdit(widget_2);
        signature->setObjectName(QString::fromUtf8("signature"));

        verticalLayout_2->addWidget(signature);

        email = new QLineEdit(widget_2);
        email->setObjectName(QString::fromUtf8("email"));

        verticalLayout_2->addWidget(email);

        pass = new QLineEdit(widget_2);
        pass->setObjectName(QString::fromUtf8("pass"));

        verticalLayout_2->addWidget(pass);

        pass_ = new QLineEdit(widget_2);
        pass_->setObjectName(QString::fromUtf8("pass_"));

        verticalLayout_2->addWidget(pass_);

        pushButton = new QPushButton(Register);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 460, 80, 26));
        label_7 = new QLabel(Register);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(100, 40, 54, 44));
        pushButton_2 = new QPushButton(Register);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 0, 191, 121));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/00.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(132, 118));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Form", nullptr));
        label->setText(QApplication::translate("Register", "\345\247\223\345\220\215", nullptr));
        label_2->setText(QApplication::translate("Register", "\346\230\265\347\247\260", nullptr));
        label_4->setText(QApplication::translate("Register", "\344\270\252\346\200\247\347\255\276\345\220\215", nullptr));
        label_5->setText(QApplication::translate("Register", "\351\202\256\347\256\261", nullptr));
        label_3->setText(QApplication::translate("Register", "\345\257\206\347\240\201", nullptr));
        label_6->setText(QApplication::translate("Register", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        pushButton->setText(QApplication::translate("Register", "\346\263\250\345\206\214", nullptr));
        label_7->setText(QApplication::translate("Register", "\345\244\264\345\203\217", nullptr));
        pushButton_2->setText(QApplication::translate("Register", "\347\202\271\345\207\273\346\233\264\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
