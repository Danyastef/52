#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QObject>
#include <QString>
#include <QByteArray>

QByteArray parse(QString data_from_client);
QByteArray auth(QString log, QString pass);
QByteArray reg(QString log, QString pass, QString mail);

#endif // FUNCTIONS_H
