QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    contentsegment.cpp \
    grouppanel.cpp \
    leftpanel.cpp \
    main.cpp \
    mainwindow.cpp \
    optionspanel.cpp \
    sortpanel.cpp \
    topbar.cpp

HEADERS += \
    contentsegment.h \
    grouppanel.h \
    leftpanel.h \
    mainwindow.h \
    optionspanel.h \
    sortpanel.h \
    topbar.h \
    ui_contentsegment.h \
    ui_grouppanel.h \
    ui_leftpanel.h \
    ui_mainwindow.h \
    ui_optionspanel.h \
    ui_sortpanel.h \
    ui_topbar.h

TRANSLATIONS += \
    FileOrganizer_pl_PL.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rss.qrc
