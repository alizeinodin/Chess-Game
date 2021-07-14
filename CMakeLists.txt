cmake_minimum_required(VERSION 3.16.0)
project(AP)
set(src
        
src/main.cpp
src/chessman.cpp
src/king.cpp       
src/util.cpp
src/pawn.cpp
src/rook.cpp
)


include_directories(./include)
set(CMAKE_CXX_STANDARD 11)
add_executable(app ${src})