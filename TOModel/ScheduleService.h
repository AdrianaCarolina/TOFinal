#ifndef SCHEDULESERVICE_H
#define SCHEDULESERVICE_H

#include "Schedule.h"
#include "DataBaseManagement.h"

class ScheduleService {
public:
    void addSchedule(Schedule*);
    void updateSchedule(Schedule*);
    void deleteSchedule(int);
    QList<Schedule*> findSchedule();
    QList<Schedule*> findSchedule(int);
    ScheduleService();
    ScheduleService(const ScheduleService& orig);
    virtual ~ScheduleService();
private:
    DataBaseManagement* DATABASE_MANAGEMENT=DataBaseManagement::initialize();
};


#endif // SCHEDULESERVICE_H
