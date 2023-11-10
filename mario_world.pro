#by default two lib embedded
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Tile.cpp \
    WorldController.cpp \
    WorldModel.cpp \
    WorldView.cpp \
    main.cpp \
    mainwindow.cpp \
    world.cpp

HEADERS += \
    Tile.h \
    WorldController.h \
    WorldModel.h \
    WorldView.h \
    mainwindow.h \
    world.h \
    world_global.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    images.qrc

TRANSLATIONS += \
    mario_world_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README.md
