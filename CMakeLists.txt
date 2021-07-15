<<<<<<< HEAD
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
=======
cmake_minimum_required(VERSION 3.0)
project(CHESS)
include_directories(include/)
set(CMAKE_CXX_STANDARD 11)
add_executable(app 
src/main.cpp 
src/cell.cpp 
src/id.cpp
src/chessBoard.cpp
<<<<<<< HEAD
src/fileConnect.cpp
)
=======
)
>>>>>>> 534eac2a9fe7241af6bf8629b7c368f4b8fd42a4
>>>>>>> 373edc2f9159d4e6e6a32f4af4fcfd8b1d47c633
