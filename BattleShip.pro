TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    board.cpp \
    coordinate.cpp \
    ship.cpp \
    destroyer.cpp

HEADERS += \
    board.h \
    coordinate.h \
    ship.h \
    destroyer.h

