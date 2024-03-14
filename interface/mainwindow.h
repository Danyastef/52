#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//#include "authregform.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PushButton_exit_clicked();
    //void slot_on_auth_good();

private:
    Ui::MainWindow *ui;
    //AuthRegForm * ui_reg;
};

#endif // MAINWINDOW_H
