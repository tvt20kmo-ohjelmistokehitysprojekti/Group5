#ifndef MENU_H
#define MENU_H

#include <QWidget>

namespace Ui {
class menu;
}

class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();

private slots:
    //void on_pushButton_clicked();

    void on_btnWithdraw_clicked();

    //void on_btnAccount_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
