#include "functionsforclient.h"

FunctionsForClient::FunctionsForClient()
{
    ui_auth = new AuthRegForm;
    ui_auth->show();
    connect (ui_auth, &AuthRegForm::is_auth, this, &FunctionsForClient::is_auth);
}

void FunctionsForClient::is_auth(QString log, QString pass)
{
    //??? answer = send_to_server("auth&"+log+"&"+pass)
    //if (answer.substr(0,5) == "auth+")
    if (log == "user" && pass == "123")
    {
        delete ui_auth;
        ui_main = new MainWindow;
        ui_main->show();
        //emit on_auth_good();
    }
    //else
    //.....
}
