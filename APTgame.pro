QT       += core gui
CONFIG += c++17
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
        MainWindow.cpp \
    View/tilegraphicsitem.cpp



HEADERS  += MainWindow.h\
    Controller/ViewController.h \
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
    View/tilegraphicsitem.h

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
#    images/enemy_golem/PNG Sequences/Attack/00.png \
#    images/enemy_golem/PNG Sequences/Attack/01.png \
#    images/enemy_golem/PNG Sequences/Attack/02.png \
#    images/enemy_golem/PNG Sequences/Attack/03.png \
#    images/enemy_golem/PNG Sequences/Attack/04.png \
#    images/enemy_golem/PNG Sequences/Attack/05.png \
#    images/enemy_golem/PNG Sequences/Attack/06.png \
#    images/enemy_golem/PNG Sequences/Attack/07.png \
#    images/enemy_golem/PNG Sequences/Attack/08.png \
#    images/enemy_golem/PNG Sequences/Attack/09.png \
#    images/enemy_golem/PNG Sequences/Attack/10.png \
#    images/enemy_golem/PNG Sequences/Attack/11.png \
#    images/enemy_golem/PNG Sequences/Dying/00.png \
#    images/enemy_golem/PNG Sequences/Dying/01.png \
#    images/enemy_golem/PNG Sequences/Dying/02.png \
#    images/enemy_golem/PNG Sequences/Dying/03.png \
#    images/enemy_golem/PNG Sequences/Dying/04.png \
#    images/enemy_golem/PNG Sequences/Dying/05.png \
#    images/enemy_golem/PNG Sequences/Dying/06.png \
#    images/enemy_golem/PNG Sequences/Dying/07.png \
#    images/enemy_golem/PNG Sequences/Dying/08.png \
#    images/enemy_golem/PNG Sequences/Dying/09.png \
#    images/enemy_golem/PNG Sequences/Dying/10.png \
#    images/enemy_golem/PNG Sequences/Dying/11.png \
#    images/enemy_golem/PNG Sequences/Dying/12.png \
#    images/enemy_golem/PNG Sequences/Dying/13.png \
#    images/enemy_golem/PNG Sequences/Dying/14.png \
#    images/enemy_golem/PNG Sequences/Heal/00.png \
#    images/enemy_golem/PNG Sequences/Heal/01.png \
#    images/enemy_golem/PNG Sequences/Heal/02.png \
#    images/enemy_golem/PNG Sequences/Heal/03.png \
#    images/enemy_golem/PNG Sequences/Heal/04.png \
#    images/enemy_golem/PNG Sequences/Heal/05.png \
#    images/enemy_golem/PNG Sequences/Heal/06.png \
#    images/enemy_golem/PNG Sequences/Heal/07.png \
#    images/enemy_golem/PNG Sequences/Heal/08.png \
#    images/enemy_golem/PNG Sequences/Heal/09.png \
#    images/enemy_golem/PNG Sequences/Heal/10.png \
#    images/enemy_golem/PNG Sequences/Heal/11.png \
#    images/enemy_golem/PNG Sequences/Hurt/00.png \
#    images/enemy_golem/PNG Sequences/Hurt/01.png \
#    images/enemy_golem/PNG Sequences/Hurt/02.png \
#    images/enemy_golem/PNG Sequences/Hurt/03.png \
#    images/enemy_golem/PNG Sequences/Hurt/04.png \
#    images/enemy_golem/PNG Sequences/Hurt/05.png \
#    images/enemy_golem/PNG Sequences/Hurt/06.png \
#    images/enemy_golem/PNG Sequences/Hurt/07.png \
#    images/enemy_golem/PNG Sequences/Hurt/08.png \
#    images/enemy_golem/PNG Sequences/Hurt/09.png \
#    images/enemy_golem/PNG Sequences/Hurt/10.png \
#    images/enemy_golem/PNG Sequences/Hurt/11.png \
#    images/enemy_golem/PNG Sequences/Idle/00.png \
#    images/enemy_golem/PNG Sequences/Idle/01.png \
#    images/enemy_golem/PNG Sequences/Idle/02.png \
#    images/enemy_golem/PNG Sequences/Idle/03.png \
#    images/enemy_golem/PNG Sequences/Idle/04.png \
#    images/enemy_golem/PNG Sequences/Idle/05.png \
#    images/enemy_golem/PNG Sequences/Idle/06.png \
#    images/enemy_golem/PNG Sequences/Idle/07.png \
#    images/enemy_golem/PNG Sequences/Idle/08.png \
#    images/enemy_golem/PNG Sequences/Idle/09.png \
#    images/enemy_golem/PNG Sequences/Idle/10.png \
#    images/enemy_golem/PNG Sequences/Idle/11.png \
#    images/enemy_golem/PNG Sequences/Jump Loop/00.png \
#    images/enemy_golem/PNG Sequences/Jump Loop/01.png \
#    images/enemy_golem/PNG Sequences/Jump Loop/02.png \
#    images/enemy_golem/PNG Sequences/Jump Loop/03.png \
#    images/enemy_golem/PNG Sequences/Jump Loop/04.png \
#    images/enemy_golem/PNG Sequences/Jump Loop/05.png \
#    images/enemy_golem/PNG Sequences/Jump Start/00.png \
#    images/enemy_golem/PNG Sequences/Jump Start/01.png \
#    images/enemy_golem/PNG Sequences/Jump Start/02.png \
#    images/enemy_golem/PNG Sequences/Jump Start/03.png \
#    images/enemy_golem/PNG Sequences/Jump Start/04.png \
#    images/enemy_golem/PNG Sequences/Jump Start/05.png \
#    images/enemy_golem/PNG Sequences/Taunt/00.png \
#    images/enemy_golem/PNG Sequences/Taunt/01.png \
#    images/enemy_golem/PNG Sequences/Taunt/02.png \
#    images/enemy_golem/PNG Sequences/Taunt/03.png \
#    images/enemy_golem/PNG Sequences/Taunt/04.png \
#    images/enemy_golem/PNG Sequences/Taunt/05.png \
#    images/enemy_golem/PNG Sequences/Taunt/06.png \
#    images/enemy_golem/PNG Sequences/Taunt/07.png \
#    images/enemy_golem/PNG Sequences/Taunt/08.png \
#    images/enemy_golem/PNG Sequences/Taunt/09.png \
#    images/enemy_golem/PNG Sequences/Taunt/10.png \
#    images/enemy_golem/PNG Sequences/Taunt/11.png \
#    images/enemy_golem/PNG Sequences/Taunt/12.png \
#    images/enemy_golem/PNG Sequences/Taunt/13.png \
#    images/enemy_golem/PNG Sequences/Taunt/14.png \
#    images/enemy_golem/PNG Sequences/Taunt/15.png \
#    images/enemy_golem/PNG Sequences/Taunt/16.png \
#    images/enemy_golem/PNG Sequences/Taunt/17.png \
#    images/enemy_golem/PNG Sequences/Walking/00.png \
#    images/enemy_golem/PNG Sequences/Walking/01.png \
#    images/enemy_golem/PNG Sequences/Walking/02.png \
#    images/enemy_golem/PNG Sequences/Walking/03.png \
#    images/enemy_golem/PNG Sequences/Walking/04.png \
#    images/enemy_golem/PNG Sequences/Walking/05.png \
#    images/enemy_golem/PNG Sequences/Walking/06.png \
#    images/enemy_golem/PNG Sequences/Walking/07.png \
#    images/enemy_golem/PNG Sequences/Walking/08.png \
#    images/enemy_golem/PNG Sequences/Walking/09.png \
#    images/enemy_golem/PNG Sequences/Walking/10.png \
#    images/enemy_golem/PNG Sequences/Walking/11.png \
#    images/enemy_golem/PNG Sequences/Walking/12.png \
#    images/enemy_golem/PNG Sequences/Walking/13.png \
#    images/enemy_golem/PNG Sequences/Walking/14.png \
#    images/enemy_golem/PNG Sequences/Walking/15.png \
#    images/enemy_golem/PNG Sequences/Walking/16.png \
#    images/enemy_golem/PNG Sequences/Walking/17.png \
#    images/enemy_golem/Vector Parts/Animations.scml \
#    images/enemy_golem/Vector Parts/Body.png \
#    images/enemy_golem/Vector Parts/Face 01.png \
#    images/enemy_golem/Vector Parts/Face 02.png \
#    images/enemy_golem/Vector Parts/Face 03.png \
#    images/enemy_golem/Vector Parts/Head.png \
#    images/enemy_golem/Vector Parts/Left Arm.png \
#    images/enemy_golem/Vector Parts/Left Hand.png \
#    images/enemy_golem/Vector Parts/Left Leg.png \
#    images/enemy_golem/Vector Parts/Right Arm.png \
#    images/enemy_golem/Vector Parts/Right Hand.png \
#    images/enemy_golem/Vector Parts/Right Leg.png \
#    images/enemy_golem/Vector Parts/Weapon.png \
#    images/enemy_golem_attack/01.png \
#    images/enemy_golem_attack/02.png \
#    images/enemy_golem_attack/03.png \
#    images/enemy_golem_attack/04.png \
#    images/enemy_golem_attack/05.png \
#    images/enemy_golem_attack/06.png \
#    images/enemy_golem_attack/07.png \
#    images/enemy_golem_attack/08.png \
#    images/enemy_golem_attack/09.png \
#    images/enemy_golem_attack/10.png \
#    images/fixed_attack_direction/PNG/00.png \
#    images/fixed_attack_direction/PNG/01.png \
#    images/fixed_attack_direction/PNG/02.png \
#    images/fixed_attack_direction/PNG/03.png \
#    images/fixed_attack_direction/PNG/04.png \
#    images/fixed_attack_direction/PNG/05.png \
#    images/fixed_attack_direction/PNG/06.png \
#    images/fixed_attack_direction/PNG/07.png \
#    images/fixed_attack_direction/PNG/08.png \
#    images/fixed_attack_direction/PNG/09.png \
#    images/fixed_attack_direction/PNG/10.png \
#    images/fixed_attack_direction/PNG/11.png \
#    images/fixed_attack_direction/PNG/12.png \
#    images/fixed_attack_direction/PNG/13.png \
#    images/fixed_attack_direction/PNG/14.png \
#    images/fixed_attack_direction/PNG/15.png \
#    images/fixed_attack_direction/PNG/16.png \
#    images/fixed_attack_direction/PNG/17.png \
#    images/fixed_attack_direction/PNG/18.png \
#    images/fixed_attack_direction/PNG/19.png \
#    images/fixed_attack_direction/PNG/20.png \
#    images/fixed_attack_direction/PNG/21.png \
#    images/fixed_attack_direction/PNG/22.png \
#    images/fixed_attack_direction/PNG/23.png \
#    images/fixed_attack_direction/PNG/24.png \
#    images/fixed_attack_direction/PNG/25.png \
#    images/fixed_attack_direction/PNG/26.png \
#    images/fixed_attack_direction/PNG/27.png \
#    images/fixed_attack_direction/PNG/28.png \
#    images/fixed_attack_direction/PNG/29.png \
#    images/fixed_attack_direction/PNG/30.png \
#    images/fixed_attack_direction/PNG/31.png \
#    images/fixed_attack_direction/PNG/32.png \
#    images/fixed_attack_direction/PNG/33.png \
#    images/fixed_attack_direction/PNG/34.png \
#    images/fixed_attack_direction/PNG/35.png \
#    images/fixed_attack_direction/PNG/36.png \
#    images/fixed_attack_direction/PNG/37.png \
#    images/fixed_attack_direction/PNG/38.png \
#    images/fixed_attack_direction/PNG/39.png \
#    images/fixed_attack_direction/PNG/40.png \
#    images/fixed_attack_direction/SPINE/02.png \
#    images/fixed_attack_direction/SPINE/03.png \
#    images/fixed_attack_direction/SPINE/04.png \
#    images/fixed_attack_direction/SPINE/10.png \
#    images/fixed_attack_direction/SPINE/flame10.atlas.txt \
#    images/fixed_attack_direction/SPINE/flame10.json \
#    images/fixed_attack_direction/gif demo.gif \
#    images/fixed_attack_direction/images/02.png \
#    images/fixed_attack_direction/images/03.png \
#    images/fixed_attack_direction/images/04.png \
#    images/fixed_attack_direction/images/05.png \
#    images/fixed_attack_direction/images/06.png \
#    images/fixed_attack_direction/images/07.png \
#    images/fixed_attack_direction/images/08.png \
#    images/fixed_attack_direction/images/09.png \
#    images/fixed_attack_direction/images/10.png \
#    images/fixed_attack_direction/images/11.png \
#    images/fixed_attack_direction/images/12.png \
#    images/fixed_attack_direction/images/13.png \
#    images/fixed_attack_direction/images/14.png \
#    images/fixed_attack_direction/images/15.png \
#    images/fixed_attack_direction/images/16.png \
#    images/fixed_attack_direction/images/17.png \
#    images/fixed_attack_direction/images/18.png \
#    images/fixed_attack_direction/images/19.png \
#    images/fixed_attack_direction/images/20.png \
#    images/fixed_attack_direction/images/21.png \
#    images/fixed_attack_direction/images/22.png \
#    images/fixed_attack_direction/images/23.png \
#    images/fixed_attack_direction/images/24.png \
#    images/fixed_attack_direction/images/25.png \
#    images/fixed_attack_direction/images/26.png \
#    images/fixed_attack_direction/images/27.png \
#    images/fixed_attack_direction/images/28.png \
#    images/fixed_attack_direction/images/29.png \
#    images/fixed_attack_direction/images/h2.png \
#    images/fixed_attack_direction/images/ht.png \
#    images/fixed_attack_direction/images/uh.png \
#    images/fixed_attack_direction/images/vjuh.json \
#    images/healthpack/1.png \
#    images/healthpack/2.png \
#    images/healthpack/3.png \
#    images/healthpack/4.png \
#    images/healthpack/5.png \
#    images/healthpack/6.png \
#    images/penemy_wraith/PNG Sequences/Attacking/00.png \
#    images/penemy_wraith/PNG Sequences/Attacking/01.png \
#    images/penemy_wraith/PNG Sequences/Attacking/02.png \
#    images/penemy_wraith/PNG Sequences/Attacking/03.png \
#    images/penemy_wraith/PNG Sequences/Attacking/04.png \
#    images/penemy_wraith/PNG Sequences/Attacking/05.png \
#    images/penemy_wraith/PNG Sequences/Attacking/06.png \
#    images/penemy_wraith/PNG Sequences/Attacking/07.png \
#    images/penemy_wraith/PNG Sequences/Attacking/08.png \
#    images/penemy_wraith/PNG Sequences/Attacking/09.png \
#    images/penemy_wraith/PNG Sequences/Attacking/10.png \
#    images/penemy_wraith/PNG Sequences/Attacking/11.png \
#    images/penemy_wraith/PNG Sequences/Casting Spells/00.png \
#    images/penemy_wraith/PNG Sequences/Casting Spells/01.png \
#    images/penemy_wraith/PNG Sequences/Casting Spells/02.png \
#    images/penemy_wraith/PNG Sequences/Casting Spells/03.png \
#    images/penemy_wraith/PNG Sequences/Casting Spells/04.png \
#    images/penemy_wraith/PNG Sequences/Casting Spells/05.png \
#    images/penemy_wraith/PNG Sequences/Casting Spells/06.png \
#    images/penemy_wraith/PNG Sequences/Casting Spells/07.png \
#    images/penemy_wraith/PNG Sequences/Casting Spells/08.png \
#    images/penemy_wraith/PNG Sequences/Casting Spells/09.png \
#    images/penemy_wraith/PNG Sequences/Casting Spells/10.png \
#    images/penemy_wraith/PNG Sequences/Casting Spells/11.png \
#    images/penemy_wraith/PNG Sequences/Casting Spells/12.png \
#    images/penemy_wraith/PNG Sequences/Casting Spells/13.png \
#    images/penemy_wraith/PNG Sequences/Casting Spells/14.png \
#    images/penemy_wraith/PNG Sequences/Casting Spells/15.png \
#    images/penemy_wraith/PNG Sequences/Casting Spells/16.png \
#    images/penemy_wraith/PNG Sequences/Casting Spells/17.png \
#    images/penemy_wraith/PNG Sequences/Dying/00.png \
#    images/penemy_wraith/PNG Sequences/Dying/01.png \
#    images/penemy_wraith/PNG Sequences/Dying/02.png \
#    images/penemy_wraith/PNG Sequences/Dying/03.png \
#    images/penemy_wraith/PNG Sequences/Dying/04.png \
#    images/penemy_wraith/PNG Sequences/Dying/05.png \
#    images/penemy_wraith/PNG Sequences/Dying/06.png \
#    images/penemy_wraith/PNG Sequences/Dying/07.png \
#    images/penemy_wraith/PNG Sequences/Dying/08.png \
#    images/penemy_wraith/PNG Sequences/Dying/09.png \
#    images/penemy_wraith/PNG Sequences/Dying/10.png \
#    images/penemy_wraith/PNG Sequences/Dying/11.png \
#    images/penemy_wraith/PNG Sequences/Dying/12.png \
#    images/penemy_wraith/PNG Sequences/Dying/13.png \
#    images/penemy_wraith/PNG Sequences/Dying/14.png \
#    images/penemy_wraith/PNG Sequences/Hurt/00.png \
#    images/penemy_wraith/PNG Sequences/Hurt/01.png \
#    images/penemy_wraith/PNG Sequences/Hurt/02.png \
#    images/penemy_wraith/PNG Sequences/Hurt/03.png \
#    images/penemy_wraith/PNG Sequences/Hurt/04.png \
#    images/penemy_wraith/PNG Sequences/Hurt/05.png \
#    images/penemy_wraith/PNG Sequences/Hurt/06.png \
#    images/penemy_wraith/PNG Sequences/Hurt/07.png \
#    images/penemy_wraith/PNG Sequences/Hurt/08.png \
#    images/penemy_wraith/PNG Sequences/Hurt/09.png \
#    images/penemy_wraith/PNG Sequences/Hurt/10.png \
#    images/penemy_wraith/PNG Sequences/Hurt/11.png \
#    images/penemy_wraith/PNG Sequences/Idle Blink/00.png \
#    images/penemy_wraith/PNG Sequences/Idle Blink/01.png \
#    images/penemy_wraith/PNG Sequences/Idle Blink/02.png \
#    images/penemy_wraith/PNG Sequences/Idle Blink/03.png \
#    images/penemy_wraith/PNG Sequences/Idle Blink/04.png \
#    images/penemy_wraith/PNG Sequences/Idle Blink/05.png \
#    images/penemy_wraith/PNG Sequences/Idle Blink/06.png \
#    images/penemy_wraith/PNG Sequences/Idle Blink/07.png \
#    images/penemy_wraith/PNG Sequences/Idle Blink/08.png \
#    images/penemy_wraith/PNG Sequences/Idle Blink/09.png \
#    images/penemy_wraith/PNG Sequences/Idle Blink/10.png \
#    images/penemy_wraith/PNG Sequences/Idle Blink/11.png \
#    images/penemy_wraith/PNG Sequences/Idle/00.png \
#    images/penemy_wraith/PNG Sequences/Idle/01.png \
#    images/penemy_wraith/PNG Sequences/Idle/02.png \
#    images/penemy_wraith/PNG Sequences/Idle/03.png \
#    images/penemy_wraith/PNG Sequences/Idle/04.png \
#    images/penemy_wraith/PNG Sequences/Idle/05.png \
#    images/penemy_wraith/PNG Sequences/Idle/06.png \
#    images/penemy_wraith/PNG Sequences/Idle/07.png \
#    images/penemy_wraith/PNG Sequences/Idle/08.png \
#    images/penemy_wraith/PNG Sequences/Idle/09.png \
#    images/penemy_wraith/PNG Sequences/Idle/10.png \
#    images/penemy_wraith/PNG Sequences/Idle/11.png \
#    images/penemy_wraith/PNG Sequences/Taunt/00.png \
#    images/penemy_wraith/PNG Sequences/Taunt/01.png \
#    images/penemy_wraith/PNG Sequences/Taunt/02.png \
#    images/penemy_wraith/PNG Sequences/Taunt/03.png \
#    images/penemy_wraith/PNG Sequences/Taunt/04.png \
#    images/penemy_wraith/PNG Sequences/Taunt/05.png \
#    images/penemy_wraith/PNG Sequences/Taunt/06.png \
#    images/penemy_wraith/PNG Sequences/Taunt/07.png \
#    images/penemy_wraith/PNG Sequences/Taunt/08.png \
#    images/penemy_wraith/PNG Sequences/Taunt/09.png \
#    images/penemy_wraith/PNG Sequences/Taunt/10.png \
#    images/penemy_wraith/PNG Sequences/Taunt/11.png \
#    images/penemy_wraith/PNG Sequences/Taunt/12.png \
#    images/penemy_wraith/PNG Sequences/Taunt/13.png \
#    images/penemy_wraith/PNG Sequences/Taunt/14.png \
#    images/penemy_wraith/PNG Sequences/Taunt/15.png \
#    images/penemy_wraith/PNG Sequences/Taunt/16.png \
#    images/penemy_wraith/PNG Sequences/Taunt/17.png \
#    images/penemy_wraith/PNG Sequences/Walking/00.png \
#    images/penemy_wraith/PNG Sequences/Walking/01.png \
#    images/penemy_wraith/PNG Sequences/Walking/02.png \
#    images/penemy_wraith/PNG Sequences/Walking/03.png \
#    images/penemy_wraith/PNG Sequences/Walking/04.png \
#    images/penemy_wraith/PNG Sequences/Walking/05.png \
#    images/penemy_wraith/PNG Sequences/Walking/06.png \
#    images/penemy_wraith/PNG Sequences/Walking/07.png \
#    images/penemy_wraith/PNG Sequences/Walking/08.png \
#    images/penemy_wraith/PNG Sequences/Walking/09.png \
#    images/penemy_wraith/PNG Sequences/Walking/10.png \
#    images/penemy_wraith/PNG Sequences/Walking/11.png \
#    images/penemy_wraith/Vector Parts/Animations.scml \
#    images/penemy_wraith/Vector Parts/Body.png \
#    images/penemy_wraith/Vector Parts/Face 01.png \
#    images/penemy_wraith/Vector Parts/Face 02.png \
#    images/penemy_wraith/Vector Parts/Face 03.png \
#    images/penemy_wraith/Vector Parts/Head.png \
#    images/penemy_wraith/Vector Parts/Left Arm.png \
#    images/penemy_wraith/Vector Parts/Left Hand.png \
#    images/penemy_wraith/Vector Parts/Right Arm.png \
#    images/penemy_wraith/Vector Parts/Right Hand.png \
#    images/penemy_wraith/Vector Parts/Spells Effect.png \
#    images/penemy_wraith_poison/1.png \
#    images/penemy_wraith_poison/10.png \
#    images/penemy_wraith_poison/2.png \
#    images/penemy_wraith_poison/3.png \
#    images/penemy_wraith_poison/4.png \
#    images/penemy_wraith_poison/5.png \
#    images/penemy_wraith_poison/6.png \
#    images/penemy_wraith_poison/7.png \
#    images/penemy_wraith_poison/8.png \
#    images/penemy_wraith_poison/9.png \
#    images/protagonist_fighter/Attack/01.png \
#    images/protagonist_fighter/Attack/02.png \
#    images/protagonist_fighter/Attack/03.png \
#    images/protagonist_fighter/Dying/01.png \
#    images/protagonist_fighter/Hurt/01.png \
#    images/protagonist_fighter/Idle/01.png \
#    images/protagonist_fighter/Jump.png \
#    images/protagonist_fighter/Run.png \
#    images/protagonist_fighter/Shield.png \
#    images/protagonist_fighter/Walking/01.png \
#    images/protagonist_heal/1.png \
#    images/protagonist_heal/10.png \
#    images/protagonist_heal/2.png \
#    images/protagonist_heal/3.png \
#    images/protagonist_heal/4.png \
#    images/protagonist_heal/5.png \
#    images/protagonist_heal/6.png \
#    images/protagonist_heal/7.png \
#    images/protagonist_heal/8.png \
#    images/protagonist_heal/9.png \
#    images/protagonist_samurai/Attack_1.png \
#    images/protagonist_samurai/Attack_2.png \
#    images/protagonist_samurai/Attack_3.png \
#    images/protagonist_samurai/Dead.png \
#    images/protagonist_samurai/Hurt.png \
#    images/protagonist_samurai/Idle.png \
#    images/protagonist_samurai/Jump.png \
#    images/protagonist_samurai/Run.png \
#    images/protagonist_samurai/Shield.png \
#    images/protagonist_samurai/Walk.png \
#    images/protagonist_shinobi/Attack_1.png \
#    images/protagonist_shinobi/Attack_2.png \
#    images/protagonist_shinobi/Attack_3.png \
#    images/protagonist_shinobi/Dead.png \
#    images/protagonist_shinobi/Hurt.png \
#    images/protagonist_shinobi/Idle.png \
#    images/protagonist_shinobi/Jump.png \
#    images/protagonist_shinobi/Run.png \
#    images/protagonist_shinobi/Shield.png \
#    images/protagonist_shinobi/Walk.png \
#    images/world_images/maze1.png \
#    images/world_images/maze2.png \
#    images/world_images/maze3.png \
#    images/world_images/worldmap.png \
#    images/world_images/worldmap4.png \
#    images/xenemy_monster/00.png \
#    images/xenemy_monster/01.png \
#    images/xenemy_monster/02.png \
#    images/xenemy_monster/03.png \
#    images/xenemy_monster/04.png \
#    images/xenemy_monster/05.png \
#    images/xenemy_monster/06.png \
#    images/xenemy_monster/07.png \
#    images/xenemy_monster/08.png \
#    images/xenemy_monster/09.png \
#    images/xenemy_monster/10.png \
#    images/xenemy_monster/11.png \
#    images/xenemy_monster/12.png \
#    images/xenemy_monster/13.png \
#    images/xenemy_monster/14.png \
#    images/xenemy_monster/15.png \
#    images/xenemy_monster/16.png \
#    images/xenemy_monster/17.png \
#    images/xenemy_monster/18.png \
#    images/xenemy_monster/19.png \
#    images/xenemy_wraith/PNG Sequences/Attacking/00.png \
#    images/xenemy_wraith/PNG Sequences/Attacking/01.png \
#    images/xenemy_wraith/PNG Sequences/Attacking/02.png \
#    images/xenemy_wraith/PNG Sequences/Attacking/03.png \
#    images/xenemy_wraith/PNG Sequences/Attacking/04.png \
#    images/xenemy_wraith/PNG Sequences/Attacking/05.png \
#    images/xenemy_wraith/PNG Sequences/Attacking/06.png \
#    images/xenemy_wraith/PNG Sequences/Attacking/07.png \
#    images/xenemy_wraith/PNG Sequences/Attacking/08.png \
#    images/xenemy_wraith/PNG Sequences/Attacking/09.png \
#    images/xenemy_wraith/PNG Sequences/Attacking/10.png \
#    images/xenemy_wraith/PNG Sequences/Attacking/11.png \
#    images/xenemy_wraith/PNG Sequences/Casting Spells/00.png \
#    images/xenemy_wraith/PNG Sequences/Casting Spells/01.png \
#    images/xenemy_wraith/PNG Sequences/Casting Spells/02.png \
#    images/xenemy_wraith/PNG Sequences/Casting Spells/03.png \
#    images/xenemy_wraith/PNG Sequences/Casting Spells/04.png \
#    images/xenemy_wraith/PNG Sequences/Casting Spells/05.png \
#    images/xenemy_wraith/PNG Sequences/Casting Spells/06.png \
#    images/xenemy_wraith/PNG Sequences/Casting Spells/07.png \
#    images/xenemy_wraith/PNG Sequences/Casting Spells/08.png \
#    images/xenemy_wraith/PNG Sequences/Casting Spells/09.png \
#    images/xenemy_wraith/PNG Sequences/Casting Spells/10.png \
#    images/xenemy_wraith/PNG Sequences/Casting Spells/11.png \
#    images/xenemy_wraith/PNG Sequences/Casting Spells/12.png \
#    images/xenemy_wraith/PNG Sequences/Casting Spells/13.png \
#    images/xenemy_wraith/PNG Sequences/Casting Spells/14.png \
#    images/xenemy_wraith/PNG Sequences/Casting Spells/15.png \
#    images/xenemy_wraith/PNG Sequences/Casting Spells/16.png \
#    images/xenemy_wraith/PNG Sequences/Casting Spells/17.png \
#    images/xenemy_wraith/PNG Sequences/Dying/00.png \
#    images/xenemy_wraith/PNG Sequences/Dying/01.png \
#    images/xenemy_wraith/PNG Sequences/Dying/02.png \
#    images/xenemy_wraith/PNG Sequences/Dying/03.png \
#    images/xenemy_wraith/PNG Sequences/Dying/04.png \
#    images/xenemy_wraith/PNG Sequences/Dying/05.png \
#    images/xenemy_wraith/PNG Sequences/Dying/06.png \
#    images/xenemy_wraith/PNG Sequences/Dying/07.png \
#    images/xenemy_wraith/PNG Sequences/Dying/08.png \
#    images/xenemy_wraith/PNG Sequences/Dying/09.png \
#    images/xenemy_wraith/PNG Sequences/Dying/10.png \
#    images/xenemy_wraith/PNG Sequences/Dying/11.png \
#    images/xenemy_wraith/PNG Sequences/Dying/12.png \
#    images/xenemy_wraith/PNG Sequences/Dying/13.png \
#    images/xenemy_wraith/PNG Sequences/Dying/14.png \
#    images/xenemy_wraith/PNG Sequences/Hurt/00.png \
#    images/xenemy_wraith/PNG Sequences/Hurt/01.png \
#    images/xenemy_wraith/PNG Sequences/Hurt/02.png \
#    images/xenemy_wraith/PNG Sequences/Hurt/03.png \
#    images/xenemy_wraith/PNG Sequences/Hurt/04.png \
#    images/xenemy_wraith/PNG Sequences/Hurt/05.png \
#    images/xenemy_wraith/PNG Sequences/Hurt/06.png \
#    images/xenemy_wraith/PNG Sequences/Hurt/07.png \
#    images/xenemy_wraith/PNG Sequences/Hurt/08.png \
#    images/xenemy_wraith/PNG Sequences/Hurt/09.png \
#    images/xenemy_wraith/PNG Sequences/Hurt/10.png \
#    images/xenemy_wraith/PNG Sequences/Hurt/11.png \
#    images/xenemy_wraith/PNG Sequences/Idle Blink/00.png \
#    images/xenemy_wraith/PNG Sequences/Idle Blink/01.png \
#    images/xenemy_wraith/PNG Sequences/Idle Blink/02.png \
#    images/xenemy_wraith/PNG Sequences/Idle Blink/03.png \
#    images/xenemy_wraith/PNG Sequences/Idle Blink/04.png \
#    images/xenemy_wraith/PNG Sequences/Idle Blink/05.png \
#    images/xenemy_wraith/PNG Sequences/Idle Blink/06.png \
#    images/xenemy_wraith/PNG Sequences/Idle Blink/07.png \
#    images/xenemy_wraith/PNG Sequences/Idle Blink/08.png \
#    images/xenemy_wraith/PNG Sequences/Idle Blink/09.png \
#    images/xenemy_wraith/PNG Sequences/Idle Blink/10.png \
#    images/xenemy_wraith/PNG Sequences/Idle Blink/11.png \
#    images/xenemy_wraith/PNG Sequences/Idle/00.png \
#    images/xenemy_wraith/PNG Sequences/Idle/01.png \
#    images/xenemy_wraith/PNG Sequences/Idle/02.png \
#    images/xenemy_wraith/PNG Sequences/Idle/03.png \
#    images/xenemy_wraith/PNG Sequences/Idle/04.png \
#    images/xenemy_wraith/PNG Sequences/Idle/05.png \
#    images/xenemy_wraith/PNG Sequences/Idle/06.png \
#    images/xenemy_wraith/PNG Sequences/Idle/07.png \
#    images/xenemy_wraith/PNG Sequences/Idle/08.png \
#    images/xenemy_wraith/PNG Sequences/Idle/09.png \
#    images/xenemy_wraith/PNG Sequences/Idle/10.png \
#    images/xenemy_wraith/PNG Sequences/Idle/11.png \
#    images/xenemy_wraith/PNG Sequences/Taunt/00.png \
#    images/xenemy_wraith/PNG Sequences/Taunt/01.png \
#    images/xenemy_wraith/PNG Sequences/Taunt/02.png \
#    images/xenemy_wraith/PNG Sequences/Taunt/03.png \
#    images/xenemy_wraith/PNG Sequences/Taunt/04.png \
#    images/xenemy_wraith/PNG Sequences/Taunt/05.png \
#    images/xenemy_wraith/PNG Sequences/Taunt/06.png \
#    images/xenemy_wraith/PNG Sequences/Taunt/07.png \
#    images/xenemy_wraith/PNG Sequences/Taunt/08.png \
#    images/xenemy_wraith/PNG Sequences/Taunt/09.png \
#    images/xenemy_wraith/PNG Sequences/Taunt/10.png \
#    images/xenemy_wraith/PNG Sequences/Taunt/11.png \
#    images/xenemy_wraith/PNG Sequences/Taunt/12.png \
#    images/xenemy_wraith/PNG Sequences/Taunt/13.png \
#    images/xenemy_wraith/PNG Sequences/Taunt/14.png \
#    images/xenemy_wraith/PNG Sequences/Taunt/15.png \
#    images/xenemy_wraith/PNG Sequences/Taunt/16.png \
#    images/xenemy_wraith/PNG Sequences/Taunt/17.png \
#    images/xenemy_wraith/PNG Sequences/Walking/00.png \
#    images/xenemy_wraith/PNG Sequences/Walking/01.png \
#    images/xenemy_wraith/PNG Sequences/Walking/02.png \
#    images/xenemy_wraith/PNG Sequences/Walking/03.png \
#    images/xenemy_wraith/PNG Sequences/Walking/04.png \
#    images/xenemy_wraith/PNG Sequences/Walking/05.png \
#    images/xenemy_wraith/PNG Sequences/Walking/06.png \
#    images/xenemy_wraith/PNG Sequences/Walking/07.png \
#    images/xenemy_wraith/PNG Sequences/Walking/08.png \
#    images/xenemy_wraith/PNG Sequences/Walking/09.png \
#    images/xenemy_wraith/PNG Sequences/Walking/10.png \
#    images/xenemy_wraith/PNG Sequences/Walking/11.png \
#    images/xenemy_wraith/Vector Parts/Animations.scml \
#    images/xenemy_wraith/Vector Parts/Body.png \
#    images/xenemy_wraith/Vector Parts/Face 01.png \
#    images/xenemy_wraith/Vector Parts/Face 02.png \
#    images/xenemy_wraith/Vector Parts/Face 03.png \
#    images/xenemy_wraith/Vector Parts/Head.png \
#    images/xenemy_wraith/Vector Parts/Left Arm.png \
#    images/xenemy_wraith/Vector Parts/Left Hand.png \
#    images/xenemy_wraith/Vector Parts/Right Arm.png \
#    images/xenemy_wraith/Vector Parts/Right Hand.png \
#    images/xenemy_wraith/Vector Parts/Spells-Effect.png \
#    images/xenemy_wraith_attack/1.png \
#    images/xenemy_wraith_attack/10.png \
#    images/xenemy_wraith_attack/2.png \
#    images/xenemy_wraith_attack/3.png \
#    images/xenemy_wraith_attack/4.png \
#    images/xenemy_wraith_attack/5.png \
#    images/xenemy_wraith_attack/6.png \
#    images/xenemy_wraith_attack/7.png \
#    images/xenemy_wraith_attack/8.png \
#    images/xenemy_wraith_attack/9.png \
    library/libworld.so \
    library/libworld.so.1 \
    library/libworld.so.1.0 \
    library/libworld.so.1.0.0

SUBDIRS += \
    world.pro
