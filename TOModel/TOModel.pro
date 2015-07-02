#-------------------------------------------------
#
# Project created by QtCreator 2015-07-02T08:36:39
#
#-------------------------------------------------

QT       += core sql

QT       -= gui

TARGET = TOModel
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Cinema.cpp \
    CinemaService.cpp \
    databasemanagement.cpp \
    Movie.cpp \
    Room.cpp \
    Schedule.cpp \
    usuario.cpp

HEADERS += \
    Cinema.h \
    CinemaService.h \
    databasemanagement.h \
    Movie.h \
    Room.h \
    Schedule.h \
    usuario.h
