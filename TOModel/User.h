#ifndef USUARIO_H
#define USUARIO_H

#include <QString>
#include "Permission.h"

class User {
public:
    User();
    User(const User& orig);
    virtual ~User();
    void setPassword(QString );
    QString getPassword() const;
    void setName(QString );
    QString getName() const;
    void setId(int );
    int getId() const;
    void setPermission(Permission* );
    Permission* getPermission() const;
private:
    int id;
    QString name;
    QString password;
    Permission* permission;
};

#endif // USUARIO_H
