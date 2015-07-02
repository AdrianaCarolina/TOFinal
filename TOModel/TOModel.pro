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
    Movie.cpp \
    Room.cpp \
    Schedule.cpp \
    DataBaseManagement.cpp \
    User.cpp \
    UserService.cpp \
    Permission.cpp \
    PermissionService.cpp \
    RoomService.cpp

HEADERS += \
    Cinema.h \
    CinemaService.h \
    Movie.h \
    Room.h \
    Schedule.h \
    DataBaseManagement.h \
    User.h \
    UserService.h \
    Permission.h \
    PermissionService.h \
    RoomService.h
