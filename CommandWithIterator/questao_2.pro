QT += core
QT -= gui

CONFIG += c++11

TARGET = questao_2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    icommand.cpp \
    adicaocommand.cpp \
    subtracaocommand.cpp \
    multiplicacaocommand.cpp \
    divisaocommand.cpp \
    commandstack.cpp

HEADERS += \
    icommand.h \
    adicaocommand.h \
    subtracaocommand.h \
    multiplicacaocommand.h \
    divisaocommand.h \
    commandstack.h \
    commanditerator.h
