/* 
 * File:   Room.h
 * Author: root
 *
 * Created on June 20, 2015, 1:25 PM
 */

#ifndef ROOM_H
#define	ROOM_H

class Room {
public:
    Room();
    Room(const Room& orig);
    virtual ~Room();
    void setTypeRoom(int typeRoom);
    int getTypeRoom() const;
    void setNumberOfSeats(int numberOfSeats);
    int getNumberOfSeats() const;
    void setIdCinema(int idCinema);
    int getIdCinema() const;
    void setId(int id);
    int getId() const;
private:
    int id;
    int idCinema;
    int numberOfSeats;
    int typeRoom;
};

#endif	/* ROOM_H */

