QT += quick
QT += quickcontrols2
QT += widgets
QT += multimedia

TARGET = chess
TEMPLATE = app

# Prefer C++17 for Qt 6; still works with Qt 5.15
CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

# Build against Qt 6 when available (qmake6 / Qt Creator Qt6 kit)
greaterThan(QT_MAJOR_VERSION, 5) {
    DEFINES += BUALI_QT6
    # High-DPI is always on in Qt 6
}

SOURCES += \
    main.cpp \
    src/Cell.cpp \
    src/bishop.cpp \
    src/chessBoard.cpp \
    src/chessman.cpp \
    src/connection.cpp \
    src/fileConnect.cpp \
    src/game.cpp \
    src/id.cpp \
    src/king.cpp \
    src/knight.cpp \
    src/pawn.cpp \
    src/player.cpp \
    src/queen.cpp \
    src/rook.cpp \
    src/util.cpp

RESOURCES += qml.qrc

QML_IMPORT_PATH =
QML_DESIGNER_IMPORT_PATH =

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    include/bishop.h \
    include/castling.h \
    include/cell.h \
    include/chessBoard.h \
    include/chessMan.h \
    include/connection.h \
    include/equality.h \
    include/fileConnect.h \
    include/game.h \
    include/id.h \
    include/king.h \
    include/kishexcept.h \
    include/knight.h \
    include/matexcept.h \
    include/moving.h \
    include/pawn.h \
    include/pawnpromotion.h \
    include/player.h \
    include/promotionundo.h \
    include/queen.h \
    include/rook.h \
    include/undoattack.h \
    include/using.h \
    include/util.h \
    include/enpassantexcept.h

DISTFILES += \
    media/Sound/attackPiece.WAV

INCLUDEPATH += $$PWD $$PWD/include
