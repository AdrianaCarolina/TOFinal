/* 
 * File:   CinemaService.h
 * Author: root
 *
 * Created on June 20, 2015, 3:12 PM
 */

#ifndef CINEMASERVICE_H
#define	CINEMASERVICE_H

#include "Cinema.h"
#include "databasemanagement.h"
#include <iostream>
#include <sstream>

using namespace std;

class CinemaService {
public:
    void addCinema(Cinema*);
    void updateCinema(Cinema*);
    void deleteCinema(int);
    QList<Cinema*> findCinema();
    QList<Cinema*> findCinema(int);
    CinemaService();
    CinemaService(const CinemaService& orig);
    virtual ~CinemaService();
private:
    DataBaseManagement* DATABASE_MANAGEMENT=new DataBaseManagement();
};

#endif	/* CINEMASERVICE_H */

