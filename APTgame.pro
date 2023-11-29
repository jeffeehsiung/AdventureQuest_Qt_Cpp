QT       += core gui
CONFIG += c++17
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = demo1
TEMPLATE = app


SOURCES += main.cpp\
    Controller/WorldController.cpp \
    Model/EnemyModel.cpp \
    Model/ProtagonistModel.cpp \
    Model/world.cpp \
    View/EnemyGraphicsItem.cpp \
    View/Game2DView.cpp \
    View/GameTextView.cpp \
    View/ProtagonistGraphicsItem.cpp \
        MainWindow.cpp \
    View/TileGraphicsItem.cpp



HEADERS  += MainWindow.h\
    Controller/ViewController.h \
    Controller/WorldController.h \
    Model/EnemyModel.h \
    Model/Entity.h \
    Model/ProtagonistModel.h \
    Model/TileModel.h \
    Model/structs.h \
    Model/world.h \
    Model/world_global.h \
    View/EnemyGraphicsItem.h \
    View/EntityGraphicsItem.h \
    View/EntityTextItem.h \
    View/Game2DView.h \
    View/GameTextView.h \
    View/GameView.h \
    View/ProtagonistGraphicsItem.h \
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
    library/libworld.so \
    library/libworld.so.1 \
    library/libworld.so.1.0 \
    library/libworld.so.1.0.0

SUBDIRS += \
    world.pro
