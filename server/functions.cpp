#include <functions.h>

QByteArray parse(QString data_from_client)
{
    QStringList data_from_client_list = data_from_client.split('&');
    QString func = data_from_client_list.front();
    data_from_client_list.pop_front();
    if (func == "auth")
    {
        return auth(data_from_client_list.at(0),data_from_client_list.at(1));
    }
    else if (func == "reg")
    {
        return reg(data_from_client_list.at(0),data_from_client_list.at(1),data_from_client_list.at(2));
    }
    else if (func == "\xFF\xFB\x1F\xFF\xFB \xFF\xFB\x18\xFF\xFB'\xFF\xFD\x01\xFF\xFB\x03\xFF\xFD\x03")
        return "";
    else
        return "ERROR\r\n";
}
QByteArray auth(QString log, QString pass)
{
    return "auth\r\n";
}
QByteArray reg(QString log, QString pass, QString mail)
{
    return "reg\r\n";
}
