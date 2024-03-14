#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui_reg = new AuthRegForm;
    //ui_reg -> show();
    //connect (ui_reg->get_func(), &FunctionsForClient::on_auth_good, this, &MainWindow::slot_on_auth_good);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PushButton_exit_clicked()
{
    this->close();
}
/*
void MainWindow::slot_on_auth_good() {
    delete ui_reg;
    this-> show();
}*/
