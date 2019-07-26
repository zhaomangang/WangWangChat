#include "chatfri.h"
#include "ui_chatfri.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QToolButton>
#include <QScrollBar>

ChatFri::ChatFri(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatFri)
{
    //id = 100001;
    ui->setupUi(this);
    icoDia = new QDialog(this);
    layout_fri = new QVBoxLayout(icoDia);
    layout_fri->setMargin(20);
    layout_fri->setAlignment(Qt::AlignCenter);
    AddIco();

    layout_lis = new QVBoxLayout(ui->tableView);
    QToolButton *tempButton = new QToolButton;
    QString iconpath = QString(":/pic/%1.ico").arg("01");
    QString text = QString("%1 <%2>").arg("zhao").arg("hahahahaha");
    tempButton->setText(text);
    qDebug()<<iconpath;
    tempButton->setIcon(QPixmap(iconpath));
    tempButton->setIconSize(QSize(100,30)); //设置按钮尺寸
    tempButton->setAutoRaise(true);   //当鼠标离开时，按钮恢复为弹起状态
    tempButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); //设置按钮文字显示在图标旁边
    layout_lis->addWidget(tempButton);
}

void ChatFri::closeEvent(QCloseEvent *event)
{
    qDebug()<<"销毁信号被发送";
    emit kill();
}
void ChatFri::setInfo(int id_, int frid_, QString user_, QString fri)
{
    qDebug()<<"shoudaoxiaoxi "<<id_;
    this->id = id_;
    this->friend_id = frid_;
    user = user_;
    userfriend = fri;
    QString title = QString("与[%1]聊天中").arg(userfriend);
    this->setWindowTitle(title);
}

void ChatFri::recvMessage(QString mess,int id_)
{
    //ui->messBrowser->setAlignment(Qt::AlignRight);
    QString temp_user;
    //int us = 100001;
    qDebug()<<"shoudaoxiaoxi "<<id<<"     "<<id_;
    if(id_ == this->id)
    {
        temp_user = user;
        ui->messBrowser->setAlignment(Qt::AlignRight);
    }else{
        temp_user = userfriend;
        ui->messBrowser->setAlignment(Qt::AlignLeft);
    }
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz ddd");
    QString temp = QString("%1 [%2]\n").arg(temp_user).arg(current_date);
    ui->messBrowser->append(temp);
    ui->messBrowser->insertHtml(mess);
    ui->messBrowser->append("\n");
    QScrollBar *scrollbar = ui->messBrowser->verticalScrollBar();
        if (scrollbar)
        {
            scrollbar->setSliderPosition(scrollbar->maximum());
        }
}
void ChatFri::AddIco()
{
    //添加表情
    for(int i=0;i<7;i++)
    {
        QString path = QString(":/face/face0%1.ico").arg(i);
        QPushButton *bu_temp = new QPushButton(icoDia);
        bu_temp->setIcon(QPixmap(path));
        qDebug()<<"path is "<<path;
        icolist.append(bu_temp);
        layout_fri->addWidget(bu_temp);
        connect(bu_temp,&QPushButton::clicked,
                [=]() mutable
                {
                    this->icoDia->hide();
                    qDebug()<<path;
                    QString path_ = QString("<img src=\"%1\"/>").arg(path);
                    ui->messEdit->insertHtml(path_);
                    //ui->messEdit->append("\n");
                }
                );

    }
}




ChatFri::~ChatFri()
{
    delete ui;
}

void ChatFri::on_pushButton_pressed()
{
    icoDia->show();
}


void ChatFri::on_sendButton_clicked()
{

    qDebug()<<"ui:"<<ui->messEdit->toPlainText();
    qDebug()<<ui->messEdit->toHtml();
    QString str = ui->messEdit->toHtml();
    //QString temp = ui->messEdit->toPlainText();
    recvMessage(str,this->id);
    str = QString("message %1 %2 %3").arg(this->id).arg(this->friend_id).arg(str);

    ui->messEdit->clear();
    tcpSocket->write(str.toUtf8().data());
}

void ChatFri::on_pushButton_2_clicked()
{

    QString path = QFileDialog::getOpenFileName(this,
                                                 "open","../","PNG(*.png)");
    if(path.isEmpty() == false)
    {
        path = QString("<img src=\"%1\"/>").arg(path);
        ui->messEdit->insertHtml(path);
    }


}
