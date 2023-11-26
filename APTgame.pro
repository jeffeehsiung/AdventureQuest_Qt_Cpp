QT       += core gui
CONFIG += c++17
QMAKE_CXXFLAGS += -fconcepts-diagnostics-depth=200
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = demo1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        controller/worldcontroller.cpp\
        model/world.cpp\
        model/EnemyModel.cpp\
        model/ProtagonistModel.cpp\



HEADERS  += mainwindow.h\
            controller/worldcontroller.h\
            model/world.h\
            model/structs.h\
            model/ProtagonistModel.h\
            model/Entity.h\
            model/EnemyModel.h\

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
