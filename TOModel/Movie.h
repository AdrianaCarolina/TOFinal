/* 
 * File:   Movie.h
 * Author: root
 *
 * Created on June 20, 2015, 1:25 PM
 */

#ifndef MOVIE_H
#define	MOVIE_H

#include <QString>

using namespace std;

class Movie {
public:
    Movie();
    Movie(const Movie& orig);
    virtual ~Movie();
    void setTicketOffice(int ticketOffice);
    int getTicketOffice() const;
    void setDuration(int duration);
    int getDuration() const;
    void setClassification(QString classification);
    QString getClassification() const;
    void setTitle(QString title);
    QString getTitle() const;
    void setId(int id);
    int getId() const;
private:
    int id;
    QString title;
    QString classification;
    int duration;
    int ticketOffice;
};

#endif	/* MOVIE_H */

