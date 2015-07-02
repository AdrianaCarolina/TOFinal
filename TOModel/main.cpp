#include <QCoreApplication>

#include "CinemaService.h"
#include "UserService.h"
#include "PermissionService.h"
#include "RoomService.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CinemaService* _cs=new CinemaService();
    Cinema* _cinema=new Cinema();
    _cinema->setId(10);
    _cinema->setName("cine azul");
    _cinema->setLocation("arequipa cercado");
    _cs->addCinema(_cinema);
    //_cs->updateCinema(_cinema);

    RoomService* _rs=new RoomService();
    Room* _room=new Room();
    _room->setId(1);
    _room->setCinema(_cinema);
    _room->setNumberOfSeats(60);
    _room->setSchedule("LMMJVS");
    _room->setTypeRoom(1);
    _rs->updateRoom(_room);
    //_rs->addRoom(_room);

    QList<Room*> _qlistRoom;
    _qlistRoom=    _rs->findRoom();
    QListIterator<Room*> itRoom(_qlistRoom);
    while (itRoom.hasNext()) {
        qDebug()<<itRoom.next()->getSchedule();
    }
    _rs->deleteRoom(2);


    QList<Cinema*> _qlist;
    _qlist=    _cs->findCinema();
    QListIterator<Cinema*> it(_qlist);
    while (it.hasNext()) {
        qDebug()<<it.next()->getName();
    }
    _cs->deleteCinema(2);
     qDebug()<<"-----";
    _qlist=    _cs->findCinema();
    QListIterator<Cinema*> it2(_qlist);
    while (it2.hasNext()) {
        qDebug()<<it2.next()->getName();
    }


    PermissionService* _ps=new PermissionService();
    Permission* _Permission=new Permission();
    _Permission->setId(2);
    _Permission->setCharge("usuario");
    _ps->addPermission(_Permission);
    //_ps->updatePermission(_Permission);

    UserService* _us=new UserService();
    User* _user=new User();
    _user->setId(2);
    _user->setName("juan");
    _user->setPassword("1234567");
    _user->setPermission(_Permission);
    _us->addUser(_user);
    //_us->updateUser(_user);

    QList<User*> _qlistUser;
    _qlistUser=    _us->findUser();
    QListIterator<User*> itUser(_qlistUser);
    while (itUser.hasNext()) {
        qDebug()<<itUser.next()->getPassword();
    }
    _us->deleteUser(2);
     qDebug()<<"-----";
    _qlistUser=    _us->findUser();
    QListIterator<User*> itUser2(_qlistUser);
    while (itUser2.hasNext()) {
        qDebug()<<itUser2.next()->getName();
    }



    QList<Permission*> _qlistPermission;
    _qlistPermission=    _ps->findPermission();
    QListIterator<Permission*> itPermission(_qlistPermission);
    while (itPermission.hasNext()) {
        qDebug()<<itPermission.next()->getCharge();
    }
    _ps->deletePermission(2);
     qDebug()<<"-----";
    _qlistPermission=    _ps->findPermission();
    QListIterator<Permission*> itPermission2(_qlistPermission);
    while (itPermission2.hasNext()) {
        qDebug()<<itPermission2.next()->getCharge();
    }


    return a.exec();
}
