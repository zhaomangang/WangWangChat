#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "frilist.h"
#include <QHostAddress>
#include <QMessageBox>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonArray>
#include <QDateTime>
#include <QDir>
#include <QAction>
mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
    setFixedSize(295,700);                     // 禁止拖动窗口大小
    connectToServer();  //连接服务器

    //与服务成功建立连接

    land = new LandWidget();
    land->setTcpSocket(tcpSocket);  //为land设置通信套接字
    land->show();   //显示登陆窗口

    connect(land,&LandWidget::landSuccess,
            [=]()
            {
                //当登陆界面传来登陆成功信号时
                land->hide();   //隐藏登陆窗口
                this->show();   //显示主窗口
                this->user_active = land->user_active;
                delete land;   //登陆成功后销毁登陆界面对象
                connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(slotRecv()));
                this->requestUserInfo();
                //this->setUserInfo("00","kidjkod","this is a test user");
            }

            );
    fr = new FriList(ui->frame);
    fr->setSocket(tcpSocket);
//    fr->addFriend(10001,"kid","00","hahah","0");
    fr->addFriend(10001,"bug反馈","00","测试用户","1");
    fr->addGroup(11111,"itKim","07","it 交流","0");
//    fr->addGroup(22222,"闲聊","06","闲聊群","1");
    player = new QMediaPlayer;
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    player->setMedia(QUrl("qrc:/sound/Global.wav"));
    player->setVolume(30);
    //player->play();
}
void mainWidget::requestUserInfo()
{
    QString temp = QString("%1 %2").arg("inituser").arg(user_active);
    tcpSocket->write(temp.toUtf8().data());//将登陆信息打包发给服务器
}
mainWidget::~mainWidget()
{
    delete ui;
}

bool mainWidget::connectToServer()
{
    //打开程序时尝试与服务器建立连接

    //分配空间指定父对象
    tcpSocket = new QTcpSocket(this);

    //获取服务器IP和端口
    QString ip = "39.106.102.75";//"39.106.102.75";//"127.0.0.1";//"192.168.1.106";
    quint16 port = 8888;//48788;//8888;s

    //主动和服务器建立连接
    tcpSocket->connectToHost(QHostAddress(ip),port);
    return true;
}
void mainWidget::slotRecv()
{

    QByteArray array = tcpSocket->readAll();//取出消息内容
    qDebug()<<"array is"<<array;
    //解包获取信息类型
    QString temp = array;
    QString type = NULL;
    int mess_type = -1;
    for(int i =0;i<temp.size();i++)
    {
        if(temp[i] == ' ')break;
        type[i] = temp[i];
    }
    qDebug()<<"line52 type"<<type;
    if(type == "userinfo")
    {
        mess_type = 0;
    }
    else if (type == "message") {
        mess_type = 1;
        player->play();
    }
    else if(type == "friendinfo"){
        mess_type = 2;
    }
    else if(type == "groupinfo"){
        mess_type = 3;
    }
    switch (mess_type) {

    case 0:
        //收到服务器发送的用户信息
        setUserInfo(temp);//设置信息
        break;
    case 1:
        //收到消息
        this->dealMessage(temp);
        break;
    case 2:
        //好友信息
        this->setFriend(temp);
        break;
    case 3:
        //群组信息
        setGroup(temp);
        break;
    default:
        break;

    }


}
void mainWidget::dealMessage(QString info)
{
    qDebug()<<"line128 收到消息"<<info;
    int i=0;
    int j=0;
    QString send;
    QString data;
    for(i=0;i<info.size();i++)
    {
        if(info[i]==' ')
        {
            i++;
            break;
        }
    }
    for(j=0;j<info.size();j++,i++)
    {
        if(info[i]==' ')
        {
            i++;
            break;
        }
        send[j] = info[i];
    }
    for(j=0;i<info.size();j++,i++)
    {
        //if('0' == data[i] && data[i+1]== 'u')
        data[j] = info[i];
    }

    qDebug()<<"send is "<<send <<"data is "<<data;
    fr->recvMessage(send.toInt(),data);
}

void mainWidget::setGroup(QString info)
{
    //加载群组
    qDebug()<<"line129: "<<info;
    //加载好友列表
    QList<Friend> friend_list;
    //QList<Friend> group_list;
    Friend temp; //= new Friend;
    int i =0;
    for(i = 0;i<info.size();i++)
    {
        if(info[i] == '#')
        {
            i++;
            break;
        }
    }
    for(;i<info.size();i++)
    {

        qDebug()<<"line 137 i is "<<i;

        for(int k=0;i<info.size();k++,i++)
        {
            if(info[i] == ' ')
            {
                i++;
                break;
            }
            temp.id[k] = info[i];
            qDebug()<<"line 153 i is "<<i;
        }
        for(int k =0;i<info.size();k++,i++)
        {
            if(info[i] == ' ')
            {
                i++;
                break;
            }
            temp.user[k] = info[i];
            qDebug()<<"line 163 i is "<<i;
        }
        for(int k =0;i<info.size();k++,i++)
        {
            if(info[i] == ' ')
            {
                i++;
                break;
            }
            temp.signature[k] = info[i];
            qDebug()<<"line 173 i is "<<i;
        }
        qDebug()<<"line178 "<<temp.signature;
        for(int k =0;i<info.size();k++,i++)
        {
            if(info[i] == ' ')
            {
                i++;
                break;
            }
            temp.icon[k] = info[i];
            qDebug()<<"line 183 i is "<<i;
        }
        for(int k =0;i<info.size();k++,i++)
        {
            if(info[i] == ' ')
            {
                i++;
                break;
            }
            temp.status[k] = info[i];
            qDebug()<<"line 193 i is "<<i;
        }
        if(info[i] == '#')
        {
            qDebug()<<"line 141 add ";
            friend_list.append(temp);
            temp.signature = " ";
          //  continue;
        }
    }
    qDebug()<<"line 200 i is "<<friend_list.size();
    for(int j=0;j<friend_list.size();j++)
    {
        fr->addGroup(friend_list.at(j).id.toInt(),friend_list.at(j).user,friend_list.at(j).icon,friend_list.at(j).signature,friend_list.at(j).status);
        qDebug()<<"line 200 i is "<<friend_list.at(j).id.toInt()<<friend_list.at(j).user<<friend_list.at(j).icon<<friend_list.at(j).signature<<friend_list.at(j).status;
    }

}
void mainWidget::setFriend(QString info)
{
    //加载好友列表
    QList<Friend> friend_list;
    //QList<Friend> group_list;
    Friend temp; //= new Friend;
    int i =0;
    for(i = 0;i<info.size();i++)
    {
        if(info[i] == '#')
        {
            i++;
            break;
        }
    }
    for(;i<info.size();i++)
    {

        qDebug()<<"line 137 i is "<<i;

        for(int k=0;i<info.size();k++,i++)
        {
            if(info[i] == ' ')
            {
                i++;
                break;
            }
            temp.id[k] = info[i];
            qDebug()<<"line 153 i is "<<i;
        }
        for(int k =0;i<info.size();k++,i++)
        {
            if(info[i] == ' ')
            {
                i++;
                break;
            }
            temp.user[k] = info[i];
            qDebug()<<"line 163 i is "<<i;
        }
        for(int k =0;i<info.size();k++,i++)
        {
            if(info[i] == ' ')
            {
                i++;
                break;
            }
            temp.signature[k] = info[i];
            qDebug()<<"line 173 i is "<<i;
        }
        for(int k =0;i<info.size();k++,i++)
        {
            if(info[i] == ' ')
            {
                i++;
                break;
            }
            temp.icon[k] = info[i];
            qDebug()<<"line 183 i is "<<i;
        }
        for(int k =0;i<info.size();k++,i++)
        {
            if(info[i] == ' ')
            {
                i++;
                break;
            }
            temp.status[k] = info[i];
            qDebug()<<"line 193 i is "<<i;
        }
        if(info[i] == '#')
        {
            qDebug()<<"line 141 add ";
            friend_list.append(temp);

          //  continue;
        }
    }
    qDebug()<<"line 200 i is "<<friend_list.size();
    for(int j=0;j<friend_list.size();j++)
    {
        fr->addFriend(friend_list.at(j).id.toInt(),friend_list.at(j).user,friend_list.at(j).icon,friend_list.at(j).signature,friend_list.at(j).status);
        qDebug()<<"line 200 i is ";
    }


}
void mainWidget::setUserInfo(QString info)
{
    qDebug()<<"line115 "<<info;
    int i;
   // char id[10];
    QString id;
    QString icon;
    QString username;
    QString desc;
    for(i =0;i<info.size();i++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        }
    }
    for(int j=0;i<info.size();i++,j++)
    {
        //qDebug()<<info[i];
        if(info[i] == ' ')
        {
            i++;
            break;
        }

        id[j] = info[i];
    }
    this->user_active = id.toInt();
    for(int j=0;i<info.size();i++,j++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        }

        username[j] = info[i];
    }
    for(int j=0;i<info.size();i++,j++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        }

        icon[j] = info[i];
    }
    for(int j=0;i<info.size();i++,j++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        }

        desc[j] = info[i];
    }
    qDebug()<<"line 165"<<id<<" "<<username<<" "<<icon<<" "<<desc;

    //设置用户信息
    QString iconpath = QString(":/icon/%1.ico").arg(icon);
    ui->icon->setPixmap(QPixmap(iconpath));
    ui->username->setText(username);
    ui->desci->setText(desc);
    fr->setInfo(id.toInt(),username);


    //发送好友信息加载请求
    QString temp = QString("%1 %2").arg("initfriend").arg(user_active);
    qDebug()<<temp;
    tcpSocket->write(temp.toUtf8().data());
}


void mainWidget::on_pushButton_clicked()
{
    //点击搜索按钮

}
