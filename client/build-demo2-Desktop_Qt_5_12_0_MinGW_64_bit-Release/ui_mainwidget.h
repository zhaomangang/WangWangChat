/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWidget
{
public:
    QFrame *frame;
    QFrame *info;
    QLabel *icon;
    QLabel *username;
    QLabel *desci;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QWidget *mainWidget)
    {
        if (mainWidget->objectName().isEmpty())
            mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->resize(293, 585);
        frame = new QFrame(mainWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 170, 291, 351));
        frame->setMinimumSize(QSize(291, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        info = new QFrame(mainWidget);
        info->setObjectName(QString::fromUtf8("info"));
        info->setGeometry(QRect(10, 10, 141, 151));
        info->setFrameShape(QFrame::StyledPanel);
        info->setFrameShadow(QFrame::Raised);
        icon = new QLabel(info);
        icon->setObjectName(QString::fromUtf8("icon"));
        icon->setGeometry(QRect(0, 0, 141, 151));
        username = new QLabel(mainWidget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(160, 20, 71, 31));
        desci = new QLabel(mainWidget);
        desci->setObjectName(QString::fromUtf8("desci"));
        desci->setGeometry(QRect(160, 70, 111, 31));
        pushButton = new QPushButton(mainWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 540, 41, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/pic/sera6174645.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(30, 30));
        pushButton_2 = new QPushButton(mainWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 540, 51, 26));
        label = new QLabel(mainWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 550, 121, 18));

        retranslateUi(mainWidget);

        QMetaObject::connectSlotsByName(mainWidget);
    } // setupUi

    void retranslateUi(QWidget *mainWidget)
    {
        mainWidget->setWindowTitle(QApplication::translate("mainWidget", "mainWidget", nullptr));
        icon->setText(QApplication::translate("mainWidget", "icon", nullptr));
        username->setText(QApplication::translate("mainWidget", "us", nullptr));
        desci->setText(QApplication::translate("mainWidget", "de", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QApplication::translate("mainWidget", "\345\205\263\344\272\216", nullptr));
        label->setText(QApplication::translate("mainWidget", "<html><head/><body><p><a href=\"https://github.com/zhaomangang/WangWangChat.git\"><span style=\" text-decoration: underline; color:#0000ff;\">\347\202\271\345\207\273\346\255\244\345\244\204\350\216\267\345\217\226\351\241\271\347\233\256\346\272\220\347\240\201</span></a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWidget: public Ui_mainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
