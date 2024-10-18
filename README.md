Voici un exemple de `README.md` pour ton projet de jeu **Battleship** en C++ :

---

# Battleship Game 🎯

Welcome to the **Battleship Game** – an epic console-based naval combat game where strategy meets luck! Sink your opponent's fleet before they sink yours!

## Table of Contents
1. [About the Game](#about-the-game)
2. [How to Play](#how-to-play)
3. [Features](#features)
4. [Installation](#installation)
5. [Game Preview](#game-preview)
6. [Instructions](#instructions)
7. [Technologies Used](#technologies-used)
8. [Contributing](#contributing)
9. [License](#license)

---

## About the Game
**Battleship** is a classic naval warfare game where each player has a fleet of ships hidden on a grid. The goal is to locate and destroy the opponent's fleet by guessing the coordinates of their ships. This project is built in **C++** and runs in the console, making use of ASCII art to enhance the experience.

## How to Play
1. **Start the game** from the main menu.
   - Option to automatically place your fleet or manually position each ship.
2. **Take turns** with the computer to attack a position on the enemy's grid.
3. **Sink all ships** of the opponent to win the game!

## Features
- Classic Battleship grid (10x10) gameplay.
- Multiple ship types with different lengths:
  - Aircraft Carrier (5 spaces)
  - Battleship (4 spaces)
  - Cruiser (3 spaces)
  - Submarine (3 spaces)
  - Destroyer (2 spaces)
- **Random** or **manual** ship placement.
- ASCII art and clear console design for a retro game experience.
- Game logic that tracks hits, misses, and sunken ships.
- Main menu with options to start, view instructions, or exit.

## Installation

### Prerequisites
- You will need a C++ compiler (e.g., GCC or Visual Studio) installed on your machine.

### Steps
1. Clone this repository:
    ```bash
    git clone https://github.com/mpahmanoah/BattleShip.git
    ```

2. Navigate to the project directory:
    ```bash
    cd BattleShip
    ```

3. Compile the game:
    ```bash
    g++ -o battleship main.cpp
    ```

4. Run the game:
    ```bash
    ./battleship
    ```

### Windows Users
If you're on Windows, you can use the provided `.bat` file to compile and run the game, or use your favorite IDE like Visual Studio.

## Game Preview
```
╔══════════════════════════════════════════════════════════════════════════════════════╗
║                                                                                      ║
║     ██████╗  █████╗ ████████╗████████╗██╗     ███████╗███████╗██╗  ██╗██╗██████╗     ║
║     ██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██║     ██╔════╝██╔════╝██║  ██║██║██╔══██╗    ║
║     ██████╔╝███████║   ██║      ██║   ██║     █████╗  ███████╗███████║██║██████╔╝    ║
║     ██╔══██╗██╔══██║   ██║      ██║   ██║     ██╔══╝  ╚════██║██╔══██║██║██╔═══╝     ║
║     ██████╔╝██║  ██║   ██║      ██║   ███████╗███████╗███████║██║  ██║██║██║         ║
║     ╚═════╝ ╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝╚═╝         ║
║                                                                                      ║
║                            WELCOME TO THE BATTLESHIP GAME                            ║
║                                                                                      ║
║                          "Prepare for epic naval battles!"                           ║
║                                                                                      ║
║                             ╔═══════════════════════════╗                            ║
║                             ║   [1] Start Game          ║                            ║
║                             ║   [2] Instructions        ║                            ║
║                             ║   [3] Exit                ║                            ║
║                             ╚═══════════════════════════╝                            ║
║                                                                                      ║
║                           Select an option and press Enter...                        ║
║                                                                                      ║
╚══════════════════════════════════════════════════════════════════════════════════════╝

```

## Instructions
- **Main Menu**: 
    - Press `1` to start a new game.
    - Press `2` to view game instructions.
    - Press `3` to exit the game.

- **Gameplay**:
    - Use the numeric keys to input coordinates (e.g., `4 7`) to attack.
    - The game continues until all ships from one player are sunk.
    
## Technologies Used
- **C++**: Core programming language for the game's logic.
- **ASCII Art**: For console-based visual effects and UI design.

## Contributing
Contributions are welcome! If you have any ideas or improvements for this project, feel free to fork the repository, create a feature branch, and submit a pull request.

### Steps for contributing:
1. Fork the project
2. Create a new branch (`git checkout -b feature-branch`)
3. Commit your changes (`git commit -m 'Add some feature'`)
4. Push to the branch (`git push origin feature-branch`)
5. Open a pull request

---

**Enjoy the game, and may the best captain win!** 🛳️🔥

---
