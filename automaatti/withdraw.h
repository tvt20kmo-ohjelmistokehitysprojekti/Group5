#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QWidget>

namespace Ui {
class Withdraw;
}

class Withdraw : public QWidget
{
    Q_OBJECT

public:
    explicit Withdraw(QWidget *parent = 0);
    ~Withdraw();

private slots:

    //void on_btnMuuSumma_clicked();

    void on_btnWithdraw20_clicked();

    void on_btnWithdraw40_clicked();

    void on_btnWithdraw50_clicked();

    void on_btnWithdraw100_clicked();

    void on_lineEditSumma_textChanged(const QString &arg1);

    void on_btnSuoritaNosto_clicked();

private:
    Ui::Withdraw *ui;
    QString amount;
    QString id;
};

#endif // WITHDRAW_H
