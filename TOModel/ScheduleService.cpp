#include "ScheduleService.h"


ScheduleService::ScheduleService() {

}

ScheduleService::ScheduleService(const ScheduleService& orig) {
}

ScheduleService::~ScheduleService() {
}

void ScheduleService::addSchedule(Schedule* _schedule){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("INSERT INTO horario (id_horario,id_pelicula,id_entrada,id_sala,horario_inicio,horario_fin) VALUES ("
                                 +QString::number(_schedule->getId())+","
                                 +QString::number(_schedule->getMovie()->getId())+","
                                 +QString::number(_schedule->getTicket()->getId())+","
                                 +QString::number(_schedule->getRoom()->getId())+","
                                 +"'"+_schedule->getStartTime()+"'"+","
                                 +"'"+_schedule->getEndTime()+"'"+")");
    DATABASE_MANAGEMENT->close();
}

void ScheduleService::deleteSchedule(int _id){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("DELETE FROM horario WHERE id_horario="+QString::number(_id));
    DATABASE_MANAGEMENT->close();
}

void ScheduleService::updateSchedule(Schedule * _schedule){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("UPDATE horario SET id_horario="+QString::number(_schedule->getId())+","
                                 +" id_pelicula="+QString::number(_schedule->getMovie()->getId())+", "
                                 +" id_entrada="+QString::number(_schedule->getTicket()->getId())+", "
                                 +" id_sala="+QString::number(_schedule->getRoom()->getId())+", "
                                 +" horario_inicio='"+_schedule->getStartTime()+"'"+", "
                                 +" horario_fin='"+_schedule->getEndTime()+"'"+" "
                                 +"WHERE id_horario="+QString::number(_schedule->getId()));
    DATABASE_MANAGEMENT->close();
}

QList<Schedule*> ScheduleService::findSchedule(){
    DATABASE_MANAGEMENT->open();
    QSqlQuery* _qSqlQuery=DATABASE_MANAGEMENT->getQuery("SELECT * FROM horario INNER JOIN pelicula ON horario.id_pelicula=pelicula.id_pelicula INNER JOIN entrada ON horario.id_entrada=entrada.id_entrada INNER JOIN sala ON horario.id_sala=sala.id_sala INNER JOIN cine ON sala.id_cine=cine.id_cine");
    QList<Schedule*> _qList;
    while(_qSqlQuery->next()){
        Schedule* _schedule=new Schedule();
        _schedule->setId(_qSqlQuery->value("id_horario").toInt());
        Movie* _movie=new Movie();
        _movie->setId(_qSqlQuery->value("id_pelicula").toInt());
        _movie->setTitle(_qSqlQuery->value("titulo").toString());
        _movie->setClassification(_qSqlQuery->value("clasificacion").toString());
        _movie->setDuration(_qSqlQuery->value("duracion").toInt());
        _schedule->setMovie(_movie);
        Ticket* _ticket=new Ticket();
        _ticket->setId(_qSqlQuery->value("id_entrada").toInt());
        _ticket->setSchedule(_qSqlQuery->value("horario").toString());
        _ticket->setPrice(_qSqlQuery->value("precio_entrada").toFloat());
        _schedule->setTicket(_ticket);
        Room* _room=new Room();
        _room->setId(_qSqlQuery->value("id_sala").toInt());
        _room->setSchedule(_qSqlQuery->value("horarios").toString());
        _room->setTypeRoom(_qSqlQuery->value("tiposala").toInt());
        Cinema* _cinema=new Cinema();
        _cinema->setId(_qSqlQuery->value("id_cine").toInt());
        _cinema->setName(_qSqlQuery->value("nombre_cine").toString());
        _cinema->setLocation(_qSqlQuery->value("ubicacion_cine").toString());
        _room->setCinema(_cinema);
        _schedule->setRoom(_room);
        _qList.append(_schedule);
    }
    DATABASE_MANAGEMENT->close();
    return _qList;
}

QList<Schedule*> ScheduleService::findSchedule(int _id){
    DATABASE_MANAGEMENT->open();
    QSqlQuery* _qSqlQuery=DATABASE_MANAGEMENT->getQuery("SELECT * FROM horario INNER JOIN pelicula ON horario.id_pelicula=pelicula.id_pelicula INNER JOIN entrada ON horario.id_entrada=entrada.id_entrada INNER JOIN sala ON horario.id_sala=sala.id_sala INNER JOIN cine ON sala.id_cine=cine.id_cine WHERE id_horario="+QString::number(_id));
    QList<Schedule*> _qList;
    while(_qSqlQuery->next()){
        Schedule* _schedule=new Schedule();
        _schedule->setId(_qSqlQuery->value("id_horario").toInt());
        Movie* _movie=new Movie();
        _movie->setId(_qSqlQuery->value("id_pelicula").toInt());
        _movie->setTitle(_qSqlQuery->value("titulo").toString());
        _movie->setClassification(_qSqlQuery->value("clasificacion").toString());
        _movie->setDuration(_qSqlQuery->value("duracion").toInt());
        _schedule->setMovie(_movie);
        Ticket* _ticket=new Ticket();
        _ticket->setId(_qSqlQuery->value("id_entrada").toInt());
        _ticket->setSchedule(_qSqlQuery->value("horario").toString());
        _ticket->setPrice(_qSqlQuery->value("precio_entrada").toFloat());
        _schedule->setTicket(_ticket);
        Room* _room=new Room();
        _room->setId(_qSqlQuery->value("id_sala").toInt());
        _room->setSchedule(_qSqlQuery->value("horarios").toString());
        _room->setTypeRoom(_qSqlQuery->value("tiposala").toInt());
        Cinema* _cinema=new Cinema();
        _cinema->setId(_qSqlQuery->value("id_cine").toInt());
        _cinema->setName(_qSqlQuery->value("nombre_cine").toString());
        _cinema->setLocation(_qSqlQuery->value("ubicacion_cine").toString());
        _room->setCinema(_cinema);
        _schedule->setRoom(_room);
        _qList.append(_schedule);
    }
    DATABASE_MANAGEMENT->close();
    return _qList;
}
