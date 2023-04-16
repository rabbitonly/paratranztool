QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    exporter.cpp \
    importer.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    exporter.h \
    importer.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    paratranz_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

RC_ICONS = img/logo.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../renpy/release/ -lrenpy
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../renpy/debug/ -lrenpy
else:unix: LIBS += -L$$OUT_PWD/../renpy/ -lrenpy

INCLUDEPATH += $$PWD/../renpy
DEPENDPATH += $$PWD/../renpy

RESOURCES += \
    rc.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../data/release/ -ldata
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../data/debug/ -ldata
else:unix: LIBS += -L$$OUT_PWD/../data/ -ldata

INCLUDEPATH += $$PWD/../data
DEPENDPATH += $$PWD/../data
