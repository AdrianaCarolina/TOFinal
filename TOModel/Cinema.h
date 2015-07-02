/* 
 * File:   Cinema.h
 * Author: root
 *
 * Created on June 20, 2015, 1:25 PM
 */

#ifndef CINEMA_H
#define	CINEMA_H

#include <QString>


class Cinema {
public:
    Cinema();
    Cinema(const Cinema& orig);
    virtual ~Cinema();
    void setLocation(QString location);
    QString getLocation() const;
    void setName(QString name);
    QString getName() const;
    void setId(int id);
    int getId() const;
private:
    int id;
    QString name;
    QString location;
};

#endif	/* CINEMA_H */

