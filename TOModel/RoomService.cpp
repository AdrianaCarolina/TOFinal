#include "RoomService.h"

RoomService::RoomService()
{

}

RoomService::RoomService(const RoomService& orig) {
}

RoomService::~RoomService() {
}

void RoomService::addRoom(Room* _room){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("INSERT INTO sala (id_sala,id_cine,horarios,numasientos,tiposala) VALUES ("
                                 +QString::number(_room->getId())+","
                                 +QString::number(_room->getCinema()->getId())+","
                                 +"'"+_room->getSchedule()+"',"
                                 +QString::number(_room->getNumberOfSeats())+","
                                 +QString::number(_room->getTypeRoom())+")");
    DATABASE_MANAGEMENT->close();
}

void RoomService::deleteRoom(int _id){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("DELETE FROM sala WHERE id_sala="+QString::number(_id));
    DATABASE_MANAGEMENT->close();
}

void RoomService::updateRoom(Room * _room){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("UPDATE sala SET id_sala="+QString::number(_room->getId())+","
                                 +" id_cine="+QString::number(_room->getCinema()->getId())+", "
                                 +" horarios='"+_room->getSchedule()+"'"+", "
                                 +" numasientos="+QString::number(_room->getNumberOfSeats())+", "
                                 +" tiposala="+QString::number(_room->getTypeRoom())+" "
                                 +"WHERE id_sala="+QString::number(_room->getId()));
    DATABASE_MANAGEMENT->close();
}

QList<Room*> RoomService::findRoom(){
    DATABASE_MANAGEMENT->open();
    QSqlQuery* _qSqlQuery=DATABASE_MANAGEMENT->getQuery("SELECT * FROM sala INNER JOIN cine ON sala.id_cine=cine.id_cine");
    QList<Room*> _qList;
    while(_qSqlQuery->next()){
        Room* _room=new Room();
        _room->setId(_qSqlQuery->value("id_usuario").toInt());
        Cinema* _cinema=new Cinema();
        _cinema->setId(_qSqlQuery->value("id_cine").toInt());
        _cinema->setName(_qSqlQuery->value("nombre_cine").toString());
        _cinema->setName(_qSqlQuery->value("ubicacion_cine").toString());
        _room->setCinema(_cinema);
        _room->setNumberOfSeats(_qSqlQuery->value("numasientos").toInt());
        _room->setSchedule(_qSqlQuery->value("horarios").toString());
        _room->setTypeRoom(_qSqlQuery->value("tiposala").toInt());
        _qList.append(_room);
    }
    DATABASE_MANAGEMENT->close();
    return _qList;
}

QList<Room*> RoomService::findRoom(int _id){
    DATABASE_MANAGEMENT->open();
    QSqlQuery* _qSqlQuery=DATABASE_MANAGEMENT->getQuery("SELECT * FROM sala INNER JOIN cine ON sala.id_cine=cine.id_cine WHERE id_sala="+QString::number(_id));
    QList<Room*> _qList;
    while(_qSqlQuery->next()){
        Room* _room=new Room();
        _room->setId(_qSqlQuery->value("id_usuario").toInt());
        Cinema* _cinema=new Cinema();
        _cinema->setId(_qSqlQuery->value("id_cine").toInt());
        _cinema->setName(_qSqlQuery->value("nombre_cine").toString());
        _cinema->setName(_qSqlQuery->value("ubicacion_cine").toString());
        _room->setCinema(_cinema);
        _room->setNumberOfSeats(_qSqlQuery->value("numasientos").toInt());
        _room->setSchedule(_qSqlQuery->value("horarios").toString());
        _room->setTypeRoom(_qSqlQuery->value("tiposala").toInt());
        _qList.append(_room);
    }
    DATABASE_MANAGEMENT->close();
    return _qList;
}
