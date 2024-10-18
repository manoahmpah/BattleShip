cmake_minimum_required(VERSION 3.29)
project(Battleship)

set(CMAKE_CXX_STANDARD 20)

add_executable(Battleship main.cpp
        classes/board/board.cpp
        classes/board/boards.h
        classes/Cell/Cell.cpp
        classes/Cell/Cell.h
        classes/Ship/Ship.cpp
        classes/Ship/Ship.h
)

target_link_options(Battleship PUBLIC -static -static-libgcc -static-libstdc++)
