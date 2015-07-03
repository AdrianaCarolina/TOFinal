#include <QCoreApplication>

#include "CinemaService.h"
#include "UserService.h"
#include "PermissionService.h"
#include "RoomService.h"
#include "MovieService.h"
#include "TicketService.h"
#include "ScheduleService.h"

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
    //_us->deleteUser(2);
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



    MovieService* _ms=new MovieService();
    Movie* _movie=new Movie();
    _movie->setId(2);
    _movie->setTitle("noe el trolaso - es o no es");
    _movie->setClassification("only hard");
    _movie->setDuration(69);
    _movie->setTicketOffice(20);
    _ms->addMovie(_movie);
    //_us->updateUser(_movie);

    QList<Movie*> _qlistMovie;
    _qlistMovie=    _ms->findMovie();
    QListIterator<Movie*> itMovie(_qlistMovie);
    while (itMovie.hasNext()) {
        qDebug()<<itMovie.next()->getTitle();
    }
    _ms->deleteMovie(2);
     qDebug()<<"-----";
    _qlistMovie=    _ms->findMovie(1);
    QListIterator<Movie*> itMovie2(_qlistMovie);
    while (itMovie2.hasNext()) {
        qDebug()<<itMovie2.next()->getTitle();
    }


    TicketService* _ts=new TicketService();
    Ticket* _ticket=new Ticket();
    _ticket->setId(1);
    _ticket->setUser(_user);
    _ticket->setPrice(25.0f);
    _ticket->setSchedule("LMV");
    //_ts->addTicket(_ticket);
    _ts->updateTicket(_ticket);

    QList<Ticket*> _qlistTicket;
    _qlistTicket=    _ts->findTicket();
    QListIterator<Ticket*> itTicket(_qlistTicket);
    while (itTicket.hasNext()) {
        qDebug()<<itTicket.next()->getPrice();
    }
    _ts->deleteTicket(2);
     qDebug()<<"-----";
    _qlistTicket=    _ts->findTicket(1);
    QListIterator<Ticket*> itTicket2(_qlistTicket);
    while (itTicket2.hasNext()) {
        qDebug()<<itTicket2.next()->getPrice();
    }


    ScheduleService* _ss=new ScheduleService();
    Schedule* _schedule=new Schedule();
    _schedule->setId(1);
    _schedule->setMovie(_movie);
    _schedule->setRoom(_room);
    _schedule->setTicket(_ticket);
    _schedule->setStartTime("3:00");
    _schedule->setEndTime("6:00");
    _ss->addSchedule(_schedule);
    //_ss->updateTicket(_ticket);

    QList<Schedule*> _qlistSchedule;
    _qlistSchedule=    _ss->findSchedule();
    QListIterator<Schedule*> itSchedule(_qlistSchedule);
    while (itSchedule.hasNext()) {
        qDebug()<<itSchedule.next()->getStartTime();
    }
    _ss->deleteSchedule(2);
     qDebug()<<"-----";
    _qlistSchedule=    _ss->findSchedule(1);
    QListIterator<Schedule*> itSchedule2(_qlistSchedule);
    while (itSchedule2.hasNext()) {
        qDebug()<<itSchedule2.next()->getStartTime();
    }


    return a.exec();
}
