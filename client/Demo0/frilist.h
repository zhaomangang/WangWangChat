#ifndef FRILIST_H
#define FRILIST_H

#include <QWidget>

namespace Ui {
class FriList;
}

class FriList : public QWidget
{
    Q_OBJECT

public:
    explicit FriList(QWidget *parent = nullptr);
    ~FriList();

private:
    Ui::FriList *ui;
};

#endif // FRILIST_H
