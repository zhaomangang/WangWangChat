#ifndef SERCH_H
#define SERCH_H

#include <QWidget>
#include <QTcpSocket>
namespace Ui {
class Serch;
}

class Serch : public QWidget
{
    Q_OBJECT

public:
    explicit Serch(QWidget *parent = nullptr);
    ~Serch();
    void setsocket(QTcpSocket *tcp)
    {
        tcpSocket = tcp;
    }


private slots:
    void on_pushButton_clicked();

private:
    Ui::Serch *ui;
    QTcpSocket *tcpSocket;
};

#endif // SERCH_H
