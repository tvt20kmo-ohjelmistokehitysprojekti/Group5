#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QNetwork>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <qjsondocument.h>
#include "menu.h"
#include "mysingleton.h"
#include <QByteArray>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLogin_clicked()
{
    QString CardId, CardPin;
    CardId = ui->lineEditCardId->text();
    CardPin = ui->lineEditCardPin->text();

    MySingleton *my = MySingleton::getInstance();
    my->setCardID(CardId);

    QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9kami06/Group5/RestApi/index.php/login?idkortti="+CardId+"&tunnusluku="+CardPin));
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
        qDebug() << "DATA:" +response_data;
        reply->deleteLater();

        if(response_data.compare("true") == 0) {
            menu *men = new menu();
            men->show();
            ui->lineEditCardId->clear();
            ui->lineEditCardPin->clear();
        }
        else {
            ui->lineEditCardId->clear();
            ui->lineEditCardPin->clear();
        }
}
