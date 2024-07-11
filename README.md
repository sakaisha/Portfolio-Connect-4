# Connect 4 Game

This project is a Connect 4 game implemented in C, as part of my ALX portfolio project. I am humbly working on this project all alone, ensuring it meets all requirements and functionalities of the classic Connect 4 game.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Files](#files)
- [Setup](#setup)
- [Usage](#usage)
- [Gameplay](#gameplay)
- [Libraries Used](#libraries-used)
- [Acknowledgements](#acknowledgements)

## Introduction

Connect 4 is a two-player connection game in which the players take turns dropping colored discs from the top into a seven-column, six-row vertically suspended grid. The pieces fall straight down, occupying the next available space within the column. The objective of the game is to be the first to form a horizontal, vertical, or diagonal line of four of one's own discs.

## Features

- Two-player gameplay
- Win detection for horizontal, vertical, and diagonal lines
- High score management
- Option to restart or exit the game
- Main menu with options to start a new game, view high scores, or exit

## Files

- `main.c`: Contains the main function and the game loop.
- `board.h`: Header file for board-related functions.
- `board.c`: Source file for board-related functions.
- `game.h`: Header file for game logic and utility functions.
- `game.c`: Source file for game logic and utility functions.
- `highscore.h`: Header file for high score management functions.
- `highscore.c`: Source file for high score management functions.

## Setup

### Prerequisites

- GCC compiler

### Installation

1. **Clone the repository**:
   ```sh
   git clone https://github.com/yourusername/connect4.git
   cd connect4
   ```

2. **Compile the program**:
   ```sh
   gcc -o connect4 main.c board.c game.c highscore.c -lm
   ```

## Usage

1. **Run the program**:
   ```sh
   ./connect4
   ```

## Gameplay

1. The game starts with a main menu.
   - Options:
     - Start New Game
     - View High Scores
     - Exit

2. Players take turns to drop their discs into one of the columns.
   - Players are prompted to enter the column number (1-7) where they want to drop their disc.
   - The game checks for valid input and places the disc in the lowest available position in the chosen column.

3. The game checks for win conditions after each move.
   - Win conditions include four consecutive discs in a horizontal, vertical, or diagonal line.

4. The first player to form a horizontal, vertical, or diagonal line of four discs wins.
5. The game records the high scores.
6. Players can choose to restart or exit the game after it ends.

## Libraries Used

### Standard Libraries in C

1. **stdio.h**: Standard Input/Output Library
   - `printf()`: Used to display output to the console.
   - `scanf()`: Used to read input from the user.

   **Example**:
   ```c
   #include <stdio.h>

   int main() {
       int column;
       printf("Enter column number: ");
       scanf("%d", &column);
       printf("You entered: %d\n", column);
       return 0;
   }
   ```

   **Explanation**:
   - The `stdio.h` library provides essential functions for input and output operations, which are crucial for interacting with the players in the game. `printf()` allows us to display messages and the game board to the console, while `scanf()` lets us capture user inputs for their moves.

2. **stdlib.h**: Standard Library
   - `exit()`: Used to terminate the program.

   **Example**:
   ```c
   #include <stdlib.h>

   void exitGame() {
       printf("Exiting game.\n");
       exit(0);
   }
   ```

   **Explanation**:
   - The `stdlib.h` library includes functions for memory allocation, process control, conversions, and others. In our game, `exit()` is used to exit the program gracefully when the player chooses to quit. This is important for handling user-initiated exits and ensuring the program terminates cleanly.

3. **math.h**: Mathematics Library
   - `pow()`: Computes the power of a number.

   **Example**:
   ```c
   #include <math.h>
   #include <stdio.h>

   void examplePowerFunction() {
       double base = -1;
       double exponent = 3;
       double result = pow(base, exponent);
       printf("Result of pow(%lf, %lf) is %lf\n", base, exponent, result);
   }
   ```

   **Explanation**:
   - The `math.h` library provides mathematical functions. In our Connect 4 game, the `pow()` function is used to calculate powers, which is part of the logic for checking win conditions.
   - Specifically, `pow(-1, counter)` is used in the `scoreCheck` function to alternate between 1 and -1. This alternation helps in checking diagonal win conditions in both directions.

## Acknowledgements

This project is part of my ALX portfolio project. I am grateful for the support and feedback from peers and mentors throughout this journey.

---
