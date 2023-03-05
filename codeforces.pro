TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++20

SOURCES += \
        main.cpp \
        solve.cpp

HEADERS += \
    template.h \
    tests.h

DISTFILES +=
