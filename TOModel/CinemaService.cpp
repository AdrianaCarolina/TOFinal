/*
 * File:   CinemaService.cpp
 * Author: root
 * 
 * Created on June 20, 2015, 3:12 PM
 */

#include "CinemaService.h"

CinemaService::CinemaService() {
}

CinemaService::CinemaService(const CinemaService& orig) {
}

CinemaService::~CinemaService() {
}

void CinemaService::addCinema(Cinema* _cinema){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("INSERT INTO cine (id_cine,nombre_cine,ubicacion_cine) VALUES ("
                                 +QString::number(_cinema->getId())+","
                                 +"'"+_cinema->getName()+"'"+","
                                 +"'"+_cinema->getLocation()+"'"+")");
    DATABASE_MANAGEMENT->close();
}

void CinemaService::deleteCinema(int _id){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("DELETE FROM cine WHERE id_cine="+QString::number(_id));
    DATABASE_MANAGEMENT->close();
}

void CinemaService::updateCinema(Cinema * _cinema){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("UPDATE cine SET id_cine="+QString::number(_cinema->getId())+","
                                 +"nombre_cine='"+_cinema->getName()+"'"+","
                                 +"ubicacion_cine='"+_cinema->getLocation()+"'"
                                 +"WHERE id_cine="+QString::number(_cinema->getId()));
    DATABASE_MANAGEMENT->close();
}

QList<Cinema*> CinemaService::findCinema(){
    DATABASE_MANAGEMENT->open();
    QSqlQuery* _qSqlQuery=DATABASE_MANAGEMENT->getQuery("SELECT * FROM cine");
    QList<Cinema*> _qList;
    while(_qSqlQuery->next()){
        Cinema* _cinema=new Cinema();
        _cinema->setId(_qSqlQuery->value("id_cine").toInt());
        _cinema->setName(_qSqlQuery->value("nombre_cine").toString());
        _cinema->setLocation(_qSqlQuery->value("ubicacion_cine").toString());
        _qList.append(_cinema);
    }
    DATABASE_MANAGEMENT->close();
    return _qList;
}

QList<Cinema*> CinemaService::findCinema(int _id){
    DATABASE_MANAGEMENT->open();
    QSqlQuery* _qSqlQuery=DATABASE_MANAGEMENT->getQuery("SELECT * FROM cine WHERE id_cine="+QString::number(_id));
    QList<Cinema*> _qList;
    while(_qSqlQuery->next()){
        Cinema* _cinema=new Cinema();
        _cinema->setId(_qSqlQuery->value("id_cine").toInt());
        _cinema->setName(_qSqlQuery->value("nombre_cine").toString());
        _cinema->setLocation(_qSqlQuery->value("ubicacion_cine").toString());
        _qList.append(_cinema);
    }
    DATABASE_MANAGEMENT->close();
    return _qList;
}
