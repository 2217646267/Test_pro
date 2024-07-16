QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BannerWidget.cpp \
    HFrameEvent.cpp \
    checkboxdelegate.cpp \
    checkboxwidget.cpp \
    main.cpp \
    mybtn.cpp \
    painterwidget.cpp \
    rightwidget.cpp \
    tablemodel.cpp \
    widget.cpp \
    IconLabel.cpp\
    LanelRotate.cpp

HEADERS += \
    BannerWidget.h \
    HFrameEvent.h \
    checkboxdelegate.h \
    checkboxwidget.h \
    mybtn.h \
    painterwidget.h \
    rightwidget.h \
    tablemodel.h \
    widget.h \
    IconLabel.h\
    LanelRotate.h


FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
