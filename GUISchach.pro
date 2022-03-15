QT       += core gui xml sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bauer.cpp \
    dame.cpp \
    database.cpp \
    feld.cpp \
    figur.cpp \
    koenig.cpp \
    lauefer.cpp \
    main.cpp \
    mainwindow.cpp \
    nofigur.cpp \
    spiel.cpp \
    springer.cpp \
    turm.cpp \
    xml_austausch.cpp

HEADERS += \
    bauer.h \
    dame.h \
    database.h \
    feld.h \
    figur.h \
    koenig.h \
    lauefer.h \
    mainwindow.h \
    nofigur.h \
    spiel.h \
    springer.h \
    turm.h \
    xml_austausch.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    classdiagramm.qmodel
