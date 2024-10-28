cmake_minimum_required(VERSION 3.29)
project(Battleship)

set(CMAKE_CXX_STANDARD 20)

add_executable(Battleship src/main.cpp
        src/board.cpp
        src/Cell.cpp
        src/Ship.cpp
        src/Art.cpp
        src/Art.h
        src/UX.cpp
        src/UX.h
        src/Fleet.cpp
        src/Fleet.h
        src/Player.cpp
        src/Player.h
        src/Game.cpp
        src/Game.h
        src/Color.cpp
        src/Color.h
)

target_link_options(Battleship PUBLIC -static -static-libgcc -static-libstdc++)
