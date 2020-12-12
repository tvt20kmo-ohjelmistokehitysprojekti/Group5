#ifndef CREDITDEBIT_H
#define CREDITDEBIT_H

#include <QWidget>

namespace Ui {
class creditdebit;
}

class creditdebit : public QWidget
{
    Q_OBJECT

public:
    explicit creditdebit(QWidget *parent = nullptr);
    ~creditdebit();
    QString accountSelection;
    QString id;

private slots:
    void on_btnCredit_clicked();

    void on_btnDebit_clicked();

private:
    Ui::creditdebit *ui;
};

#endif // CREDITDEBIT_H
