QT       += core gui
QT += sql
QT += core gui widgets sql printsupport
QT += core gui widgets sql charts
QT += charts
QT       += core gui sql
QT       += widgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    fenetrehistorique.cpp \
    fournisseur.cpp \
    main.cpp \
    mainwindow.cpp \
    qr_code.cpp \
    qr_code1.cpp \
    statistique.cpp

HEADERS += \
    connection.h \
    fenetrehistorique.h \
    fournisseur.h \
    mainwindow.h \
    qr_code.h \
    qr_code1.h \
    statistique.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
