#include "MovieService.h"

MovieService::MovieService() {
}

MovieService::MovieService(const MovieService& orig) {
}

MovieService::~MovieService() {
}

void MovieService::addMovie(Movie* _movie){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("INSERT INTO pelicula (id_pelicula,titulo,clasificacion,duracion,taquilla) VALUES ("
                                 +QString::number(_movie->getId())+","
                                 +"'"+_movie->getTitle()+"'"+","
                                 +"'"+_movie->getClassification()+"'"+","
                                 +QString::number(_movie->getDuration())+","
                                 +QString::number(_movie->getTicketOffice())+")");
    DATABASE_MANAGEMENT->close();
}

void MovieService::deleteMovie(int _id){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("DELETE FROM pelicula WHERE id_pelicula="+QString::number(_id));
    DATABASE_MANAGEMENT->close();
}

void MovieService::updateMovie(Movie * _movie){
    DATABASE_MANAGEMENT->open();
    DATABASE_MANAGEMENT->execute("UPDATE pelicula SET id_pelicula="+QString::number(_movie->getId())+","
                                 +"titulo='"+_movie->getTitle()+"'"+","
                                 +"clasificacion='"+_movie->getClassification()+"',"
                                 +"duracion='"+QString::number(_movie->getDuration())+"',"
                                 +"taquilla='"+QString::number(_movie->getTicketOffice())+"'"
                                 +"WHERE id_pelicula="+QString::number(_movie->getId()));
    DATABASE_MANAGEMENT->close();
}

QList<Movie*> MovieService::findMovie(){
    DATABASE_MANAGEMENT->open();
    QSqlQuery* _qSqlQuery=DATABASE_MANAGEMENT->getQuery("SELECT * FROM pelicula");
    QList<Movie*> _qList;
    while(_qSqlQuery->next()){
        Movie* _movie=new Movie();
        _movie->setId(_qSqlQuery->value("id_pelicula").toInt());
        _movie->setTitle(_qSqlQuery->value("titulo").toString());
        _movie->setClassification(_qSqlQuery->value("clasificacion").toString());
        _movie->setDuration(_qSqlQuery->value("duracion").toInt());
        _movie->setTicketOffice(_qSqlQuery->value("taquilla").toInt());
        _qList.append(_movie);
    }
    DATABASE_MANAGEMENT->close();
    return _qList;
}

QList<Movie*> MovieService::findMovie(int _id){
    DATABASE_MANAGEMENT->open();
    QSqlQuery* _qSqlQuery=DATABASE_MANAGEMENT->getQuery("SELECT * FROM pelicula WHERE id_pelicula="+QString::number(_id));
    QList<Movie*> _qList;
    while(_qSqlQuery->next()){
        Movie* _movie=new Movie();
        _movie->setId(_qSqlQuery->value("id_pelicula").toInt());
        _movie->setTitle(_qSqlQuery->value("titulo").toString());
        _movie->setClassification(_qSqlQuery->value("clasificacion").toString());
        _movie->setDuration(_qSqlQuery->value("duracion").toInt());
        _movie->setTicketOffice(_qSqlQuery->value("taquilla").toInt());
        _qList.append(_movie);
    }
    DATABASE_MANAGEMENT->close();
    return _qList;
}

