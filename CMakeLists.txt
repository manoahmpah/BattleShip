cmake_minimum_required(VERSION 3.29)
project(Battleship)

set(CMAKE_CXX_STANDARD 20)

add_executable(Battleship
        src/main.cpp
        src/board.cpp
        src/Cell.cpp
        src/Ship.cpp
        src/Art.cpp
        src/UX.cpp
        src/Fleet.cpp
        src/Player.cpp
        src/Game.cpp
        src/Color.cpp
)

target_link_options(Battleship PUBLIC -static -static-libgcc -static-libstdc++)
