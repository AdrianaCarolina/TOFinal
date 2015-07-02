#ifndef DATABASEMANAGEMENT_H
#define DATABASEMANAGEMENT_H

#include <QString>
#include <QtSql>
#include <QDebug>

class DataBaseManagement
{
public:
    bool open();
    bool execute(QString);
    QSqlQuery* getQuery(QString);
    bool close();
    static DataBaseManagement* initialize();
private:
    DataBaseManagement();
    const QString TYPE_DRIVER="QSQLITE";
    const QString NAME_DATABASE="/home/rodrigo/Desktop/dbCine.sqlite";
    QSqlDatabase qSqlDataBase;
    QSqlQuery* qSqlQuery;
    static DataBaseManagement* instance;
};

#endif // DATABASEMANAGEMENT_H
