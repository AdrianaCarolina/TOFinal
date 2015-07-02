#include "PermissionService.h"


PermissionService::PermissionService() {

}

PermissionService::PermissionService(const PermissionService& orig) {
}

PermissionService::~PermissionService() {
}

void PermissionService::addPermission(Permission* _permission){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("INSERT INTO permiso (acceso,cargo) VALUES ("
                                 +QString::number(_permission->getId())+","
                                 +"'"+_permission->getCharge()+"'"+")");
    DATABASE_MANAGEMENT->close();
}

void PermissionService::deletePermission(int _id){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("DELETE FROM permiso WHERE acceso="+QString::number(_id));
    DATABASE_MANAGEMENT->close();
}

void PermissionService::updatePermission(Permission * _permission){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("UPDATE permiso SET acceso="+QString::number(_permission->getId())+","
                                 +"cargo='"+_permission->getCharge()+"'"
                                 +"WHERE acceso="+QString::number(_permission->getId()));
    DATABASE_MANAGEMENT->close();
}

QList<Permission*> PermissionService::findPermission(){
    DATABASE_MANAGEMENT->open();
    QSqlQuery* _qSqlQuery=DATABASE_MANAGEMENT->getQuery("SELECT * FROM permiso");
    QList<Permission*> _qList;
    while(_qSqlQuery->next()){
        Permission* _permission=new Permission();
        _permission->setId(_qSqlQuery->value("acceso").toInt());
        _permission->setCharge(_qSqlQuery->value("cargo").toString());
        _qList.append(_permission);
    }
    DATABASE_MANAGEMENT->close();
    return _qList;
}

QList<Permission*> PermissionService::findPermission(int _id){
    DATABASE_MANAGEMENT->open();
    QSqlQuery* _qSqlQuery=DATABASE_MANAGEMENT->getQuery("SELECT * FROM permiso WHERE acceso="+QString::number(_id));
    QList<Permission*> _qList;
    while(_qSqlQuery->next()){
        Permission* _permission=new Permission();
        _permission->setId(_qSqlQuery->value("acceso").toInt());
        _permission->setCharge(_qSqlQuery->value("cargo").toString());
        _qList.append(_permission);
    }
    DATABASE_MANAGEMENT->close();
    return _qList;
}
