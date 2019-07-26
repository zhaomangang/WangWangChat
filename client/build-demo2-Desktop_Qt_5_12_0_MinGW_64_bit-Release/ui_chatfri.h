/********************************************************************************
** Form generated from reading UI file 'chatfri.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATFRI_H
#define UI_CHATFRI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatFri
{
public:
    QTextEdit *messBrowser;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableView *tableView;
    QTextEdit *messEdit;
    QPushButton *sendButton;

    void setupUi(QWidget *ChatFri)
    {
        if (ChatFri->objectName().isEmpty())
            ChatFri->setObjectName(QString::fromUtf8("ChatFri"));
        ChatFri->resize(1031, 513);
        messBrowser = new QTextEdit(ChatFri);
        messBrowser->setObjectName(QString::fromUtf8("messBrowser"));
        messBrowser->setGeometry(QRect(10, 40, 731, 231));
        messBrowser->setReadOnly(true);
        pushButton = new QPushButton(ChatFri);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 290, 31, 26));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/face/face00.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton_2 = new QPushButton(ChatFri);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 290, 31, 26));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ico/tp.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        tableView = new QTableView(ChatFri);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(760, 50, 256, 421));
        messEdit = new QTextEdit(ChatFri);
        messEdit->setObjectName(QString::fromUtf8("messEdit"));
        messEdit->setGeometry(QRect(10, 320, 731, 131));
        sendButton = new QPushButton(ChatFri);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(660, 460, 80, 26));

        retranslateUi(ChatFri);

        QMetaObject::connectSlotsByName(ChatFri);
    } // setupUi

    void retranslateUi(QWidget *ChatFri)
    {
        ChatFri->setWindowTitle(QApplication::translate("ChatFri", "Form", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        sendButton->setText(QApplication::translate("ChatFri", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatFri: public Ui_ChatFri {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATFRI_H
