#ifndef MOVIESERVICE_H
#define MOVIESERVICE_H


#include "Movie.h"
#include "DataBaseManagement.h"

class MovieService {
public:
    void addMovie(Movie*);
    void updateMovie(Movie*);
    void deleteMovie(int);
    QList<Movie*> findMovie();
    QList<Movie*> findMovie(int);
    MovieService();
    MovieService(const MovieService& orig);
    virtual ~MovieService();
private:
    DataBaseManagement* DATABASE_MANAGEMENT=DataBaseManagement::initialize();
};


#endif // MOVIESERVICE_H
