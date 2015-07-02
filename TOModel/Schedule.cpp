/* 
 * File:   Schedule.cpp
 * Author: root
 * 
 * Created on June 20, 2015, 1:25 PM
 */

#include "Schedule.h"

Schedule::Schedule() {
}

Schedule::Schedule(const Schedule& orig) {
}

Schedule::~Schedule() {
}

void Schedule::setEndTime(time_t endTime) {
    this->endTime = endTime;
}

time_t Schedule::getEndTime() const {
    return endTime;
}

void Schedule::setStartTime(time_t startTime) {
    this->startTime = startTime;
}

time_t Schedule::getStartTime() const {
    return startTime;
}

void Schedule::setIdRoom(int idRoom) {
    this->idRoom = idRoom;
}

int Schedule::getIdRoom() const {
    return idRoom;
}

void Schedule::setIdTicket(int idTicket) {
    this->idTicket = idTicket;
}

int Schedule::getIdTicket() const {
    return idTicket;
}

void Schedule::setIdMovie(int idMovie) {
    this->idMovie = idMovie;
}

int Schedule::getIdMovie() const {
    return idMovie;
}

void Schedule::SetId(int id) {
    this->id = id;
}

int Schedule::GetId() const {
    return id;
}

