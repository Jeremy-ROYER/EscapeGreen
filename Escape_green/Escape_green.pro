QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    decode.cpp \
    decode_fruits.cpp \
    main.cpp \
    mainwindow.cpp \
    room_1.cpp \
    room_2.cpp \
    trie_dechets.cpp \
    trie_fruits.cpp

HEADERS += \
    decode.h \
    decode_fruits.h \
    game.h \
    mainwindow.h \
    room.h \
    room_1.h \
    room_2.h \
    trie_dechets.h \
    trie_fruits.h \
    trie_game.h

FORMS += \
    decode.ui \
    decode_fruits.ui \
    mainwindow.ui \
    room_1.ui \
    room_2.ui \
    trie_dechets.ui \
    trie_fruits.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
