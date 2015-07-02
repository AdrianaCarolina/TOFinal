#include <QCoreApplication>

#include "CinemaService.h"
#include "UserService.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CinemaService* _cs=new CinemaService();
    Cinema* _cinema=new Cinema();
    _cinema->setId(10);
    _cinema->setName("cine azul");
    _cinema->setLocation("arequipa cercado");
    //_cs->addCinema(_cinema);
    _cs->updateCinema(_cinema);

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

    UserService* _us=new UserService();
    User* _user=new User();
    _user->setId(1);
    _user->setName("juan");
    _user->setPassword("1234567");
    _user->setAccess(1);
    //_us->addUser(_user);
    _us->updateUser(_user);

    QList<User*> _qlistUser;
    _qlistUser=    _us->findUser();
    QListIterator<User*> itUser(_qlistUser);
    while (itUser.hasNext()) {
        qDebug()<<itUser.next()->getName();
    }
    _us->deleteUser(2);
     qDebug()<<"-----";
    _qlistUser=    _us->findUser();
    QListIterator<User*> itUser2(_qlistUser);
    while (itUser2.hasNext()) {
        qDebug()<<itUser2.next()->getName();
    }


    return a.exec();
}
