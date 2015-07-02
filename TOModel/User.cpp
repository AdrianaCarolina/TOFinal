#include "User.h"

User::User()
{
    this->id=0;
    this->name="";
    this->password="";
    this->access=0;
}

User::User(const User& orig) {
}

User::~User() {
}

void User::setPassword(QString clave) {
    this->password = password;
}

QString User::getPassword() const {
    return password;
}

void User::setName(QString name) {
    this->name = name;
}

QString User::getName() const {
    return name;
}

void User::setId(int id) {
    this->id = id;
}

int User::getId() const {
    return id;
}

void User::setAccess(int access) {
    this->access = access;
}

int User::getAccess() const {
    return access;
}
