cmake_minimum_required(VERSION 3.0)
project(CHESS)
include_directories(include/)
set(CMAKE_CXX_STANDARD 11)
add_executable(app 
src/main.cpp 
src/cell.cpp 
src/id.cpp
src/chessBoard.cpp
)