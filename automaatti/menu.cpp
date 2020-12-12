#include "menu.h"
#include "ui_menu.h"
#include "withdraw.h"
#include "creditdebit.h"
#include "ui_creditdebit.h"

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

}

/*void menu::on_btnAccount_clicked()
{

}*/
