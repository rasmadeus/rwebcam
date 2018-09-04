QT += \
    core \
    gui \
    widgets \
    multimedia

TARGET = \
    rwebcam

TEMPLATE = \
    app

DEFINES += \
    QT_DEPRECATED_WARNINGS

CONFIG += \
    c++14

SOURCES += \
    main.cpp \
    main_view.cpp \
    signals_src.cpp

HEADERS += \
    main_view.h \
    signals_src.h

FORMS += \
    main_view.ui

unix {
    FFMPEG_HOME = /home/rasmadeus/Documents/dev/sdk/ffmpeg

    INCLUDEPATH += \
        $$FFMPEG_HOME/include

    LIBS += \
        -L$$FFMPEG_HOME/lib \
        -lz \
        -lavdevice \
        -lavformat \
        -lswscale
}

DISTFILES += \
    README.md
