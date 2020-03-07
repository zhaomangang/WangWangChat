#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QTcpSocket>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    void setSocket(QTcpSocket *soc )
    {
        tcpSocket = soc;
    }
    void regiSucce(QString info);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Register *ui;
    QTcpSocket *tcpSocket;
    QDialog *icoDia;
    QVBoxLayout *layout_fri;
    QList <QPushButton *> icolist;
    QString icon;
};

#endif // REGISTER_H
