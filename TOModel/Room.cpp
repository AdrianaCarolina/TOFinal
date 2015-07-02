/* 
 * File:   Room.cpp
 * Author: root
 * 
 * Created on June 20, 2015, 1:25 PM
 */

#include "Room.h"

Room::Room() {
}

Room::Room(const Room& orig) {
}

Room::~Room() {
}

void Room::setTypeRoom(int typeRoom) {
    this->typeRoom = typeRoom;
}

int Room::getTypeRoom() const {
    return typeRoom;
}

void Room::setNumberOfSeats(int numberOfSeats) {
    this->numberOfSeats = numberOfSeats;
}

int Room::getNumberOfSeats() const {
    return numberOfSeats;
}

void Room::setIdCinema(int idCinema) {
    this->idCinema = idCinema;
}

int Room::getIdCinema() const {
    return idCinema;
}

void Room::setId(int id) {
    this->id = id;
}

int Room::getId() const {
    return id;
}

