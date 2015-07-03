/* 
 * File:   Schedule.h
 * Author: root
 *
 * Created on June 20, 2015, 1:25 PM
 */

#ifndef SCHEDULE_H
#define	SCHEDULE_H

#include <time.h>
#include "Movie.h"
#include "Ticket.h"
#include "Room.h"

class Schedule {
public:
    Schedule();
    Schedule(const Schedule& orig);
    virtual ~Schedule();
    void setEndTime(QString );
    QString getEndTime() const;
    void setStartTime(QString );
    QString getStartTime() const;
    void setRoom(Room* );
    Room* getRoom() const;
    void setTicket(Ticket* );
    Ticket* getTicket() const;
    void setMovie(Movie* );
    Movie* getMovie() const;
    void setId(int);
    int getId() const;
private:
    int id;
    Movie* movie;
    Ticket* ticket;
    Room* room;
    QString startTime;
    QString endTime;
};

#endif	/* SCHEDULE_H */

