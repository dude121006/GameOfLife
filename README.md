# Conway's Game of Life

This is a C++ implementation of **Conway's Game of Life**, a zero-player game devised by the mathematician John Horton Conway in 1970. It's a cellular automaton that simulates a world of cells that live, die, or multiply based on a few simple rules, creating complex and unpredictable patterns.

## About the Game

The "Game of Life" is played on an infinite two-dimensional grid of square "cells," each of which is in one of two possible states: **alive** or **dead**. Every cell interacts with its eight neighbors (horizontally, vertically, or diagonally). At each step in time, the following transitions occur:

1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
2. Any live cell with two or three live neighbours lives on to the next generation.
3. Any live cell with more than three live neighbours dies, as if by overpopulation.
4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

These simple rules lead to fascinating emergent behavior, from stable patterns to "gliders" that move across the grid, and even "spaceships" that can generate other patterns.

## Technologies Used

* **C++:** The core programming language for the simulation logic.
* **SFML (Simple and Fast Multimedia Library):** Used for rendering the graphical interface, handling window events, and user input.

## How to Run

To compile and run this Game of Life simulation, you'll need a C++ compiler (like g++) and the SFML library installed on your system.

### Prerequisites

* **C++ Compiler:** G++ (or a compatible C++17 compiler)
* **SFML Library:** Ensure SFML graphics, window, and system modules are installed and configured for your compiler.

### Installation and Execution

1. **Clone the repository:**

```bash
git clone https://github.com/dude121006/GameOfLife.git
cd GameOfLife
```

2. **Compile the project:** Use the provided `Makefile` to compile the source code.

```bash
make compile
# or simply: make
```

This command will compile the C++ files and create an executable named `main` in the `bin/` directory.

3. **Run the simulation:**

```bash
make run
# or directly: ./bin/main
```

## Controls

* **Click on cells:** At the start of the game (before pressing Space), click on individual cells to toggle their state between alive and dead, creating your initial pattern.
* **Spacebar:** Press to start the simulation. Press again to pause/resume the simulation.
* **Enter:** Press to restart the game, clearing the grid and allowing you to draw a new initial pattern.

## Possible Enhancements (Future Ideas)

* **Pattern Saving/Loading:** Implement functionality to save and load custom or famous Game of Life patterns.
* **Speed Control:** Add options to adjust the simulation speed.
* **Grid Size Customization:** Allow users to define the dimensions of the grid.
* **Advanced UI Elements:** Add buttons or menus for more intuitive control.
* **Rule Customization:** Allow users to modify the rules of life and death, exploring variations of cellular automata.
