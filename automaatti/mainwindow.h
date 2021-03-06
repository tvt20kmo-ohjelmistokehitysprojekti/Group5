#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString CardId;
    QString CardPin;

private slots:
    void on_btnLogin_clicked();

    //void on_btnWithdraw_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
