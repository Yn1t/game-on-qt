QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bridge.cpp \
    custom_scene.cpp \
    forest.cpp \
    invisible_wall.cpp \
    main.cpp \
    mainwindow.cpp \
    object.cpp \
    sprite_hero.cpp \
    static_object.cpp \
    triangle.cpp

HEADERS += \
    bridge.h \
    custom_scene.h \
    forest.h \
    invisible_wall.h \
    mainwindow.h \
    object.h \
    sprite_hero.h \
    static_object.h \
    triangle.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    Game_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
