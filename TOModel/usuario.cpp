#include "usuario.h"

Usuario::Usuario()
{
    this->id=0;
    this->name="";
    this->password="";
    this->access=0;
}

Usuario::Usuario(const Usuario& orig) {
}

Usuario::~Usuario() {
}

void Usuario::setPassword(QString clave) {
    this->password = password;
}

QString Usuario::getPassword() const {
    return password;
}

void Usuario::setName(QString name) {
    this->name = name;
}

QString Usuario::getName() const {
    return name;
}

void Usuario::setId(int id) {
    this->id = id;
}

int Usuario::getId() const {
    return id;
}

void Usuario::setAccess(int access) {
    this->access = access;
}

int Usuario::getAccess() const {
    return access;
}
