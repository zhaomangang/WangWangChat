#include "frilist.h"
#include <QGroupBox>
#include <QVBoxLayout>

FriList::FriList(QWidget *parent,Qt::WindowFlags f)
    :QToolBox(parent,f)
{
    friendBox = new QGroupBox;
    groupBox = new QGroupBox;

    this->setLayFri();
    this->setLayGro();
}

void FriList::setLayFri()
{
    //好友页布局
    layout_fri = new QVBoxLayout(friendBox);
    layout_fri->setMargin(45);
    layout_fri->setAlignment(Qt::AlignLeft);
    this->addItem((QWidget*)friendBox,QStringLiteral("好友列表"));
}
void FriList::setLayGro()
{
    //群组页布局
    layout_group = new QVBoxLayout(groupBox);
    layout_fri->setMargin(45);
    layout_fri->setAlignment(Qt::AlignLeft);
    this->addItem((QWidget*)groupBox,QStringLiteral("群组列表"));
}
void FriList::recvMessageGroup(int sendid, QString data)
{
    for(int i=0;i<chat_list.size();i++)
    {
        if(7001 == chat_list.at(i)->id_group)
        {
            chat_list.at(i)->recvMessage(data,sendid,true);
            return ;
        }
    }
    ChatFri *tempfri = new ChatFri();
    tempfri->setSocket(tcpSocket);
    tempfri->id_group = 7001;
    QString se = QString("%1").arg(sendid);
    tempfri->setInfo(actid,7001,this->user,"7001");
    tempfri->show();
    tempfri->recvMessage(data,sendid,true);
    chat_list.append(tempfri);
    connect(tempfri,&ChatFri::kill,
            [=]() mutable
            {
                qDebug()<<"关闭对话框";
                for(int i=0;i<chat_list.size();i++)
                {
                    if(chat_list.at(i)->getFrid() == tempfri->getFrid())
                    {
                        chat_list.removeAt(i);
                        qDebug()<<"关闭成功";
                    }
                }
            }
            );


}
void FriList::recvMessage(int sendid, QString data)
{

    for(int i=0;i<chat_list.size();i++)
    {
        if(sendid == chat_list.at(i)->getFrid())
        {
            chat_list.at(i)->recvMessage(data,sendid,false);
            return ;
        }
    }
    qDebug()<<"line 42 收到消息";
    QString senduser = QString("%1").arg(sendid);
    for(int i=0;i<send_list.size();i++)
    {
        qDebug()<<"查询 ："<<send_list.at(i)->id;
        if(sendid == send_list.at(i)->id)
        {
            senduser = send_list.at(i)->user;
        }
    }
    ChatFri *tempfri = new ChatFri();
    tempfri->setSocket(tcpSocket);
    tempfri->setInfo(actid,sendid,this->user,senduser);
    tempfri->show();
    tempfri->recvMessage(data,sendid,false);
    chat_list.append(tempfri);
    connect(tempfri,&ChatFri::kill,
            [=]() mutable
            {
                qDebug()<<"关闭对话框";
                for(int i=0;i<chat_list.size();i++)
                {
                    if(chat_list.at(i)->getFrid() == tempfri->getFrid())
                    {
                        chat_list.removeAt(i);
                        qDebug()<<"关闭成功";
                    }
                }
            }
            );

}

void FriList::addFriend(int id, QString user, QString icon, QString desc,QString status)
{
    QToolButton *tempButton = new QToolButton;
    QString iconpath = QString(":/icon/%1.ico").arg(icon);
    QString text = QString("%1 <%2>").arg(user).arg(desc);
    tempButton->setText(text);
    qDebug()<<iconpath;
    tempButton->setIcon(QPixmap(iconpath));
    tempButton->setIconSize(QSize(100,30)); //设置按钮尺寸
    tempButton->setAutoRaise(true);   //当鼠标离开时，按钮恢复为弹起状态
    tempButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); //设置按钮文字显示在图标旁边
    friend_list.append(tempButton);
    layout_fri->addWidget(friend_list.last());
    sender *temp = new sender();
    temp->id = id;
    temp->user = user;
    send_list.append(temp);
    connect(tempButton,&QPushButton::clicked,
            [=]() mutable
            {
                int biaozhi = 0;
                for(int i=0;i<chat_list.size();i++)
                {
                    if(chat_list.at(i)->getFrid()==id)
                    {
                        //防止多开聊天界面
                        biaozhi = 1;
                        break;
                    }

                }
                if(!biaozhi)
                {
                    qDebug()<<"line 49 clicked:";
                    ChatFri *tempfri = new ChatFri();
                    tempfri->setSocket(tcpSocket);
                    tempfri->setInfo(actid,id,this->user,user);
                    tempfri->show();
                    chat_list.append(tempfri);
                    connect(tempfri,&ChatFri::kill,
                            [=]() mutable
                            {
                                qDebug()<<"关闭对话框";
                                for(int i=0;i<chat_list.size();i++)
                                {
                                    if(chat_list.at(i)->getFrid() == tempfri->getFrid())
                                    {
                                        chat_list.removeAt(i);
                                        qDebug()<<"关闭成功";
                                    }
                                }
                            }
                            );
                }

            }
            );
}
void FriList::setInfo(int id, QString use)
{
    actid  = id;
    user = use;
}
void FriList::addGroup(int id, QString name, QString icon, QString desc,QString status)
{
    QToolButton *tempButton = new QToolButton;
    QString iconpath = QString(":/icon/%1.ico").arg(icon);
    QString text = QString("%1 <%2>").arg(name).arg(desc);
    tempButton->setText(text);
    qDebug()<<iconpath;
    tempButton->setIcon(QPixmap(iconpath));
    tempButton->setIconSize(QSize(100,30)); //设置按钮尺寸
    tempButton->setAutoRaise(true);   //当鼠标离开时，按钮恢复为弹起状态
    tempButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); //设置按钮文字显示在图标旁边
    group_list.append(tempButton);
    layout_group->addWidget(group_list.last());
    sender *temp = new sender();
    temp->id = id;
    temp->user = name;
    send_list.append(temp);
    //qDebug()<<
    connect(tempButton,&QPushButton::clicked,
            [=]() mutable
            {
                int biaozhi = 0;
                for(int i=0;i<chat_list.size();i++)
                {
                    if(chat_list.at(i)->id_group==7001)
                    {
                        //防止多开聊天界面
                        biaozhi = 1;
                        break;
                    }

                }
                if(!biaozhi)
                {
                    qDebug()<<"line 49 clicked:";
                    ChatFri *tempfri = new ChatFri();
                    tempfri->id_group = 7001;
                    tempfri->setSocket(tcpSocket);
                    tempfri->setInfo(actid,7001,this->user,"7001");
                    tempfri->show();
                    chat_list.append(tempfri);
                    connect(tempfri,&ChatFri::kill,
                            [=]() mutable
                            {
                                qDebug()<<"关闭对话框";
                                for(int i=0;i<chat_list.size();i++)
                                {
                                    if(chat_list.at(i)->getFrid() == tempfri->getFrid())
                                    {
                                        chat_list.removeAt(i);
                                        qDebug()<<"关闭成功";
                                    }
                                }
                            }
                            );
                }

            }
            );

}


