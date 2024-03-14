#include "authregform.h"
#include "ui_authregform.h"

AuthRegForm::AuthRegForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuthRegForm)
{
    ui->setupUi(this);
    ui->labelemail->setVisible(false);
    ui->lineEdit_email->setVisible(false);
    ui->pushButton_reg->setVisible(false);
}

AuthRegForm::~AuthRegForm()
{
    delete ui;
}

void AuthRegForm::on_pushButton_auth_clicked()
{

    emit is_auth(ui->lineEdit_login->text(), ui->lineEdit_password->text());
}

void AuthRegForm::on_pushButton_change_clicked()
{
    bool flag = ui->labelemail->isVisible();

        ui->labelemail->setVisible(!flag);
        ui->lineEdit_email->setVisible(!flag);
        ui->pushButton_reg->setVisible(!flag);
        ui->pushButton_auth->setVisible(flag);
}
/*
FunctionsForClient * AuthRegForm::get_func(){
    return &(this->func);
}
*/
