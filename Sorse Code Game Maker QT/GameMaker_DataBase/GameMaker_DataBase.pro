QT += core gui sql
RC_FILE = exe_icon.rc

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    C_L_LE_Add.cpp \
    main.cpp \
    window.cpp

HEADERS += \
    C_L_LE_Add.h \
    window.h

FORMS += \
    window.ui

TRANSLATIONS += \
    GameMaker_DataBase_fa_IR.ts
CONFIG += lrelease
CONFIG += embed_translations

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Picther.qrc
