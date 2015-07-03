#include "Ticket.h"

Ticket::Ticket()
{
    this->id=0;
    this->price=0.0f;
    this->schedule="";
    this->user=0;
}

Ticket::Ticket(const Ticket& orig) {
}

Ticket::~Ticket() {
}

int Ticket::getId() const{
    return id;
}

void Ticket::setId(int _id){
    this->id=_id;
}

float Ticket::getPrice()const {
    return price;
}

void Ticket::setPrice(float _price){
    this->price=_price;
}

QString Ticket::getSchedule()const {
    return schedule;
}

void Ticket::setSchedule(QString _schedule){
    this->schedule=_schedule;
}

User* Ticket::getUser()const {
    return user;
}

void Ticket::setUser(User* _user){
    this->user=_user;
}
