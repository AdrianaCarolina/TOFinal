/* 
 * File:   Movie.cpp
 * Author: root
 * 
 * Created on June 20, 2015, 1:25 PM
 */

#include "Movie.h"

Movie::Movie() {
}

Movie::Movie(const Movie& orig) {
}

Movie::~Movie() {
}

void Movie::setTicketOffice(int ticketOffice) {
    this->ticketOffice = ticketOffice;
}

int Movie::getTicketOffice() const {
    return ticketOffice;
}

void Movie::setDuration(int duration) {
    this->duration = duration;
}

int Movie::getDuration() const {
    return duration;
}

void Movie::setClassification(QString classification) {
    this->classification = classification;
}

QString Movie::getClassification() const {
    return classification;
}

void Movie::setTitle(QString title) {
    this->title = title;
}

QString Movie::getTitle() const {
    return title;
}

void Movie::setId(int id) {
    this->id = id;
}

int Movie::getId() const {
    return id;
}

