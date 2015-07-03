#ifndef TICKETSERVICE_H
#define TICKETSERVICE_H

#include "Ticket.h"
#include "DataBaseManagement.h"

class TicketService {
public:
    void addTicket(Ticket*);
    void updateTicket(Ticket*);
    void deleteTicket(int);
    QList<Ticket*> findTicket();
    QList<Ticket*> findTicket(int);
    TicketService();
    TicketService(const TicketService& orig);
    virtual ~TicketService();
private:
    DataBaseManagement* DATABASE_MANAGEMENT=DataBaseManagement::initialize();
};

#endif // TICKETSERVICE_H
