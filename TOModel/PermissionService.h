#ifndef PERMISSIONSERVICE_H
#define PERMISSIONSERVICE_H

#include "Permission.h"
#include "DataBaseManagement.h"

class PermissionService {
public:
    void addPermission(Permission*);
    void updatePermission(Permission*);
    void deletePermission(int);
    QList<Permission*> findPermission();
    QList<Permission*> findPermission(int);
    PermissionService();
    PermissionService(const PermissionService& orig);
    virtual ~PermissionService();
private:
    DataBaseManagement* DATABASE_MANAGEMENT=DataBaseManagement::initialize();
};


#endif // PERMISSIONSERVICE_H
