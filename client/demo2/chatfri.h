#ifndef CHATFRI_H
#define CHATFRI_H

#include <QWidget>
#include <QDialog>
#include <QList>
#include <QPushButton>
#include <QDebug>
#include <QVBoxLayout>
#include <QDateTime>
#include <QTcpSocket>
#include <QCloseEvent>
namespace Ui {
class ChatFri;
}

class ChatFri : public QWidget
{
    Q_OBJECT

public:
    explicit ChatFri(QWidget *parent = nullptr);
    ~ChatFri();
    void AddIco();  //添加
    void recvMessage(QString mess,int id);
    void setInfo(int id_,int frid_,QString user,QString fri); //设置对话框
    int getFrid()
    {
        return this->friend_id;
    }
    void setSocket(QTcpSocket *sock)
    {
        this->tcpSocket = sock;
    }

private slots:
    void on_pushButton_pressed();

    void on_sendButton_clicked();

    void on_pushButton_2_clicked();

protected:
    //void mousePressEvent(QMouseEvent* event);
public slots:
protected:
    void closeEvent(QCloseEvent *event);

signals:
    void kill();

private:
    QVBoxLayout *layout_fri;
    QVBoxLayout *layout_lis;
    QList <QPushButton *> icolist;
    Ui::ChatFri *ui;
    QDialog *icoDia;
    int id; //当前用户
    int friend_id;  //对话框用户
    QString user;
    QString userfriend;
    QTcpSocket *tcpSocket;
};

#endif // CHATFRI_H
