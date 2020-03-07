#include "landwidget.h"
#include "ui_landwidget.h"
#include <QMessageBox>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonArray>

LandWidget::LandWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LandWidget)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
    setFixedSize(445,508);                     // 禁止拖动窗口大小
    setWindowTitle(QStringLiteral("登录"));    //设置窗口标题

    ui->password->setEchoMode(QLineEdit::Password); //设置密码编辑框为隐藏模式

}

void LandWidget::setTcpSocket(QTcpSocket *tcp)
{
    //设置通信套接字
    tcpSocket = tcp;
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(slotDataRecv()));   //将收到服务器消息信号与槽函数建立连接
}


LandWidget::~LandWidget()
{
    delete ui;
}

bool LandWidget::judgement(QByteArray array)
{
    //判断服务器返回的消息是否是信息匹配，如果是返回true否则返回false
    //服务器返回消息格式
    /*
     * {
    "PacketType": "land_success"
    }
     */
    //解包
    /*
     * 测试用例
     * */
    QString temp = array;
    QString type = NULL;
    QString user = NULL;
    int i=0;
    for(i=0;i<temp.size();i++)
    {
        if(temp[i] == ' ')
        {
            i++;
            break;
        }
        type[i] = temp[i];
    }

    if(type == "success")
    {
        for(int j=0;i<temp.size();i++,j++)
        {
            if(temp[i]==' ')
            {
                break;
            }
            user[j] = temp[i];
        }
        user_active = user.toInt();
        return true;
    }else if(type == "register_su"){

        regi->regiSucce(temp);
    }
    else{
        QMessageBox::warning(this,QStringLiteral("错误"),QStringLiteral("账号或密码错误"));
    }
    return false;
}

void LandWidget::slotDataRecv()
{
    //收到服务器消息时
    if(judgement(tcpSocket->readAll()))//读取服务器消息并判断
    {
        //服务器返回登陆信息正确
        emit landSuccess(); //给主窗口发送登陆成功信号
    }
    else{

    }

}
void LandWidget::on_send_clicked()
{
    //点击登陆按钮时
    if(ui->id->text()=="")
    {
        //当id未填写时
        QMessageBox::warning(this,QStringLiteral("错误"),QStringLiteral("请填写id"));
    }else {
        if(ui->password->text()=="")
        {
            //当密码未填写时
            QMessageBox::warning(this,QStringLiteral("错误"),QStringLiteral("请填写密码"));
        }else {
            //账号密码都填写时
            if(ui->remember->isChecked())
            {
                //当记住密码被选中时

            }
            tcpSocket->write(landPack(ui->id->text().toInt(),ui->password->text()).toUtf8().data());//将登陆信息打包发给服务器
            //emit landSuccess();
        }
    }

}
QString LandWidget::landPack(int id, QString password)
{
    QString temp = QString("%1 %2 %3 ").arg("login").arg(id).arg(password);
    return temp;
}

void LandWidget::on_registeButton_clicked()
{
    //点击注册按钮
    regi = new Register;
    regi->show();
    regi->setSocket(this->tcpSocket);
}


