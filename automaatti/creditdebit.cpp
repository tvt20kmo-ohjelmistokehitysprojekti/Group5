#include "creditdebit.h"
#include "ui_creditdebit.h"
#include "withdraw.h"
#include "mysingleton.h"

creditdebit::creditdebit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::creditdebit)
{
    ui->setupUi(this);
}

creditdebit::~creditdebit()
{
    delete ui;
    ui=nullptr;
}

void creditdebit::on_btnCredit_clicked()
{
    Withdraw *wit = new Withdraw();
    wit->show();
    MySingleton *acc = MySingleton::getInstance();
    acc->setAccount("credit");
}

void creditdebit::on_btnDebit_clicked()
{
    Withdraw *wit = new Withdraw();
    wit->show();
    MySingleton *acc = MySingleton::getInstance();
    acc->setAccount("debit");
}
