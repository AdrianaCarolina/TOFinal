#ifndef DATABASEMANAGEMENT_H
#define DATABASEMANAGEMENT_H

#include <QString>
#include <QtSql>
#include <QDebug>

class DataBaseManagement
{
public:
    DataBaseManagement();
    bool open();
    bool execute(QString);
    QSqlQuery* getQuery(QString);
    bool close();
private:
    const QString TYPE_DRIVER="QSQLITE";
    const QString NAME_DATABASE="/home/rodrigo/Desktop/dbCine.sqlite";
    QSqlDatabase qSqlDataBase;
    QSqlQuery* qSqlQuery;
};

#endif // DATABASEMANAGEMENT_H
