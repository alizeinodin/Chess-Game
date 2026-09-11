cmake_minimum_required(VERSION 3.16)

project(chess VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 5.12 REQUIRED COMPONENTS
    Core
    Gui
    Quick
    QuickControls2
    Multimedia
    Widgets
)

set(SOURCES
    main.cpp
    src/Cell.cpp
    src/bishop.cpp
    src/chessBoard.cpp
    src/chessman.cpp
    src/connection.cpp
    src/fileConnect.cpp
    src/game.cpp
    src/id.cpp
    src/king.cpp
    src/knight.cpp
    src/pawn.cpp
    src/player.cpp
    src/queen.cpp
    src/rook.cpp
    src/util.cpp
)

set(HEADERS
    include/bishop.h
    include/castling.h
    include/cell.h
    include/chessBoard.h
    include/chessMan.h
    include/connection.h
    include/equality.h
    include/fileConnect.h
    include/game.h
    include/id.h
    include/king.h
    include/kishexcept.h
    include/knight.h
    include/matexcept.h
    include/moving.h
    include/pawn.h
    include/pawnpromotion.h
    include/player.h
    include/promotionundo.h
    include/queen.h
    include/rook.h
    include/undoattack.h
    include/using.h
    include/util.h
    include/enpassantexcept.h
)

add_executable(chess
    ${SOURCES}
    ${HEADERS}
    qml.qrc
)

target_include_directories(chess PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(chess PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Quick
    Qt5::QuickControls2
    Qt5::Multimedia
    Qt5::Widgets
)

target_compile_definitions(chess PRIVATE QT_DEPRECATED_WARNINGS)

install(TARGETS chess RUNTIME DESTINATION bin)

# Optional desktop entry helper for Linux packaging
if(UNIX AND NOT APPLE)
    install(FILES packaging/linux/bu-ali-chess.desktop
            DESTINATION share/applications
            OPTIONAL)
    install(FILES media/knight2.png
            DESTINATION share/pixmaps
            RENAME bu-ali-chess.png
            OPTIONAL)
endif()
