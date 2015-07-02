#include "User.h"

User::User()
{
    this->id=0;
    this->name="";
    this->password="";
    this->permission=0;
}

User::User(const User& orig) {
}

User::~User() {
}

void User::setPassword(QString clave) {
    this->password = clave;
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

Permission* User::getPermission() const{
    return permission;
}

void User::setPermission(Permission * _permission){
    this->permission=_permission;
}
