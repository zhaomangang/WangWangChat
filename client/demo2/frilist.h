#ifndef FRILIST_H
#define FRILIST_H
#include <QToolBox>
#include <QToolButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QList>
#include <QDebug>
#include "chatfri.h"

class FriList : public QToolBox
{
    Q_OBJECT
public:
    FriList(QWidget *parent=0,Qt::WindowFlags f=0);
    void setInfo(int id,QString user);
    void setLayFri();   //好友页布局
    void setLayGro();   //群组页布局
    void addFriend(int id,QString user,QString icon,QString desc,QString status);  //添加好友
    void addGroup(int id,QString name,QString icon,QString desc,QString status);   //添加群组
    void recvMessage(int sendid,QString data);
    void setSocket(QTcpSocket *soc)
    {
        tcpSocket = soc;
    }
private:
    QToolButton *toolBtn1;
    QList <QToolButton *>friend_list;   //好友列表
    QList <QToolButton *>group_list;    //群组列表
    QGroupBox *friendBox;   //好友页
    QGroupBox *groupBox;    //群组页
    QVBoxLayout *layout_fri;    //好友页布局
    QVBoxLayout *layout_group;  //群组页布局
    QList<ChatFri *>chat_list;  //聊天对话框列表
    QString user;
    int actid;  //当前登录用户
    QTcpSocket *tcpSocket;
    typedef struct{
    int id;
    QString user;
    }sender;
    QList<sender*>send_list;
public slots:

};



#endif // DRAWER_H
