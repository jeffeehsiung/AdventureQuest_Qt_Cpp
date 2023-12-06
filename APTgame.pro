QT       += core gui
CONFIG += c++17
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = game
TEMPLATE = app


SOURCES += main.cpp\
    Controller/GameController.cpp \
    Controller/ViewController.cpp \
    Controller/WorldController.cpp \
    Model/EnemyModel.cpp \
    Model/ProtagonistModel.cpp \
    Model/TileModel.cpp \
    Model/struct.cpp \
    Model/world.cpp \
    View/EnemyGraphicsItem.cpp \
    View/EntityGraphicsItem.cpp \
    View/Game2DView.cpp \
    View/GameTextView.cpp \
    View/ProtagonistGraphicsItem.cpp \
    View/TileGraphicsItem.cpp \
    MainWindow.cpp \



HEADERS  += MainWindow.h\
    Controller/GameController.h \
    Controller/ViewController.h \
    Controller/WorldController.h \
    Model/EnemyModel.h \
    Model/Entity.h \
    Model/ProtagonistModel.h \
    Model/TileModel.h \
    Model/structs.h \
    Model/world.h \
    Model/world_global.h \
    View/Game2DView.h \
    View/GameTextView.h \
    View/GameView.h \
    View/EntityTextItem.h \
    View/ProtagonistGraphicsItem.h \
    View/EnemyGraphicsItem.h \
    View/EntityGraphicsItem.h \
    View/TileGraphicsItem.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc

DISTFILES += \
    APTgame.pro.user \
    CMakeLists.txt \
    Final_project_class_architecture.docx \
    Makefile \
    README.md \
    UML_v1.png \
    UML_v2.png \
    images/protagonist_fighter/Moving/01.png \
    library/libworld.so \
    library/libworld.so.1 \
    library/libworld.so.1.0 \
    library/libworld.so.1.0.0

SUBDIRS += \
    world.pro
