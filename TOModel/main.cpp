#include <QCoreApplication>

#include "CinemaService.h"

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
    return a.exec();
}
