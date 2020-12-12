#ifndef BALANCE_H
#define BALANCE_H

#include <QString>
#include <QWidget>
#include "mainwindow.h"
extern QString CardId;
namespace Ui {
class balance;


}

class balance : public QWidget
{
    Q_OBJECT

public:
    explicit balance(QWidget *parent = nullptr);
    ~balance();

private slots:
    void on_btnAmount_clicked();

private:
    Ui::balance *ui;


};

#endif // BALANCE_H
