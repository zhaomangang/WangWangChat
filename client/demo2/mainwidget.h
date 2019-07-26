#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QWidget>
#include <QTcpSocket>
#include <QJsonObject>
#include <QGroupBox>
#include <QToolButton>
#include <QList>
#include "frilist.h"
#include "landwidget.h"
#include "chatfri.h"
#include <QMediaPlayer>
namespace Ui {
class mainWidget;
}

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = nullptr);
    ~mainWidget();
    bool connectToServer(); //连接服务器函数
    void setUserInfo(QString info);   //设置用户信息
    void setFriend(QString info);   //加载好友列表
    void setGroup(QString info);    //加载群组
    void requestUserInfo(); //请求用户信息
    void dealMessage(QString info);
public slots:
    void slotRecv();    //收到服务器消息
private slots:
    void on_pushButton_clicked();

private:
    Ui::mainWidget *ui;
    QTcpSocket *tcpSocket;  //通信套接字声明
    LandWidget *land;   //登陆界面声明
    int user_active;    //当前登录的用户
    FriList *fr;    //好友列表
    QMediaPlayer *player;
};

typedef struct{
    QString id;
    QString user;
    QString icon;
    QString signature;
    QString status;
}Friend;

#endif // MAINWIDGET_H
