/* 
 * File:   Schedule.cpp
 * Author: root
 * 
 * Created on June 20, 2015, 1:25 PM
 */

#include "Schedule.h"

Schedule::Schedule() {
    this->id=0;
    this->room=0;
    this->ticket=0;
    this->movie=0;
    this->startTime="";
    this->endTime="";
}

Schedule::Schedule(const Schedule& orig) {
}

Schedule::~Schedule() {
}

void Schedule::setEndTime(QString endTime) {
    this->endTime = endTime;
}

QString Schedule::getEndTime() const {
    return endTime;
}

void Schedule::setStartTime(QString startTime) {
    this->startTime = startTime;
}

QString Schedule::getStartTime() const {
    return startTime;
}

void Schedule::setRoom(Room* room) {
    this->room = room;
}

Room* Schedule::getRoom() const {
    return room;
}

void Schedule::setTicket(Ticket* ticket) {
    this->ticket = ticket;
}

Ticket* Schedule::getTicket() const {
    return ticket;
}

void Schedule::setMovie(Movie* movie) {
    this->movie = movie;
}

Movie* Schedule::getMovie() const {
    return movie;
}

void Schedule::setId(int id) {
    this->id = id;
}

int Schedule::getId() const {
    return id;
}

