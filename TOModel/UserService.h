#ifndef USUARIOSERVICE_H
#define USUARIOSERVICE_H

#include "User.h"
#include "DataBaseManagement.h"

class UserService {
public:
    void addUser(User*);
    void updateUser(User*);
    void deleteUser(int);
    QList<User*> findUser();
    QList<User*> findUser(int);
    UserService();
    UserService(const UserService& orig);
    virtual ~UserService();
private:
    DataBaseManagement* DATABASE_MANAGEMENT=DataBaseManagement::initialize();
};


#endif // USUARIOSERVICE_H

