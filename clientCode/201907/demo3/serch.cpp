#include "serch.h"
#include "ui_serch.h"
#include <QMessageBox>
Serch::Serch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Serch)
{
    ui->setupUi(this);
}

Serch::~Serch()
{
    delete ui;
}

void Serch::on_pushButton_clicked()
{
    //点击搜索
    QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("该功能暂未完成"));
    this->hide();
}
