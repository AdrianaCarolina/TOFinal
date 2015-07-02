/* 
 * File:   Cinema.cpp
 * Author: root
 * 
 * Created on June 20, 2015, 1:25 PM
 */

#include "Cinema.h"

Cinema::Cinema() {
    this->id=0;
    this->location="";
    this->name="";
}

Cinema::Cinema(const Cinema& orig) {
}

Cinema::~Cinema() {
}

void Cinema::setLocation(QString location) {
    this->location = location;
}

QString Cinema::getLocation() const {
    return location;
}

void Cinema::setName(QString name) {
    this->name = name;
}

QString Cinema::getName() const {
    return name;
}

void Cinema::setId(int id) {
    this->id = id;
}

int Cinema::getId() const {
    return id;
}

