include(QtGifImage/src/gifimage/qtgifimage.pri)
QT       += core gui openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 -Wall -Werror -Wextra

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    glview.cc \
    joystick.cc \
    main.cc \
    mainwindow.cc \
    ../model/model.cc \
    ../controller/controller.cc

HEADERS += \
    glview.h \
    joystick.h \
    mainwindow.h \
    ../model/model.h \
    ../controller/controller.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

