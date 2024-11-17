QT       += sql
QT += axcontainer
QT += printsupport
QT += core gui charts
QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chatbot.cpp \
    connection.cpp \
    dialog.cpp \
    gestionproduit.cpp \
    main.cpp \
    mainwindow.cpp \
    produit.cpp

HEADERS += \
    chatbot.h \
    connection.h \
    dialog.h \
    gestionproduit.h \
    mainwindow.h \
    produit.h

FORMS += \
    chatbot.ui \
    dialog.ui \
    gestionproduit.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
