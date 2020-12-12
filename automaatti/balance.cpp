#include "balance.h"
#include "ui_balance.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <qjsondocument.h>
#include <QByteArray>
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "mainwindow.h"
#include "mysingleton.h"

balance::balance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::balance)
{
    ui->setupUi(this);
}

balance::~balance()
{
    delete ui;
}

void balance::on_btnAmount_clicked()
{
    MySingleton *my = MySingleton::getInstance();
    QString idCard = my->getCardID();

    QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9kami06/Group5/RestApi/index.php/account?idkortti=""&tyyppi="));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QString username = "admin";
        QString password = "projekti";
        QString concatenatedCredentials = username + ":" + password;
            QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
            QString headerData = "Basic " + data;
            request.setRawHeader("Authorization", headerData.toLocal8Bit());

        QNetworkAccessManager man;
        QNetworkReply *reply = man.get(request);
        while(!reply->isFinished()) {
            qApp->processEvents();
        }
     QByteArray response_data = reply->readAll();
     QJsonDocument baldoc = QJsonDocument::fromJson(response_data);
     QJsonObject jobj = baldoc.object();
     QJsonArray jarr = baldoc.array();
     QString bal1;
     foreach (const QJsonValue &value, jarr) {
       QJsonObject jsob = value.toObject();
       bal1+=jsob["idkortti"].toString()+", "+jsob["avauspvm"].toString()+", "+jsob["saldo"].toString()+", "+jsob["tyyppi"].toString()+"\r";
       ui->textID->setText(bal1);
     }




     {
        QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9kami06/Group5/RestApi/index.php/transaction?idkortti="+idCard));
            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

            QString username = "admin";
            QString password = "projekti";
            QString concatenatedCredentials = username + ":" + password;
                QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
                QString headerData = "Basic " + data;
                request.setRawHeader("Authorization", headerData.toLocal8Bit());

            QNetworkAccessManager man;
            QNetworkReply *reply = man.get(request);
            while(!reply->isFinished()) {
                qApp->processEvents();
            }
         QByteArray response_data = reply->readAll();
         QJsonDocument baldoc = QJsonDocument::fromJson(response_data);
         QJsonObject jobj = baldoc.object();
         QJsonArray jarr = baldoc.array();
         QString bal2;
         foreach (const QJsonValue &value, jarr) {
           QJsonObject jsob = value.toObject();
           bal2+=jsob["idtapahtuma"].toString()+", "+jsob["tapahtuma"].toString()+", "+jsob["tyyppi"].toString()+", "+jsob["summa"].toString()+", "+jsob["pvm"].toString()+"\r";
           ui->textTapahtumat->setText(bal2);
         }







            reply->deleteLater();
    }
}


