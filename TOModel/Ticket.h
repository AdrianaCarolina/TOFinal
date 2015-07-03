#ifndef TICKET_H
#define TICKET_H

#include <QString>

#include "User.h"

class Ticket{
public:
    Ticket();
    Ticket(const Ticket& orig);
    virtual ~Ticket();
    int getId() const;
    void setId(int);

    User* getUser() const;
    void setUser(User*);

    QString getSchedule() const;
    void setSchedule(QString );

    float getPrice() const;
    void setPrice(float);
private:
    int id;
    User* user;
    QString schedule;
    float price;
};

#endif // TICKET_H
