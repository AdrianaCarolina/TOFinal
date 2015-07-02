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

void Room::setId(int _id) {
    this->id= _id;
}

int Room::getId() const {
    return id;
}

Cinema* Room::getCinema() const {
    return cinema;
}

void Room::setCinema(Cinema* _cinema) {
    this->cinema = _cinema;
}

QString Room::getSchedule() const{
    return schedule;
}

void Room::setSchedule(QString _schedule){
    this->schedule=_schedule;
}

