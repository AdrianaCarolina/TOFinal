#include "Permission.h"

Permission::Permission()
{
    this->id=0;
    this->charge="";
}

Permission::~Permission(){
}

Permission::Permission(const Permission& orig) {
}

QString Permission::getCharge()const{
    return this->charge;
}

void Permission::setCharge(QString _charge){
    this->charge=_charge;
}

int Permission::getId()const{
    return this->id;
}

void Permission::setId(int _id){
    this->id=_id;
}
