CONFIG -= app_bundle
QT += widgets

LIBS += -L$$PWD/./lib -llibmpv-2 -lopengl32
INCLUDEPATH += $$PWD/include/


HEADERS = \
    mpvwidget.h \
    mainwindow.h
SOURCES = main.cpp \
    mpvwidget.cpp \
    mainwindow.cpp
