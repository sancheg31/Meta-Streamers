QT  += core gui

message($$QT_VERSION)
message($$QT_MAJOR_VERSION)
message($$QT_MINOR_VERSION)
message($$QT_PATCH_VERSION)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
PRECOMPILED_HEADER = pch.h
TEMPLATE= app

DEFINES += QT_DEPRECATED_WARNINGS
INCLUDEPATH += "meta streamers"

SOURCES += \
    Counter.cpp \
    ItemDelegate.cpp \
    "meta streamers/MetaObjectStreamer.cpp" \
    VolumeHandler.cpp \
    main.cpp \
    "meta streamers/MetaEnumStreamer.cpp" \
    "meta streamers/MetaMethodStreamer.cpp" \
    "meta streamers/MetaPropertyStreamer.cpp" \
    "meta streamers/MetaTypeStreamer.cpp" \
    "meta streamers/IMetaStreamer.cpp"

HEADERS += \
    Counter.h \
    ItemDelegate.h \
    "meta streamers/MetaObjectStreamer.h" \
    VolumeHandler.h \
    "meta streamers/MetaEnumStreamer.h" \
    "meta streamers/MetaMethodStreamer.h" \
    "meta streamers/MetaPropertyStreamer.h" \
    "meta streamers/MetaTypeStreamer.h" \
    "meta streamers/IMetaStreamer.h" \
    pch.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
