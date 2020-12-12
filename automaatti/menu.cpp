#include "menu.h"
#include "ui_menu.h"
#include "withdraw.h"
#include "balance.h"

menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}


void menu::on_btnWithdraw_clicked()
{
    Withdraw *wit = new Withdraw();
    wit->show();
}

void menu::on_btnAccount_clicked()
{
    balance  *bal = new balance();
    bal->show();
}
