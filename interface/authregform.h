#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H
//#include "functionsforclient.h"
#include <QWidget>

namespace Ui {
class AuthRegForm;
}

class AuthRegForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthRegForm(QWidget *parent = nullptr);
    ~AuthRegForm();
    //FunctionsForClient * get_func();

signals:
    void is_auth(QString, QString);
    //void auth_good();

private slots:
    void on_pushButton_auth_clicked();

    void on_pushButton_change_clicked();

private:
    Ui::AuthRegForm *ui;
    //FunctionsForClient func;
};

#endif // AUTHREGFORM_H
