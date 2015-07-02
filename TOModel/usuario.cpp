#include "usuario.h"

Usuario::Usuario()
{
    this->id=0;
    this->name="";
    this->clave="";
    this->acceso=0;
}

Usuario::Usuario(const Usuario& orig) {
}

Usuario::~Usuario() {
}

void Usuario::setLocation(QString location) {
    this->location = location;
}

QString Usuario::getLocation() const {
    return location;
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
