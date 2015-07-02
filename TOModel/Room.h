#ifndef ROOM_H
#define ROOM_H

#include <QString>

#include "Cinema.h"

class Room {
public:
    Room();
    Room(const Room& orig);
    virtual ~Room();
    void setTypeRoom(int);
    int getTypeRoom() const;
    void setNumberOfSeats(int );
    int getNumberOfSeats() const;
    void setCinema(Cinema*);
    Cinema* getCinema() const;
    void setId(int id);
    int getId() const;
    void setSchedule(QString);
    QString getSchedule() const;
private:
    int id;
    Cinema* cinema;
    int numberOfSeats;
    int typeRoom;
    QString schedule;
};

#endif	/* ROOM_H */
