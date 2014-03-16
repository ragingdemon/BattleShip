TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    board.cpp \
    coordinate.cpp \
    ship.cpp \
    destroyer.cpp \
    cruiser.cpp \
    battleship.cpp \
    carrier.cpp

HEADERS += \
    board.h \
    coordinate.h \
    ship.h \
    destroyer.h \
    cruiser.h \
    battleship.h \
    carrier.h

