QT += quick
QT += quickcontrols2
QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

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

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    include/bishop.h \
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
    include/player.h \
    include/queen.h \
    include/rook.h \
    include/undoattack.h \
    include/using.h \
    include/util.h \
    include/enpassantexcept.h

DISTFILES += \
    media/Sound/attackPiece.WAV
