cmake_minimum_required(VERSION 3.29)
project(Battleship)

set(CMAKE_CXX_STANDARD 20)

add_executable(Battleship src/main.cpp
        src/board/board.cpp
        src/Cell/Cell.cpp
        src/Ship/Ship.cpp
)

target_link_options(Battleship PUBLIC -static -static-libgcc -static-libstdc++)
