TEMPLATE = app
TARGET = NYSSE

QT += core gui widgets network multimedia

CONFIG += c++14

SOURCES += \
    Actors/randomitem_logic.cpp \
    Engine/city.cpp \
    Engine/creategame.cpp \
    Engine/gameengine.cpp \
    Engine/statistics.cpp \
    Graphics/destroyer.cpp \
    Graphics/randomitem.cpp \
    Graphics/rectactoritem.cpp \
    Window/dialog.cpp \
    Window/enddialog.cpp \
    Window/mainwindow.cpp \
    main.cc \
    Actors/destroyer_logic.cpp

win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib

INCLUDEPATH += \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Course/CourseLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/libCourseLib.a

HEADERS += \
    Actors/randomitem_logic.hh \
    Engine/city.hh \
    Engine/creategame.hh \
    Engine/gameengine.hh \
    Graphics/destroyer.hh \
    Graphics/randomitem.hh \
    Graphics/rectactoritem.hh \
    Window/dialog.hh \
    Window/enddialog.hh \
    Window/mainwindow.hh \
    Actors/destroyer_logic.hh \
    Engine/statistics.hh


FORMS += \
    Window/enddialog.ui \
    dialog.ui \
    mainwindow.ui

DISTFILES += \
    Kuvat/Nysse_pixelart.png

RESOURCES += \
    kuvadata.qrc
