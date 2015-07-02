#include "DataBaseManagement.h"


DataBaseManagement* DataBaseManagement::instance=0;

DataBaseManagement* DataBaseManagement::initialize(){
    if(!instance){
        instance=new DataBaseManagement();
    }
    return instance;
}

DataBaseManagement::DataBaseManagement(){
    qSqlDataBase= QSqlDatabase::addDatabase(TYPE_DRIVER);
    qSqlDataBase.setDatabaseName(NAME_DATABASE);
}

bool DataBaseManagement::open(){
    qSqlQuery=new QSqlQuery(qSqlDataBase);
    if (qSqlDataBase.open()){
        qDebug() <<"info: se abrio la coneccion a la base de datos";
        return true;
    }
    qDebug() <<qSqlDataBase.lastError();
    return false;
}

bool DataBaseManagement::execute(QString _instruction){
    qSqlQuery=new QSqlQuery(qSqlDataBase);
    if(qSqlQuery->exec(_instruction)){
        qDebug() <<"info: se ejecuto la instruccion "<<_instruction;
        return true;
    }
    qDebug() <<"error: no se ejecuto la instruccion "<<_instruction;
    return false;
}

QSqlQuery* DataBaseManagement::getQuery(QString _query){
    qSqlQuery=new QSqlQuery(qSqlDataBase);
    qSqlQuery->exec(_query);
    if(qSqlQuery->isSelect()){
        qDebug() <<"info: se consulto la instruccion "<<_query;
    }else{
        qDebug() <<"error: no se consulto la instruccion "<<_query;
    }   
    return qSqlQuery;
}

bool::DataBaseManagement::close(){
    qSqlQuery->clear();
    delete qSqlQuery;
    qSqlQuery=0;
    qSqlDataBase.close();
    qDebug() <<"info: se cerro la coneccion a la base de datos";
}
