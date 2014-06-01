# -------------------------------------------------
# Meteo - Project created by QtCreator
# -------------------------------------------------
TARGET = meteo
TEMPLATE = app
QT += xml \
    network

CONFIG += release

SOURCES += main.cpp \
    mainwindow.cpp \
    engine/yahooeng.cpp
HEADERS += mainwindow.h \
    engine/engine.h \
    engine/yahooeng.h \
    engine/location.h \
    engine/weather.h
FORMS += mainwindow.ui


# -------------------------------------------------


unix {

OBJECTS_DIR =../out
MOC_DIR = ../out
UI_DIR = ../out
DESTDIR = ../LinuxDesktop

}


RC_FILE = radit.rc

OTHER_FILES +=

RESOURCES += \
    meteo.qrc
