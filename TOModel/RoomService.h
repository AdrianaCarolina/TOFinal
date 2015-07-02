#ifndef ROOMSERVICE_H
#define ROOMSERVICE_H

#include "Room.h"
#include "DataBaseManagement.h"

class RoomService {
public:
    void addRoom(Room*);
    void updateRoom(Room*);
    void deleteRoom(int);
    QList<Room*> findRoom();
    QList<Room*> findRoom(int);
    RoomService();
    RoomService(const RoomService& orig);
    virtual ~RoomService();
private:
    DataBaseManagement* DATABASE_MANAGEMENT=DataBaseManagement::initialize();
};


#endif // ROOMSERVICE_H
