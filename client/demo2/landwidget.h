#ifndef LANDWIDGET_H
#define LANDWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include "register.h"
namespace Ui {
class LandWidget;
}

class LandWidget : public QWidget
{
    Q_OBJECT

public:
    int user_active;    //当前用户
    explicit LandWidget(QWidget *parent = nullptr);
    ~LandWidget();
    void setTcpSocket(QTcpSocket *tcp); //设置通信套接字
    QString landPack(int id,QString password); //打包登陆信息
    bool judgement(QByteArray array);    //判断服务器返回的数据
public slots:
    void slotDataRecv();    //处理收到的服务器消息

signals:
    void landSuccess(); //登陆成功信号


private slots:
    void on_send_clicked();

    void on_registeButton_clicked();

private:
    Ui::LandWidget *ui;
    QTcpSocket *tcpSocket;
    Register *regi;
};

#endif // LANDWIDGET_H
