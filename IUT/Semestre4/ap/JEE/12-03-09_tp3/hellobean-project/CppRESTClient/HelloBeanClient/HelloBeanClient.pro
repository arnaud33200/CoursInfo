#-------------------------------------------------
#
# Project created by QtCreator 2012-03-03T10:17:11
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = HelloBeanClient
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../qjson/opt/include
LIBS += -L../qjson/opt/lib -lqjson


SOURCES += main.cpp \
    HelloBeanService.cpp \
    HelloBean.cpp

HEADERS += \
    HelloBeanService.hpp \
    HelloBean.hpp
