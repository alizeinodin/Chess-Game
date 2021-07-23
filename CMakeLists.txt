
cmake_minimum_required(VERSION 3.16.0)
project(CHESS)
include_directories(include/)
set(CMAKE_CXX_STANDARD 11)
add_executable(app 
src/main.cpp 
src/cell.cpp 
src/id.cpp
src/chessBoard.cpp
src/fileConnect.cpp
src/player.cpp
src/game.cpp
# src/pawn.cpp
# src/util.cpp
# src/king.cpp
# src/rook.cpp
# src/knight.cpp
# src/bishop.cpp
# src/queen.cpp
# src/chessman.cpp
)
