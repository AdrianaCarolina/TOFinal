/* 
 * File:   Schedule.h
 * Author: root
 *
 * Created on June 20, 2015, 1:25 PM
 */

#ifndef SCHEDULE_H
#define	SCHEDULE_H

#include <time.h>

class Schedule {
public:
    Schedule();
    Schedule(const Schedule& orig);
    virtual ~Schedule();
    void setEndTime(time_t endTime);
    time_t getEndTime() const;
    void setStartTime(time_t startTime);
    time_t getStartTime() const;
    void setIdRoom(int idRoom);
    int getIdRoom() const;
    void setIdTicket(int idTicket);
    int getIdTicket() const;
    void setIdMovie(int idMovie);
    int getIdMovie() const;
    void SetId(int id);
    int GetId() const;
private:
    int id;
    int idMovie;
    int idTicket;
    int idRoom;
    time_t startTime;
    time_t endTime;
};

#endif	/* SCHEDULE_H */

