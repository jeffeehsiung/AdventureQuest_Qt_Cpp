QT       += core gui
CONFIG += c++17
QMAKE_CXXFLAGS += -fconcepts-diagnostics-depth=200
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = demo1
TEMPLATE = app


SOURCES += main.cpp\
    Model/EnemyModel.cpp \
    Model/ProtagonistModel.cpp \
    Model/world.cpp \
    View/EnemyGraphicsItem.cpp \
    View/Game2DView.cpp \
    View/GameTextView.cpp \
    View/ProtagonistGraphicsItem.cpp \
        mainwindow.cpp \
        controller/WorldController.cpp\
        controller/GameController.cpp\
        model/world.cpp\
        model/EnemyModel.cpp\
        model/ProtagonistModel.cpp\



HEADERS  += mainwindow.h\
    Controller/GameController.h \
    Controller/GameState.h \
    Controller/GameVeiwControllerFactory.h \
    Controller/GraphicsViewController.h \
    Controller/InputType.h \
    Controller/TextViewController.h \
    Controller/ViewController.h \
    Controller/ViewControllerFactory.h \
    Controller/ViewType.h \
    Controller/WindowController.h \
    Controller/WorldController.h \
    Model/EnemyModel.h \
    Model/Entity.h \
    Model/HealthPackModel.h \
    Model/ProtagonistModel.h \
    Model/structs.h \
    Model/world.h \
    Model/world_global.h \
    MoveCommandStrategy.h \
    Strategy.h \
    View/EnemyGraphicsItem.h \
    View/EntityGraphicsItem.h \
    View/EntityTextItem.h \
    View/Game2DView.h \
    View/GameTextView.h \

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
