#-------------------------------------------------
#
# Project created by QtCreator 2016-11-09T11:11:10
#
#-------------------------------------------------

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
    View/GameView.h \
    View/ProtagonistGraphicsItem.h \
    pathfinder.h \
            world.h\

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
    images/enemy.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_000.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_000.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_000.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_000.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_000.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_000.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_000.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_001.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_001.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_001.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_001.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_001.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_001.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_001.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_002.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_002.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_002.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_002.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_002.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_002.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_002.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_003.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_003.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_003.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_003.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_003.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_003.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_003.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_004.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_004.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_004.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_004.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_004.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_004.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_004.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_005.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_005.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_005.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_005.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_005.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_005.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_005.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_006.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_006.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_006.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_006.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_006.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_006.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_006.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_007.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_007.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_007.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_007.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_007.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_007.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_007.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_008.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_008.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_008.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_008.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_008.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_008.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_008.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_009.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_009.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_009.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_009.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_009.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_009.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_009.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_010.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_010.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_010.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_010.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_010.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_010.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_010.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_011.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_011.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_011.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_011.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_011.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_011.png \
    images/enemy_golem/PNG Sequences/Attacking/Golem_01_Attacking_011.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_000.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_000.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_000.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_000.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_000.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_000.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_000.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_001.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_001.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_001.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_001.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_001.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_001.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_001.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_002.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_002.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_002.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_002.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_002.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_002.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_002.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_003.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_003.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_003.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_003.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_003.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_003.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_003.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_004.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_004.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_004.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_004.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_004.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_004.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_004.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_005.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_005.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_005.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_005.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_005.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_005.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_005.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_006.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_006.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_006.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_006.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_006.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_006.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_006.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_007.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_007.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_007.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_007.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_007.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_007.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_007.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_008.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_008.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_008.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_008.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_008.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_008.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_008.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_009.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_009.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_009.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_009.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_009.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_009.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_009.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_010.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_010.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_010.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_010.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_010.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_010.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_010.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_011.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_011.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_011.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_011.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_011.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_011.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_011.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_012.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_012.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_012.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_012.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_012.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_012.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_012.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_013.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_013.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_013.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_013.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_013.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_013.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_013.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_014.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_014.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_014.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_014.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_014.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_014.png \
    images/enemy_golem/PNG Sequences/Dying/Golem_01_Dying_014.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_000.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_000.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_000.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_000.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_000.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_000.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_000.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_001.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_001.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_001.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_001.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_001.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_001.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_001.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_002.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_002.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_002.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_002.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_002.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_002.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_002.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_003.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_003.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_003.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_003.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_003.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_003.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_003.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_004.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_004.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_004.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_004.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_004.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_004.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_004.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_005.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_005.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_005.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_005.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_005.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_005.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_005.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_006.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_006.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_006.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_006.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_006.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_006.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_006.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_007.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_007.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_007.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_007.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_007.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_007.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_007.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_008.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_008.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_008.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_008.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_008.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_008.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_008.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_009.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_009.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_009.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_009.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_009.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_009.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_009.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_010.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_010.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_010.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_010.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_010.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_010.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_010.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_011.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_011.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_011.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_011.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_011.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_011.png \
    images/enemy_golem/PNG Sequences/Hurt/Golem_01_Hurt_011.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_000.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_000.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_000.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_000.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_000.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_000.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_000.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_001.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_001.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_001.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_001.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_001.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_001.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_001.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_002.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_002.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_002.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_002.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_002.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_002.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_002.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_003.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_003.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_003.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_003.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_003.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_003.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_003.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_004.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_004.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_004.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_004.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_004.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_004.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_004.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_005.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_005.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_005.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_005.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_005.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_005.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_005.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_006.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_006.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_006.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_006.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_006.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_006.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_006.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_007.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_007.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_007.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_007.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_007.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_007.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_007.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_008.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_008.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_008.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_008.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_008.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_008.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_008.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_009.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_009.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_009.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_009.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_009.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_009.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_009.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_010.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_010.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_010.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_010.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_010.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_010.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_010.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_011.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_011.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_011.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_011.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_011.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_011.png \
    images/enemy_golem/PNG Sequences/Idle Blink/Golem_01_Idle Blinking_011.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_000.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_000.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_000.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_000.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_000.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_000.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_000.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_001.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_001.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_001.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_001.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_001.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_001.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_001.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_002.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_002.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_002.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_002.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_002.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_002.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_002.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_003.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_003.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_003.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_003.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_003.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_003.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_003.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_004.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_004.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_004.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_004.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_004.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_004.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_004.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_005.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_005.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_005.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_005.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_005.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_005.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_005.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_006.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_006.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_006.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_006.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_006.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_006.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_006.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_007.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_007.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_007.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_007.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_007.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_007.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_007.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_008.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_008.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_008.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_008.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_008.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_008.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_008.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_009.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_009.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_009.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_009.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_009.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_009.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_009.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_010.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_010.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_010.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_010.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_010.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_010.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_010.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_011.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_011.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_011.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_011.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_011.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_011.png \
    images/enemy_golem/PNG Sequences/Idle/Golem_01_Idle_011.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_000.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_000.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_000.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_000.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_000.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_000.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_000.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_001.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_001.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_001.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_001.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_001.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_001.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_001.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_002.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_002.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_002.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_002.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_002.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_002.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_002.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_003.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_003.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_003.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_003.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_003.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_003.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_003.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_004.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_004.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_004.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_004.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_004.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_004.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_004.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_005.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_005.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_005.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_005.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_005.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_005.png \
    images/enemy_golem/PNG Sequences/Jump Loop/Golem_01_Jump Loop_005.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_000.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_000.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_000.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_000.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_000.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_000.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_000.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_001.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_001.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_001.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_001.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_001.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_001.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_001.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_002.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_002.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_002.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_002.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_002.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_002.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_002.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_003.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_003.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_003.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_003.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_003.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_003.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_003.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_004.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_004.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_004.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_004.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_004.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_004.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_004.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_005.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_005.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_005.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_005.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_005.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_005.png \
    images/enemy_golem/PNG Sequences/Jump Start/Golem_01_Jump Start_005.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_000.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_000.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_000.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_000.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_000.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_000.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_000.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_001.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_001.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_001.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_001.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_001.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_001.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_001.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_002.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_002.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_002.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_002.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_002.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_002.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_002.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_003.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_003.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_003.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_003.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_003.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_003.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_003.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_004.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_004.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_004.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_004.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_004.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_004.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_004.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_005.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_005.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_005.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_005.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_005.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_005.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_005.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_006.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_006.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_006.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_006.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_006.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_006.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_006.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_007.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_007.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_007.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_007.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_007.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_007.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_007.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_008.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_008.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_008.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_008.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_008.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_008.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_008.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_009.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_009.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_009.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_009.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_009.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_009.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_009.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_010.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_010.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_010.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_010.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_010.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_010.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_010.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_011.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_011.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_011.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_011.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_011.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_011.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_011.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_012.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_012.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_012.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_012.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_012.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_012.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_012.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_013.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_013.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_013.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_013.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_013.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_013.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_013.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_014.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_014.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_014.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_014.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_014.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_014.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_014.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_015.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_015.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_015.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_015.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_015.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_015.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_015.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_016.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_016.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_016.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_016.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_016.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_016.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_016.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_017.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_017.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_017.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_017.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_017.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_017.png \
    images/enemy_golem/PNG Sequences/Taunt/Golem_01_Taunt_017.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_000.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_000.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_000.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_000.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_000.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_000.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_000.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_001.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_001.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_001.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_001.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_001.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_001.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_001.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_002.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_002.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_002.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_002.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_002.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_002.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_002.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_003.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_003.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_003.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_003.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_003.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_003.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_003.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_004.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_004.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_004.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_004.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_004.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_004.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_004.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_005.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_005.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_005.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_005.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_005.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_005.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_005.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_006.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_006.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_006.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_006.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_006.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_006.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_006.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_007.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_007.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_007.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_007.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_007.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_007.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_007.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_008.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_008.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_008.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_008.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_008.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_008.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_008.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_009.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_009.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_009.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_009.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_009.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_009.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_009.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_010.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_010.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_010.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_010.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_010.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_010.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_010.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_011.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_011.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_011.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_011.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_011.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_011.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_011.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_012.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_012.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_012.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_012.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_012.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_012.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_012.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_013.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_013.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_013.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_013.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_013.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_013.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_013.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_014.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_014.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_014.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_014.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_014.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_014.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_014.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_015.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_015.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_015.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_015.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_015.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_015.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_015.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_016.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_016.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_016.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_016.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_016.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_016.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_016.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_017.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_017.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_017.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_017.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_017.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_017.png \
    images/enemy_golem/PNG Sequences/Walking/Golem_01_Walking_017.png \
    images/enemy_golem/Vector Parts/Animations.scml \
    images/enemy_golem/Vector Parts/Animations.scml \
    images/enemy_golem/Vector Parts/Animations.scml \
    images/enemy_golem/Vector Parts/Animations.scml \
    images/enemy_golem/Vector Parts/Animations.scml \
    images/enemy_golem/Vector Parts/Animations.scml \
    images/enemy_golem/Vector Parts/Animations.scml \
    images/enemy_golem/Vector Parts/Body.png \
    images/enemy_golem/Vector Parts/Body.png \
    images/enemy_golem/Vector Parts/Body.png \
    images/enemy_golem/Vector Parts/Body.png \
    images/enemy_golem/Vector Parts/Body.png \
    images/enemy_golem/Vector Parts/Body.png \
    images/enemy_golem/Vector Parts/Body.png \
    images/enemy_golem/Vector Parts/Face 01.png \
    images/enemy_golem/Vector Parts/Face 01.png \
    images/enemy_golem/Vector Parts/Face 01.png \
    images/enemy_golem/Vector Parts/Face 01.png \
    images/enemy_golem/Vector Parts/Face 01.png \
    images/enemy_golem/Vector Parts/Face 01.png \
    images/enemy_golem/Vector Parts/Face 01.png \
    images/enemy_golem/Vector Parts/Face 02.png \
    images/enemy_golem/Vector Parts/Face 02.png \
    images/enemy_golem/Vector Parts/Face 02.png \
    images/enemy_golem/Vector Parts/Face 02.png \
    images/enemy_golem/Vector Parts/Face 02.png \
    images/enemy_golem/Vector Parts/Face 02.png \
    images/enemy_golem/Vector Parts/Face 02.png \
    images/enemy_golem/Vector Parts/Face 03.png \
    images/enemy_golem/Vector Parts/Face 03.png \
    images/enemy_golem/Vector Parts/Face 03.png \
    images/enemy_golem/Vector Parts/Face 03.png \
    images/enemy_golem/Vector Parts/Face 03.png \
    images/enemy_golem/Vector Parts/Face 03.png \
    images/enemy_golem/Vector Parts/Face 03.png \
    images/enemy_golem/Vector Parts/Head.png \
    images/enemy_golem/Vector Parts/Head.png \
    images/enemy_golem/Vector Parts/Head.png \
    images/enemy_golem/Vector Parts/Head.png \
    images/enemy_golem/Vector Parts/Head.png \
    images/enemy_golem/Vector Parts/Head.png \
    images/enemy_golem/Vector Parts/Head.png \
    images/enemy_golem/Vector Parts/Left Arm.png \
    images/enemy_golem/Vector Parts/Left Arm.png \
    images/enemy_golem/Vector Parts/Left Arm.png \
    images/enemy_golem/Vector Parts/Left Arm.png \
    images/enemy_golem/Vector Parts/Left Arm.png \
    images/enemy_golem/Vector Parts/Left Arm.png \
    images/enemy_golem/Vector Parts/Left Arm.png \
    images/enemy_golem/Vector Parts/Left Hand.png \
    images/enemy_golem/Vector Parts/Left Hand.png \
    images/enemy_golem/Vector Parts/Left Hand.png \
    images/enemy_golem/Vector Parts/Left Hand.png \
    images/enemy_golem/Vector Parts/Left Hand.png \
    images/enemy_golem/Vector Parts/Left Hand.png \
    images/enemy_golem/Vector Parts/Left Hand.png \
    images/enemy_golem/Vector Parts/Left Leg.png \
    images/enemy_golem/Vector Parts/Left Leg.png \
    images/enemy_golem/Vector Parts/Left Leg.png \
    images/enemy_golem/Vector Parts/Left Leg.png \
    images/enemy_golem/Vector Parts/Left Leg.png \
    images/enemy_golem/Vector Parts/Left Leg.png \
    images/enemy_golem/Vector Parts/Left Leg.png \
    images/enemy_golem/Vector Parts/Right Arm.png \
    images/enemy_golem/Vector Parts/Right Arm.png \
    images/enemy_golem/Vector Parts/Right Arm.png \
    images/enemy_golem/Vector Parts/Right Arm.png \
    images/enemy_golem/Vector Parts/Right Arm.png \
    images/enemy_golem/Vector Parts/Right Arm.png \
    images/enemy_golem/Vector Parts/Right Arm.png \
    images/enemy_golem/Vector Parts/Right Hand.png \
    images/enemy_golem/Vector Parts/Right Hand.png \
    images/enemy_golem/Vector Parts/Right Hand.png \
    images/enemy_golem/Vector Parts/Right Hand.png \
    images/enemy_golem/Vector Parts/Right Hand.png \
    images/enemy_golem/Vector Parts/Right Hand.png \
    images/enemy_golem/Vector Parts/Right Hand.png \
    images/enemy_golem/Vector Parts/Right Leg.png \
    images/enemy_golem/Vector Parts/Right Leg.png \
    images/enemy_golem/Vector Parts/Right Leg.png \
    images/enemy_golem/Vector Parts/Right Leg.png \
    images/enemy_golem/Vector Parts/Right Leg.png \
    images/enemy_golem/Vector Parts/Right Leg.png \
    images/enemy_golem/Vector Parts/Right Leg.png \
    images/enemy_golem/Vector Parts/Weapon.png \
    images/enemy_golem/Vector Parts/Weapon.png \
    images/enemy_golem/Vector Parts/Weapon.png \
    images/enemy_golem/Vector Parts/Weapon.png \
    images/enemy_golem/Vector Parts/Weapon.png \
    images/enemy_golem/Vector Parts/Weapon.png \
    images/enemy_golem/Vector Parts/Weapon.png \
    images/enemy_golem_attack/Explosion_1.png \
    images/enemy_golem_attack/Explosion_10.png \
    images/enemy_golem_attack/Explosion_2.png \
    images/enemy_golem_attack/Explosion_3.png \
    images/enemy_golem_attack/Explosion_4.png \
    images/enemy_golem_attack/Explosion_5.png \
    images/enemy_golem_attack/Explosion_6.png \
    images/enemy_golem_attack/Explosion_7.png \
    images/enemy_golem_attack/Explosion_8.png \
    images/enemy_golem_attack/Explosion_9.png \
    images/fixed_attack_direction/PNG/00.png \
    images/fixed_attack_direction/PNG/01.png \
    images/fixed_attack_direction/PNG/02.png \
    images/fixed_attack_direction/PNG/03.png \
    images/fixed_attack_direction/PNG/04.png \
    images/fixed_attack_direction/PNG/05.png \
    images/fixed_attack_direction/PNG/06.png \
    images/fixed_attack_direction/PNG/07.png \
    images/fixed_attack_direction/PNG/08.png \
    images/fixed_attack_direction/PNG/09.png \
    images/fixed_attack_direction/PNG/10.png \
    images/fixed_attack_direction/PNG/11.png \
    images/fixed_attack_direction/PNG/12.png \
    images/fixed_attack_direction/PNG/13.png \
    images/fixed_attack_direction/PNG/14.png \
    images/fixed_attack_direction/PNG/15.png \
    images/fixed_attack_direction/PNG/16.png \
    images/fixed_attack_direction/PNG/17.png \
    images/fixed_attack_direction/PNG/18.png \
    images/fixed_attack_direction/PNG/19.png \
    images/fixed_attack_direction/PNG/20.png \
    images/fixed_attack_direction/PNG/21.png \
    images/fixed_attack_direction/PNG/22.png \
    images/fixed_attack_direction/PNG/23.png \
    images/fixed_attack_direction/PNG/24.png \
    images/fixed_attack_direction/PNG/25.png \
    images/fixed_attack_direction/PNG/26.png \
    images/fixed_attack_direction/PNG/27.png \
    images/fixed_attack_direction/PNG/28.png \
    images/fixed_attack_direction/PNG/29.png \
    images/fixed_attack_direction/PNG/30.png \
    images/fixed_attack_direction/PNG/31.png \
    images/fixed_attack_direction/PNG/32.png \
    images/fixed_attack_direction/PNG/33.png \
    images/fixed_attack_direction/PNG/34.png \
    images/fixed_attack_direction/PNG/35.png \
    images/fixed_attack_direction/PNG/36.png \
    images/fixed_attack_direction/PNG/37.png \
    images/fixed_attack_direction/PNG/38.png \
    images/fixed_attack_direction/PNG/39.png \
    images/fixed_attack_direction/PNG/40.png \
    images/fixed_attack_direction/SPINE/flame10.atlas.txt \
    images/fixed_attack_direction/SPINE/flame10.json \
    images/fixed_attack_direction/SPINE/flame10.png \
    images/fixed_attack_direction/SPINE/flame102.png \
    images/fixed_attack_direction/SPINE/flame103.png \
    images/fixed_attack_direction/SPINE/flame104.png \
    images/fixed_attack_direction/flame10.psd \
    images/fixed_attack_direction/flame10.spine \
    images/fixed_attack_direction/gif demo.gif \
    images/fixed_attack_direction/gif demo.gif \
    images/fixed_attack_direction/gif demo.gif \
    images/fixed_attack_direction/gif demo.gif \
    images/fixed_attack_direction/images/light.png \
    images/fixed_attack_direction/images/vjuh.json \
    images/fixed_attack_direction/images/vjuh.png \
    images/fixed_attack_direction/images/vjuh2.png \
    images/fixed_attack_direction/images/vjuh_00002.png \
    images/fixed_attack_direction/images/vjuh_00003.png \
    images/fixed_attack_direction/images/vjuh_00004.png \
    images/fixed_attack_direction/images/vjuh_00005.png \
    images/fixed_attack_direction/images/vjuh_00006.png \
    images/fixed_attack_direction/images/vjuh_00007.png \
    images/fixed_attack_direction/images/vjuh_00008.png \
    images/fixed_attack_direction/images/vjuh_00009.png \
    images/fixed_attack_direction/images/vjuh_00010.png \
    images/fixed_attack_direction/images/vjuh_00011.png \
    images/fixed_attack_direction/images/vjuh_00012.png \
    images/fixed_attack_direction/images/vjuh_00013.png \
    images/fixed_attack_direction/images/vjuh_00014.png \
    images/fixed_attack_direction/images/vjuh_00015.png \
    images/fixed_attack_direction/images/vjuh_00016.png \
    images/fixed_attack_direction/images/vjuh_00017.png \
    images/fixed_attack_direction/images/vjuh_00018.png \
    images/fixed_attack_direction/images/vjuh_00019.png \
    images/fixed_attack_direction/images/vjuh_00020.png \
    images/fixed_attack_direction/images/vjuh_00021.png \
    images/fixed_attack_direction/images/vjuh_00022.png \
    images/fixed_attack_direction/images/vjuh_00023.png \
    images/fixed_attack_direction/images/vjuh_00024.png \
    images/fixed_attack_direction/images/vjuh_00025.png \
    images/fixed_attack_direction/images/vjuh_00026.png \
    images/fixed_attack_direction/images/vjuh_00027.png \
    images/fixed_attack_direction/images/vjuh_00028.png \
    images/fixed_attack_direction/images/vjuh_00029.png \
    images/fixed_attack_static/flame1.moho \
    images/fixed_attack_static/flame1.psd \
    images/fixed_attack_static/flame1.spine \
    images/fixed_attack_static/gif demo.gif \
    images/fixed_attack_static/gif demo.gif \
    images/fixed_attack_static/gif demo.gif \
    images/fixed_attack_static/gif demo.gif \
    images/fixed_attack_static/images/Sek_00001.png \
    images/fixed_attack_static/images/Sek_00002.png \
    images/fixed_attack_static/images/Sek_00003.png \
    images/fixed_attack_static/images/Sek_00004.png \
    images/fixed_attack_static/images/Sek_00005.png \
    images/fixed_attack_static/images/Sek_00006.png \
    images/fixed_attack_static/images/Sek_00007.png \
    images/fixed_attack_static/images/Sek_00008.png \
    images/fixed_attack_static/images/Sek_00009.png \
    images/fixed_attack_static/images/Sek_00010.png \
    images/fixed_attack_static/images/Sek_00011.png \
    images/fixed_attack_static/images/Sek_00012.png \
    images/fixed_attack_static/images/Sek_00013.png \
    images/fixed_attack_static/images/Sek_00014.png \
    images/fixed_attack_static/images/Sek_00015.png \
    images/fixed_attack_static/images/Sek_00016.png \
    images/fixed_attack_static/images/Sek_00017.png \
    images/fixed_attack_static/images/Sek_00018.png \
    images/fixed_attack_static/images/Sek_00019.png \
    images/fixed_attack_static/images/Sek_00020.png \
    images/fixed_attack_static/images/Sek_00021.png \
    images/fixed_attack_static/images/Sek_00022.png \
    images/fixed_attack_static/images/Sek_00023.png \
    images/fixed_attack_static/images/Sek_00024.png \
    images/fixed_attack_static/images/Sek_00025.png \
    images/fixed_attack_static/images/Sek_00026.png \
    images/fixed_attack_static/images/Sek_00027.png \
    images/fixed_attack_static/images/babah.json \
    images/fixed_attack_static/images/light2.png \
    images/fixed_attack_static/images/template.png \
    images/fixed_attack_static/png/00.png \
    images/fixed_attack_static/png/01.png \
    images/fixed_attack_static/png/02.png \
    images/fixed_attack_static/png/03.png \
    images/fixed_attack_static/png/04.png \
    images/fixed_attack_static/png/05.png \
    images/fixed_attack_static/png/06.png \
    images/fixed_attack_static/png/07.png \
    images/fixed_attack_static/png/08.png \
    images/fixed_attack_static/png/09.png \
    images/fixed_attack_static/png/10.png \
    images/fixed_attack_static/png/11.png \
    images/fixed_attack_static/png/12.png \
    images/fixed_attack_static/png/13.png \
    images/fixed_attack_static/png/14.png \
    images/fixed_attack_static/png/15.png \
    images/fixed_attack_static/png/16.png \
    images/fixed_attack_static/png/17.png \
    images/fixed_attack_static/png/18.png \
    images/fixed_attack_static/png/19.png \
    images/fixed_attack_static/png/20.png \
    images/fixed_attack_static/png/21.png \
    images/fixed_attack_static/png/22.png \
    images/fixed_attack_static/png/23.png \
    images/fixed_attack_static/png/24.png \
    images/fixed_attack_static/png/25.png \
    images/fixed_attack_static/png/26.png \
    images/fixed_attack_static/png/27.png \
    images/fixed_attack_static/spine/flame1.atlas.txt \
    images/fixed_attack_static/spine/flame1.json \
    images/fixed_attack_static/spine/flame1.png \
    images/healthpack/1.png \
    images/healthpack/2.png \
    images/healthpack/3.png \
    images/healthpack/4.png \
    images/healthpack/5.png \
    images/healthpack/6.png \
    images/logo.png \
    images/penemy.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_000.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_000.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_000.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_000.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_001.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_001.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_001.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_001.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_002.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_002.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_002.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_002.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_003.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_003.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_003.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_003.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_004.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_004.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_004.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_004.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_005.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_005.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_005.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_005.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_006.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_006.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_006.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_006.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_007.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_007.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_007.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_007.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_008.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_008.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_008.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_008.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_009.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_009.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_009.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_009.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_010.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_010.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_010.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_010.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_011.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_011.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_011.png \
    images/penemy_wraith/PNG Sequences/Attacking/Wraith_01_Attack_011.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_000.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_000.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_000.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_000.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_001.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_001.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_001.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_001.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_002.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_002.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_002.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_002.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_003.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_003.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_003.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_003.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_004.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_004.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_004.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_004.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_005.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_005.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_005.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_005.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_006.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_006.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_006.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_006.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_007.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_007.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_007.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_007.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_008.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_008.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_008.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_008.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_009.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_009.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_009.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_009.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_010.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_010.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_010.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_010.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_011.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_011.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_011.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_011.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_012.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_012.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_012.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_012.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_013.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_013.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_013.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_013.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_014.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_014.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_014.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_014.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_015.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_015.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_015.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_015.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_016.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_016.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_016.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_016.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_017.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_017.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_017.png \
    images/penemy_wraith/PNG Sequences/Casting Spells/Wraith_01_Casting Spells_017.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_000.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_000.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_000.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_000.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_001.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_001.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_001.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_001.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_002.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_002.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_002.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_002.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_003.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_003.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_003.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_003.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_004.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_004.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_004.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_004.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_005.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_005.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_005.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_005.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_006.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_006.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_006.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_006.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_007.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_007.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_007.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_007.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_008.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_008.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_008.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_008.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_009.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_009.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_009.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_009.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_010.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_010.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_010.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_010.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_011.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_011.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_011.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_011.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_012.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_012.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_012.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_012.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_013.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_013.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_013.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_013.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_014.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_014.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_014.png \
    images/penemy_wraith/PNG Sequences/Dying/Wraith_01_Dying_014.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_000.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_000.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_000.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_000.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_001.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_001.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_001.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_001.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_002.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_002.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_002.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_002.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_003.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_003.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_003.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_003.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_004.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_004.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_004.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_004.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_005.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_005.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_005.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_005.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_006.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_006.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_006.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_006.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_007.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_007.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_007.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_007.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_008.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_008.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_008.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_008.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_009.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_009.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_009.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_009.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_010.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_010.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_010.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_010.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_011.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_011.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_011.png \
    images/penemy_wraith/PNG Sequences/Hurt/Wraith_01_Hurt_011.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_000.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_000.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_000.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_000.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_001.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_001.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_001.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_001.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_002.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_002.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_002.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_002.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_003.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_003.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_003.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_003.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_004.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_004.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_004.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_004.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_005.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_005.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_005.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_005.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_006.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_006.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_006.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_006.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_007.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_007.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_007.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_007.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_008.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_008.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_008.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_008.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_009.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_009.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_009.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_009.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_010.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_010.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_010.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_010.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_011.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_011.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_011.png \
    images/penemy_wraith/PNG Sequences/Idle Blink/Wraith_01_Idle Blinking_011.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_000.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_000.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_000.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_000.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_001.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_001.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_001.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_001.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_002.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_002.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_002.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_002.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_003.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_003.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_003.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_003.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_004.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_004.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_004.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_004.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_005.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_005.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_005.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_005.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_006.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_006.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_006.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_006.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_007.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_007.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_007.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_007.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_008.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_008.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_008.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_008.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_009.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_009.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_009.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_009.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_010.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_010.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_010.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_010.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_011.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_011.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_011.png \
    images/penemy_wraith/PNG Sequences/Idle/Wraith_01_Idle_011.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_000.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_000.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_000.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_000.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_001.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_001.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_001.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_001.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_002.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_002.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_002.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_002.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_003.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_003.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_003.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_003.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_004.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_004.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_004.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_004.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_005.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_005.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_005.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_005.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_006.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_006.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_006.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_006.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_007.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_007.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_007.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_007.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_008.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_008.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_008.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_008.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_009.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_009.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_009.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_009.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_010.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_010.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_010.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_010.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_011.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_011.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_011.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_011.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_012.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_012.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_012.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_012.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_013.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_013.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_013.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_013.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_014.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_014.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_014.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_014.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_015.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_015.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_015.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_015.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_016.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_016.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_016.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_016.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_017.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_017.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_017.png \
    images/penemy_wraith/PNG Sequences/Taunt/Wraith_01_Taunt_017.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_000.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_000.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_000.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_000.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_001.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_001.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_001.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_001.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_002.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_002.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_002.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_002.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_003.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_003.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_003.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_003.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_004.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_004.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_004.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_004.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_005.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_005.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_005.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_005.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_006.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_006.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_006.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_006.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_007.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_007.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_007.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_007.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_008.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_008.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_008.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_008.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_009.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_009.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_009.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_009.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_010.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_010.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_010.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_010.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_011.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_011.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_011.png \
    images/penemy_wraith/PNG Sequences/Walking/Wraith_01_Moving Forward_011.png \
    images/penemy_wraith/Vector Parts/Animations.scml \
    images/penemy_wraith/Vector Parts/Animations.scml \
    images/penemy_wraith/Vector Parts/Animations.scml \
    images/penemy_wraith/Vector Parts/Animations.scml \
    images/penemy_wraith/Vector Parts/Body.png \
    images/penemy_wraith/Vector Parts/Body.png \
    images/penemy_wraith/Vector Parts/Body.png \
    images/penemy_wraith/Vector Parts/Body.png \
    images/penemy_wraith/Vector Parts/Face 01.png \
    images/penemy_wraith/Vector Parts/Face 01.png \
    images/penemy_wraith/Vector Parts/Face 01.png \
    images/penemy_wraith/Vector Parts/Face 01.png \
    images/penemy_wraith/Vector Parts/Face 02.png \
    images/penemy_wraith/Vector Parts/Face 02.png \
    images/penemy_wraith/Vector Parts/Face 02.png \
    images/penemy_wraith/Vector Parts/Face 02.png \
    images/penemy_wraith/Vector Parts/Face 03.png \
    images/penemy_wraith/Vector Parts/Face 03.png \
    images/penemy_wraith/Vector Parts/Face 03.png \
    images/penemy_wraith/Vector Parts/Face 03.png \
    images/penemy_wraith/Vector Parts/Head.png \
    images/penemy_wraith/Vector Parts/Head.png \
    images/penemy_wraith/Vector Parts/Head.png \
    images/penemy_wraith/Vector Parts/Head.png \
    images/penemy_wraith/Vector Parts/Left Arm.png \
    images/penemy_wraith/Vector Parts/Left Arm.png \
    images/penemy_wraith/Vector Parts/Left Arm.png \
    images/penemy_wraith/Vector Parts/Left Arm.png \
    images/penemy_wraith/Vector Parts/Left Hand.png \
    images/penemy_wraith/Vector Parts/Left Hand.png \
    images/penemy_wraith/Vector Parts/Left Hand.png \
    images/penemy_wraith/Vector Parts/Left Hand.png \
    images/penemy_wraith/Vector Parts/Right Arm.png \
    images/penemy_wraith/Vector Parts/Right Arm.png \
    images/penemy_wraith/Vector Parts/Right Arm.png \
    images/penemy_wraith/Vector Parts/Right Arm.png \
    images/penemy_wraith/Vector Parts/Right Hand.png \
    images/penemy_wraith/Vector Parts/Right Hand.png \
    images/penemy_wraith/Vector Parts/Right Hand.png \
    images/penemy_wraith/Vector Parts/Right Hand.png \
    images/penemy_wraith/Vector Parts/Spells Effect.png \
    images/penemy_wraith/Vector Parts/Spells Effect.png \
    images/penemy_wraith/Vector Parts/Spells Effect.png \
    images/penemy_wraith/Vector Parts/Spells Effect.png \
    images/penemy_wraith_poison/Explosion_1.png \
    images/penemy_wraith_poison/Explosion_10.png \
    images/penemy_wraith_poison/Explosion_2.png \
    images/penemy_wraith_poison/Explosion_3.png \
    images/penemy_wraith_poison/Explosion_4.png \
    images/penemy_wraith_poison/Explosion_5.png \
    images/penemy_wraith_poison/Explosion_6.png \
    images/penemy_wraith_poison/Explosion_7.png \
    images/penemy_wraith_poison/Explosion_8.png \
    images/penemy_wraith_poison/Explosion_9.png \
    images/protagonist.png \
    images/protagonist_fighter/Attack_1.png \
    images/protagonist_fighter/Attack_2.png \
    images/protagonist_fighter/Attack_3.png \
    images/protagonist_fighter/Dead.png \
    images/protagonist_fighter/Hurt.png \
    images/protagonist_fighter/Idle.png \
    images/protagonist_fighter/Jump.png \
    images/protagonist_fighter/Run.png \
    images/protagonist_fighter/Shield.png \
    images/protagonist_fighter/Walk.png \
    images/protagonist_heal/Explosion_1.png \
    images/protagonist_heal/Explosion_10.png \
    images/protagonist_heal/Explosion_2.png \
    images/protagonist_heal/Explosion_3.png \
    images/protagonist_heal/Explosion_4.png \
    images/protagonist_heal/Explosion_5.png \
    images/protagonist_heal/Explosion_6.png \
    images/protagonist_heal/Explosion_7.png \
    images/protagonist_heal/Explosion_8.png \
    images/protagonist_heal/Explosion_9.png \
    images/protagonist_samurai/Attack_1.png \
    images/protagonist_samurai/Attack_2.png \
    images/protagonist_samurai/Attack_3.png \
    images/protagonist_samurai/Dead.png \
    images/protagonist_samurai/Hurt.png \
    images/protagonist_samurai/Idle.png \
    images/protagonist_samurai/Jump.png \
    images/protagonist_samurai/Run.png \
    images/protagonist_samurai/Shield.png \
    images/protagonist_samurai/Walk.png \
    images/protagonist_shinobi/Attack_1.png \
    images/protagonist_shinobi/Attack_2.png \
    images/protagonist_shinobi/Attack_3.png \
    images/protagonist_shinobi/Dead.png \
    images/protagonist_shinobi/Hurt.png \
    images/protagonist_shinobi/Idle.png \
    images/protagonist_shinobi/Jump.png \
    images/protagonist_shinobi/Run.png \
    images/protagonist_shinobi/Shield.png \
    images/protagonist_shinobi/Walk.png \
    images/world_images/maze1.png \
    images/world_images/maze2.png \
    images/world_images/maze3.png \
    images/world_images/worldmap.png \
    images/world_images/worldmap4.png \
    images/xenemy.png \
    images/xenemy_monster/1_enemies_1_attack_000.png \
    images/xenemy_monster/1_enemies_1_attack_001.png \
    images/xenemy_monster/1_enemies_1_attack_002.png \
    images/xenemy_monster/1_enemies_1_attack_003.png \
    images/xenemy_monster/1_enemies_1_attack_004.png \
    images/xenemy_monster/1_enemies_1_attack_005.png \
    images/xenemy_monster/1_enemies_1_attack_006.png \
    images/xenemy_monster/1_enemies_1_attack_007.png \
    images/xenemy_monster/1_enemies_1_attack_008.png \
    images/xenemy_monster/1_enemies_1_attack_009.png \
    images/xenemy_monster/1_enemies_1_attack_010.png \
    images/xenemy_monster/1_enemies_1_attack_011.png \
    images/xenemy_monster/1_enemies_1_attack_012.png \
    images/xenemy_monster/1_enemies_1_attack_013.png \
    images/xenemy_monster/1_enemies_1_attack_014.png \
    images/xenemy_monster/1_enemies_1_attack_015.png \
    images/xenemy_monster/1_enemies_1_attack_016.png \
    images/xenemy_monster/1_enemies_1_attack_017.png \
    images/xenemy_monster/1_enemies_1_attack_018.png \
    images/xenemy_monster/1_enemies_1_attack_019.png \
    images/xenemy_monster/1_enemies_1_die_000.png \
    images/xenemy_monster/1_enemies_1_die_001.png \
    images/xenemy_monster/1_enemies_1_die_002.png \
    images/xenemy_monster/1_enemies_1_die_003.png \
    images/xenemy_monster/1_enemies_1_die_004.png \
    images/xenemy_monster/1_enemies_1_die_005.png \
    images/xenemy_monster/1_enemies_1_die_006.png \
    images/xenemy_monster/1_enemies_1_die_007.png \
    images/xenemy_monster/1_enemies_1_die_008.png \
    images/xenemy_monster/1_enemies_1_die_009.png \
    images/xenemy_monster/1_enemies_1_die_010.png \
    images/xenemy_monster/1_enemies_1_die_011.png \
    images/xenemy_monster/1_enemies_1_die_012.png \
    images/xenemy_monster/1_enemies_1_die_013.png \
    images/xenemy_monster/1_enemies_1_die_014.png \
    images/xenemy_monster/1_enemies_1_die_015.png \
    images/xenemy_monster/1_enemies_1_die_016.png \
    images/xenemy_monster/1_enemies_1_die_017.png \
    images/xenemy_monster/1_enemies_1_die_018.png \
    images/xenemy_monster/1_enemies_1_die_019.png \
    images/xenemy_monster/1_enemies_1_hurt_000.png \
    images/xenemy_monster/1_enemies_1_hurt_001.png \
    images/xenemy_monster/1_enemies_1_hurt_002.png \
    images/xenemy_monster/1_enemies_1_hurt_003.png \
    images/xenemy_monster/1_enemies_1_hurt_004.png \
    images/xenemy_monster/1_enemies_1_hurt_005.png \
    images/xenemy_monster/1_enemies_1_hurt_006.png \
    images/xenemy_monster/1_enemies_1_hurt_007.png \
    images/xenemy_monster/1_enemies_1_hurt_008.png \
    images/xenemy_monster/1_enemies_1_hurt_009.png \
    images/xenemy_monster/1_enemies_1_hurt_010.png \
    images/xenemy_monster/1_enemies_1_hurt_011.png \
    images/xenemy_monster/1_enemies_1_hurt_012.png \
    images/xenemy_monster/1_enemies_1_hurt_013.png \
    images/xenemy_monster/1_enemies_1_hurt_014.png \
    images/xenemy_monster/1_enemies_1_hurt_015.png \
    images/xenemy_monster/1_enemies_1_hurt_016.png \
    images/xenemy_monster/1_enemies_1_hurt_017.png \
    images/xenemy_monster/1_enemies_1_hurt_018.png \
    images/xenemy_monster/1_enemies_1_hurt_019.png \
    images/xenemy_monster/1_enemies_1_idle_000.png \
    images/xenemy_monster/1_enemies_1_idle_001.png \
    images/xenemy_monster/1_enemies_1_idle_002.png \
    images/xenemy_monster/1_enemies_1_idle_003.png \
    images/xenemy_monster/1_enemies_1_idle_004.png \
    images/xenemy_monster/1_enemies_1_idle_005.png \
    images/xenemy_monster/1_enemies_1_idle_006.png \
    images/xenemy_monster/1_enemies_1_idle_007.png \
    images/xenemy_monster/1_enemies_1_idle_008.png \
    images/xenemy_monster/1_enemies_1_idle_009.png \
    images/xenemy_monster/1_enemies_1_idle_010.png \
    images/xenemy_monster/1_enemies_1_idle_011.png \
    images/xenemy_monster/1_enemies_1_idle_012.png \
    images/xenemy_monster/1_enemies_1_idle_013.png \
    images/xenemy_monster/1_enemies_1_idle_014.png \
    images/xenemy_monster/1_enemies_1_idle_015.png \
    images/xenemy_monster/1_enemies_1_idle_016.png \
    images/xenemy_monster/1_enemies_1_idle_017.png \
    images/xenemy_monster/1_enemies_1_idle_018.png \
    images/xenemy_monster/1_enemies_1_idle_019.png \
    images/xenemy_monster/1_enemies_1_jump_000.png \
    images/xenemy_monster/1_enemies_1_jump_001.png \
    images/xenemy_monster/1_enemies_1_jump_002.png \
    images/xenemy_monster/1_enemies_1_jump_003.png \
    images/xenemy_monster/1_enemies_1_jump_004.png \
    images/xenemy_monster/1_enemies_1_jump_005.png \
    images/xenemy_monster/1_enemies_1_jump_006.png \
    images/xenemy_monster/1_enemies_1_jump_007.png \
    images/xenemy_monster/1_enemies_1_jump_008.png \
    images/xenemy_monster/1_enemies_1_jump_009.png \
    images/xenemy_monster/1_enemies_1_jump_010.png \
    images/xenemy_monster/1_enemies_1_jump_011.png \
    images/xenemy_monster/1_enemies_1_jump_012.png \
    images/xenemy_monster/1_enemies_1_jump_013.png \
    images/xenemy_monster/1_enemies_1_jump_014.png \
    images/xenemy_monster/1_enemies_1_jump_015.png \
    images/xenemy_monster/1_enemies_1_jump_016.png \
    images/xenemy_monster/1_enemies_1_jump_017.png \
    images/xenemy_monster/1_enemies_1_jump_018.png \
    images/xenemy_monster/1_enemies_1_jump_019.png \
    images/xenemy_monster/1_enemies_1_run_000.png \
    images/xenemy_monster/1_enemies_1_run_001.png \
    images/xenemy_monster/1_enemies_1_run_002.png \
    images/xenemy_monster/1_enemies_1_run_003.png \
    images/xenemy_monster/1_enemies_1_run_004.png \
    images/xenemy_monster/1_enemies_1_run_005.png \
    images/xenemy_monster/1_enemies_1_run_006.png \
    images/xenemy_monster/1_enemies_1_run_007.png \
    images/xenemy_monster/1_enemies_1_run_008.png \
    images/xenemy_monster/1_enemies_1_run_009.png \
    images/xenemy_monster/1_enemies_1_run_010.png \
    images/xenemy_monster/1_enemies_1_run_011.png \
    images/xenemy_monster/1_enemies_1_run_012.png \
    images/xenemy_monster/1_enemies_1_run_013.png \
    images/xenemy_monster/1_enemies_1_run_014.png \
    images/xenemy_monster/1_enemies_1_run_015.png \
    images/xenemy_monster/1_enemies_1_run_016.png \
    images/xenemy_monster/1_enemies_1_run_017.png \
    images/xenemy_monster/1_enemies_1_run_018.png \
    images/xenemy_monster/1_enemies_1_run_019.png \
    images/xenemy_monster/1_enemies_1_walk_000.png \
    images/xenemy_monster/1_enemies_1_walk_001.png \
    images/xenemy_monster/1_enemies_1_walk_002.png \
    images/xenemy_monster/1_enemies_1_walk_003.png \
    images/xenemy_monster/1_enemies_1_walk_004.png \
    images/xenemy_monster/1_enemies_1_walk_005.png \
    images/xenemy_monster/1_enemies_1_walk_006.png \
    images/xenemy_monster/1_enemies_1_walk_007.png \
    images/xenemy_monster/1_enemies_1_walk_008.png \
    images/xenemy_monster/1_enemies_1_walk_009.png \
    images/xenemy_monster/1_enemies_1_walk_010.png \
    images/xenemy_monster/1_enemies_1_walk_011.png \
    images/xenemy_monster/1_enemies_1_walk_012.png \
    images/xenemy_monster/1_enemies_1_walk_013.png \
    images/xenemy_monster/1_enemies_1_walk_014.png \
    images/xenemy_monster/1_enemies_1_walk_015.png \
    images/xenemy_monster/1_enemies_1_walk_016.png \
    images/xenemy_monster/1_enemies_1_walk_017.png \
    images/xenemy_monster/1_enemies_1_walk_018.png \
    images/xenemy_monster/1_enemies_1_walk_019.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_000.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_000.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_000.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_000.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_001.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_001.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_001.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_001.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_002.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_002.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_002.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_002.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_003.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_003.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_003.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_003.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_004.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_004.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_004.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_004.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_005.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_005.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_005.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_005.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_006.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_006.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_006.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_006.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_007.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_007.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_007.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_007.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_008.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_008.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_008.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_008.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_009.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_009.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_009.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_009.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_010.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_010.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_010.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_010.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_011.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_011.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_011.png \
    images/xenemy_wraith/PNG Sequences/Attacking/Wraith_03_Attack_011.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_000.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_000.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_000.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_000.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_001.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_001.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_001.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_001.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_002.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_002.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_002.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_002.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_003.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_003.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_003.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_003.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_004.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_004.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_004.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_004.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_005.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_005.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_005.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_005.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_006.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_006.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_006.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_006.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_007.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_007.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_007.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_007.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_008.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_008.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_008.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_008.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_009.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_009.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_009.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_009.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_010.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_010.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_010.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_010.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_011.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_011.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_011.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_011.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_012.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_012.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_012.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_012.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_013.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_013.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_013.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_013.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_014.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_014.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_014.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_014.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_015.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_015.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_015.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_015.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_016.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_016.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_016.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_016.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_017.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_017.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_017.png \
    images/xenemy_wraith/PNG Sequences/Casting Spells/Wraith_03_Casting Spells_017.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_000.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_000.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_000.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_000.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_001.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_001.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_001.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_001.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_002.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_002.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_002.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_002.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_003.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_003.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_003.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_003.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_004.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_004.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_004.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_004.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_005.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_005.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_005.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_005.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_006.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_006.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_006.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_006.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_007.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_007.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_007.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_007.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_008.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_008.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_008.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_008.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_009.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_009.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_009.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_009.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_010.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_010.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_010.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_010.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_011.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_011.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_011.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_011.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_012.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_012.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_012.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_012.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_013.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_013.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_013.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_013.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_014.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_014.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_014.png \
    images/xenemy_wraith/PNG Sequences/Dying/Wraith_03_Dying_014.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_000.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_000.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_000.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_000.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_001.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_001.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_001.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_001.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_002.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_002.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_002.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_002.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_003.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_003.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_003.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_003.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_004.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_004.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_004.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_004.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_005.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_005.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_005.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_005.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_006.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_006.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_006.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_006.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_007.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_007.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_007.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_007.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_008.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_008.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_008.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_008.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_009.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_009.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_009.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_009.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_010.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_010.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_010.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_010.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_011.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_011.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_011.png \
    images/xenemy_wraith/PNG Sequences/Hurt/Wraith_03_Hurt_011.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_000.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_000.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_000.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_000.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_001.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_001.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_001.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_001.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_002.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_002.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_002.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_002.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_003.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_003.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_003.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_003.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_004.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_004.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_004.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_004.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_005.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_005.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_005.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_005.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_006.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_006.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_006.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_006.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_007.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_007.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_007.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_007.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_008.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_008.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_008.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_008.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_009.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_009.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_009.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_009.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_010.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_010.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_010.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_010.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_011.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_011.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_011.png \
    images/xenemy_wraith/PNG Sequences/Idle Blink/Wraith_03_Idle Blinking_011.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_000.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_000.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_000.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_000.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_001.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_001.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_001.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_001.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_002.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_002.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_002.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_002.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_003.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_003.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_003.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_003.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_004.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_004.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_004.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_004.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_005.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_005.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_005.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_005.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_006.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_006.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_006.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_006.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_007.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_007.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_007.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_007.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_008.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_008.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_008.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_008.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_009.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_009.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_009.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_009.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_010.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_010.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_010.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_010.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_011.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_011.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_011.png \
    images/xenemy_wraith/PNG Sequences/Idle/Wraith_03_Idle_011.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_000.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_000.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_000.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_000.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_001.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_001.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_001.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_001.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_002.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_002.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_002.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_002.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_003.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_003.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_003.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_003.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_004.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_004.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_004.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_004.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_005.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_005.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_005.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_005.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_006.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_006.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_006.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_006.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_007.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_007.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_007.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_007.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_008.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_008.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_008.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_008.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_009.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_009.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_009.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_009.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_010.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_010.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_010.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_010.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_011.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_011.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_011.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_011.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_012.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_012.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_012.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_012.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_013.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_013.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_013.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_013.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_014.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_014.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_014.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_014.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_015.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_015.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_015.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_015.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_016.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_016.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_016.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_016.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_017.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_017.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_017.png \
    images/xenemy_wraith/PNG Sequences/Taunt/Wraith_03_Taunt_017.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_000.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_000.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_000.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_000.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_001.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_001.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_001.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_001.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_002.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_002.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_002.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_002.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_003.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_003.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_003.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_003.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_004.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_004.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_004.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_004.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_005.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_005.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_005.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_005.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_006.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_006.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_006.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_006.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_007.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_007.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_007.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_007.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_008.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_008.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_008.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_008.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_009.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_009.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_009.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_009.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_010.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_010.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_010.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_010.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_011.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_011.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_011.png \
    images/xenemy_wraith/PNG Sequences/Walking/Wraith_03_Moving Forward_011.png \
    images/xenemy_wraith/Vector Parts/Animations.scml \
    images/xenemy_wraith/Vector Parts/Animations.scml \
    images/xenemy_wraith/Vector Parts/Animations.scml \
    images/xenemy_wraith/Vector Parts/Animations.scml \
    images/xenemy_wraith/Vector Parts/Body.png \
    images/xenemy_wraith/Vector Parts/Body.png \
    images/xenemy_wraith/Vector Parts/Body.png \
    images/xenemy_wraith/Vector Parts/Body.png \
    images/xenemy_wraith/Vector Parts/Face 01.png \
    images/xenemy_wraith/Vector Parts/Face 01.png \
    images/xenemy_wraith/Vector Parts/Face 01.png \
    images/xenemy_wraith/Vector Parts/Face 01.png \
    images/xenemy_wraith/Vector Parts/Face 02.png \
    images/xenemy_wraith/Vector Parts/Face 02.png \
    images/xenemy_wraith/Vector Parts/Face 02.png \
    images/xenemy_wraith/Vector Parts/Face 02.png \
    images/xenemy_wraith/Vector Parts/Face 03.png \
    images/xenemy_wraith/Vector Parts/Face 03.png \
    images/xenemy_wraith/Vector Parts/Face 03.png \
    images/xenemy_wraith/Vector Parts/Face 03.png \
    images/xenemy_wraith/Vector Parts/Head.png \
    images/xenemy_wraith/Vector Parts/Head.png \
    images/xenemy_wraith/Vector Parts/Head.png \
    images/xenemy_wraith/Vector Parts/Head.png \
    images/xenemy_wraith/Vector Parts/Left Arm.png \
    images/xenemy_wraith/Vector Parts/Left Arm.png \
    images/xenemy_wraith/Vector Parts/Left Arm.png \
    images/xenemy_wraith/Vector Parts/Left Arm.png \
    images/xenemy_wraith/Vector Parts/Left Hand.png \
    images/xenemy_wraith/Vector Parts/Left Hand.png \
    images/xenemy_wraith/Vector Parts/Left Hand.png \
    images/xenemy_wraith/Vector Parts/Left Hand.png \
    images/xenemy_wraith/Vector Parts/Right Arm.png \
    images/xenemy_wraith/Vector Parts/Right Arm.png \
    images/xenemy_wraith/Vector Parts/Right Arm.png \
    images/xenemy_wraith/Vector Parts/Right Arm.png \
    images/xenemy_wraith/Vector Parts/Right Hand.png \
    images/xenemy_wraith/Vector Parts/Right Hand.png \
    images/xenemy_wraith/Vector Parts/Right Hand.png \
    images/xenemy_wraith/Vector Parts/Right Hand.png \
    images/xenemy_wraith/Vector Parts/Spells-Effect.png \
    images/xenemy_wraith/Vector Parts/Spells-Effect.png \
    images/xenemy_wraith/Vector Parts/Spells-Effect.png \
    images/xenemy_wraith/Vector Parts/Spells-Effect.png \
    images/xenemy_wraith_attack/Explosion_1.png \
    images/xenemy_wraith_attack/Explosion_10.png \
    images/xenemy_wraith_attack/Explosion_2.png \
    images/xenemy_wraith_attack/Explosion_3.png \
    images/xenemy_wraith_attack/Explosion_4.png \
    images/xenemy_wraith_attack/Explosion_5.png \
    images/xenemy_wraith_attack/Explosion_6.png \
    images/xenemy_wraith_attack/Explosion_7.png \
    images/xenemy_wraith_attack/Explosion_8.png \
    images/xenemy_wraith_attack/Explosion_9.png \
    library/libworld.so \
    library/libworld.so.1 \
    library/libworld.so.1.0 \
    library/libworld.so.1.0.0

SUBDIRS += \
    world.pro
