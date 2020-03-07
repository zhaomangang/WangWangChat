/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
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
            mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->resize(293, 579);
        frame = new QFrame(mainWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 170, 291, 361));
        frame->setMinimumSize(QSize(291, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        info = new QFrame(mainWidget);
        info->setObjectName(QStringLiteral("info"));
        info->setGeometry(QRect(10, 10, 141, 151));
        info->setFrameShape(QFrame::StyledPanel);
        info->setFrameShadow(QFrame::Raised);
        icon = new QLabel(info);
        icon->setObjectName(QStringLiteral("icon"));
        icon->setGeometry(QRect(0, 0, 141, 151));
        username = new QLabel(mainWidget);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(160, 20, 71, 31));
        desci = new QLabel(mainWidget);
        desci->setObjectName(QStringLiteral("desci"));
        desci->setGeometry(QRect(160, 70, 111, 31));
        pushButton = new QPushButton(mainWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 540, 41, 31));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/pic/sera6174645.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(30, 30));
        pushButton_2 = new QPushButton(mainWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 540, 51, 26));
        label = new QLabel(mainWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 550, 121, 18));

        retranslateUi(mainWidget);

        QMetaObject::connectSlotsByName(mainWidget);
    } // setupUi

    void retranslateUi(QWidget *mainWidget)
    {
        mainWidget->setWindowTitle(QApplication::translate("mainWidget", "mainWidget", Q_NULLPTR));
        icon->setText(QApplication::translate("mainWidget", "icon", Q_NULLPTR));
        username->setText(QApplication::translate("mainWidget", "us", Q_NULLPTR));
        desci->setText(QApplication::translate("mainWidget", "de", Q_NULLPTR));
        pushButton->setText(QString());
        pushButton_2->setText(QApplication::translate("mainWidget", "\345\205\263\344\272\216", Q_NULLPTR));
        label->setText(QApplication::translate("mainWidget", "<html><head/><body><p><a href=\"https://github.com/zhaomangang/WangWangChat.git\"><span style=\" text-decoration: underline; color:#0000ff;\">\347\202\271\345\207\273\346\255\244\345\244\204\350\216\267\345\217\226\351\241\271\347\233\256\346\272\220\347\240\201</span></a></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mainWidget: public Ui_mainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
