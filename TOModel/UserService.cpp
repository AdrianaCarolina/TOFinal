#include "UserService.h"


UserService::UserService() {

}

UserService::UserService(const UserService& orig) {
}

UserService::~UserService() {
}

void UserService::addUser(User* _user){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("INSERT INTO usuario (id_usuario,nombre,clave,acceso) VALUES ("
                                 +QString::number(_user->getId())+","
                                 +"'"+_user->getName()+"'"+","
                                 +"'"+_user->getPassword()+"'"+","
                                 +QString::number(_user->getAccess())+")");
    DATABASE_MANAGEMENT->close();
}

void UserService::deleteUser(int _id){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("DELETE FROM usuario WHERE id_usuario="+QString::number(_id));
    DATABASE_MANAGEMENT->close();
}

void UserService::updateUser(User * _user){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("UPDATE usuario SET id_usuario="+QString::number(_user->getId())+","
                                 +" nombre='"+_user->getName()+"'"+", "
                                 +" clave='"+_user->getPassword()+"'"+", "
                                 +" acceso="+QString::number(_user->getAccess())+" "
                                 +"WHERE id_usuario="+QString::number(_user->getId()));
    DATABASE_MANAGEMENT->close();
}

QList<User*> UserService::findUser(){
    DATABASE_MANAGEMENT->open();
    QSqlQuery* _qSqlQuery=DATABASE_MANAGEMENT->getQuery("SELECT * FROM usuario");
    QList<User*> _qList;
    while(_qSqlQuery->next()){
        User* _user=new User();
        _user->setId(_qSqlQuery->value("id_usuario").toInt());
        _user->setName(_qSqlQuery->value("nombre").toString());
        _user->setPassword(_qSqlQuery->value("clave").toString());
        _user->setAccess(_qSqlQuery->value("acceso").toInt());
        _qList.append(_user);
    }
    DATABASE_MANAGEMENT->close();
    return _qList;
}

QList<User*> UserService::findUser(int _id){
    DATABASE_MANAGEMENT->open();
    QSqlQuery* _qSqlQuery=DATABASE_MANAGEMENT->getQuery("SELECT * FROM usuario WHERE id_usuario="+QString::number(_id));
    QList<User*> _qList;
    while(_qSqlQuery->next()){
        User* _user=new User();
        _user->setId(_qSqlQuery->value("id_usuario").toInt());
        _user->setName(_qSqlQuery->value("nombre").toString());
        _user->setPassword(_qSqlQuery->value("clave").toString());
        _user->setAccess(_qSqlQuery->value("acceso").toInt());
        _qList.append(_user);
    }
    DATABASE_MANAGEMENT->close();
    return _qList;
}
