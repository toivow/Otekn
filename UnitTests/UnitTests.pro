QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_statisticstest.cpp \
        ../Game/Engine/statistics.cc \

HEADERS +=  ../Game/statistics.h \
    ../Course/CourseLib/interfaces/istatistics.hh

INCLUDEPATH += ../Game/
