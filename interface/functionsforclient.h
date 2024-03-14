#ifndef FUNCTIONSFORCLIENT_H
#define FUNCTIONSFORCLIENT_H
#include "mainwindow.h"
#include "authregform.h"

#include <QObject>

class FunctionsForClient: public QObject
{
    Q_OBJECT
public:
    //void is_auth(QString, QString);
    FunctionsForClient();
signals:
    void on_auth_good();

private:
    MainWindow * ui_main;
    AuthRegForm * ui_auth;

public slots:
    void is_auth(QString, QString);
};
#endif // FUNCTIONSFORCLIENT_H
