#include "withdraw.h"
#include "ui_withdraw.h"
#include "creditdebit.h"
#include "mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <qjsondocument.h>
#include "mysingleton.h"
#include <QByteArray>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QWidget>
#include "menu.h"

Withdraw::Withdraw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Withdraw)
{
    ui->setupUi(this);
}

Withdraw::~Withdraw()
{
    delete ui;
    ui=nullptr;
}

void Withdraw::on_btnWithdraw20_clicked()
{
    amount = amount.setNum(20);
    ui->lineEditSumma->setText(amount);
}

void Withdraw::on_btnWithdraw40_clicked()
{
    amount = amount.setNum(40);
    ui->lineEditSumma->setText(amount);
}

void Withdraw::on_btnWithdraw50_clicked()
{
    amount = amount.setNum(50);
    ui->lineEditSumma->setText(amount);
}

void Withdraw::on_btnWithdraw100_clicked()
{
    amount = amount.setNum(100);
    ui->lineEditSumma->setText(amount);
}

void Withdraw::on_btnSuoritaNosto_clicked()
{
    if (amount!=20 || amount!=40 || amount!=50 || amount!=100) {
        amount = ui->lineEditSumma->text();
    }
    ui->lineEditSumma->clear();

    MySingleton *acc = MySingleton::getInstance();
    QString accountSelection = acc->getAccount();

    MySingleton *cardId = MySingleton::getInstance();
    QString id = cardId->getCardID();

    QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9kami06/Group5/RestApi/index.php/withdraw?id="+id+"&amount="+amount+"&tyyppi="+accountSelection));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QString username = "admin";
    QString password = "projekti";
    QString concatenatedCredentials = username + ":" + password;
    QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader("Authorization", headerData.toLocal8Bit());

    QNetworkAccessManager nam;
    QNetworkReply *reply = nam.get(request);
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }
    QByteArray response_data = reply->readAll();
    qDebug()<<response_data;
    ui->labelAmountValue->setText(response_data);
    reply->deleteLater();
}


void Withdraw::on_btntakaisin_clicked()
{
    this->close();
    menu  *m = new menu();
    m->show();
}


void Withdraw::on_btnsulje_clicked()
{
    this->close();
}
