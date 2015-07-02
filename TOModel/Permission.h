#ifndef PERMISSION_H
#define PERMISSION_H

#include <QString>

class Permission
{
public:
    Permission();
    Permission(const Permission& orig);
    virtual ~Permission();
    void setCharge(QString );
    QString getCharge() const;
    void setId(int );
    int getId() const;
private:
    int id; //access
    QString charge;
};

#endif // PERMISSION_H
