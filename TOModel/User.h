#ifndef USUARIO_H
#define USUARIO_H

#include <QString>

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
    void setAccess(int );
    int getAccess() const;
private:
    int id;
    QString name;
    QString password;
    int access;
};

#endif // USUARIO_H
