#include "menu.h"
#include "ui_menu.h"
#include "withdraw.h"
#include "creditdebit.h"
#include "ui_creditdebit.h"
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
    creditdebit *cd = new creditdebit();
    cd->show();
    this->close();

}

//void menu::on_btnAccount_clicked()
//{
  //  balance  *bal = new balance();
    //bal->show();
//}


void menu::on_btnAccount_clicked()
{
    balance  *bal = new balance();
    bal->show();
    this->close();
}
