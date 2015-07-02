#ifndef USUARIO_H
#define USUARIO_H

#include <QString>

class Usuario {
public:
    Usuario();
    Usuario(const Usuario& orig);
    virtual ~Usuario();
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
