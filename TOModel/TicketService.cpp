#include "TicketService.h"

TicketService::TicketService() {

}

TicketService::TicketService(const TicketService& orig) {
}

TicketService::~TicketService() {
}

void TicketService::addTicket(Ticket* _ticket){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("INSERT INTO entrada (id_entrada,id_usuario,horario,precio_entrada) VALUES ("
                                 +QString::number(_ticket->getId())+","
                                 +QString::number(_ticket->getUser()->getId())+","
                                 +"'"+_ticket->getSchedule()+"'"+","
                                 +QString::number(_ticket->getPrice())+")");
    DATABASE_MANAGEMENT->close();
}

void TicketService::deleteTicket(int _id){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("DELETE FROM entrada WHERE id_entrada="+QString::number(_id));
    DATABASE_MANAGEMENT->close();
}

void TicketService::updateTicket(Ticket * _ticket){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("UPDATE entrada SET id_entrada="+QString::number(_ticket->getId())+","
                                 +" id_usuario='"+QString::number(_ticket->getUser()->getId())+"'"+", "
                                 +" horario='"+_ticket->getSchedule()+"'"+", "
                                 +" precio_entrada="+QString::number(_ticket->getPrice())+" "
                                 +"WHERE id_entrada="+QString::number(_ticket->getId()));
    DATABASE_MANAGEMENT->close();
}

QList<Ticket*> TicketService::findTicket(){
    DATABASE_MANAGEMENT->open();
    QSqlQuery* _qSqlQuery=DATABASE_MANAGEMENT->getQuery("SELECT * FROM entrada INNER JOIN usuario ON entrada.id_entrada=usuario.id_usuario");
    QList<Ticket*> _qList;
    while(_qSqlQuery->next()){
        Ticket* _ticket=new Ticket();
        _ticket->setId(_qSqlQuery->value("id_entrada").toInt());
        User* _user=new User();
        _user->setId(_qSqlQuery->value("id_usuario").toInt());
        _user->setName(_qSqlQuery->value("nombre").toString());
        _ticket->setUser(_user);
        _ticket->setPrice(_qSqlQuery->value("precio_entrada").toFloat());
        _ticket->setSchedule(_qSqlQuery->value("horario").toString());
        _qList.append(_ticket);
    }
    DATABASE_MANAGEMENT->close();
    return _qList;
}

QList<Ticket*> TicketService::findTicket(int _id){
    DATABASE_MANAGEMENT->open();
    QSqlQuery* _qSqlQuery=DATABASE_MANAGEMENT->getQuery("SELECT * FROM entrada INNER JOIN usuario ON entrada.id_entrada=usuario.id_usuario WHERE id_entrada="+QString::number(_id));
    QList<Ticket*> _qList;
    while(_qSqlQuery->next()){
        Ticket* _ticket=new Ticket();
        _ticket->setId(_qSqlQuery->value("id_entrada").toInt());
        User* _user=new User();
        _user->setId(_qSqlQuery->value("id_usuario").toInt());
        _user->setName(_qSqlQuery->value("nombre").toString());
        _ticket->setUser(_user);
        _ticket->setPrice(_qSqlQuery->value("precio_entrada").toFloat());
        _ticket->setSchedule(_qSqlQuery->value("horario").toString());
        _qList.append(_ticket);
    }
    DATABASE_MANAGEMENT->close();
    return _qList;
}
