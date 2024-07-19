---

# Connect 4 Game

This project is a Connect 4 game implemented in C, as part of my ALX portfolio project. I am humbly working on this project all alone, ensuring it meets all requirements and functionalities of the classic Connect 4 game.

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [Files](#files)
4. [Setup](#setup)
5. [Usage](#usage)
6. [Gameplay](#gameplay)
7. [Libraries Used](#libraries-used)
8. [Acknowledgements](#acknowledgements)
9. [Updates and New Features](#updates-and-new-features)

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
- MSYS2 with the following packages:
  - `base-devel`
  - `mingw-w64-x86_64-toolchain`
  - `mingw-w64-x86_64-gtk3`

### Installation

1. **Install MSYS2**:
   Download and install MSYS2 from [msys2.org](https://www.msys2.org/).

2. **Open MSYS2 MinGW 64-bit**:
   Open the MSYS2 MinGW 64-bit terminal.

3. **Update the package database**:
   ```sh
   pacman -Syu
   ```

4. **Install required packages**:
   ```sh
   pacman -S base-devel mingw-w64-x86_64-toolchain mingw-w64-x86_64-gtk3
   ```

5. **Clone the repository**:
   ```sh
   git clone https://github.com/sakaisha/Portfolio-Connect-4.git
   cd Portfolio-Connect-4
   ```

6. **Compile the program**:
   ```sh
   gcc main.c board.c game.c highscore.c -o connect4 `pkg-config --cflags --libs gtk+-3.0` -lm
   ```

## Usage

1. **Run the program**:
   ```sh
   ./connect4
   ```

## Gameplay

The game starts with a main menu.

### Options:
- Start New Game
- View High Scores
- Exit

Players take turns to drop their discs into one of the columns.

- Players are prompted to enter the column number (1-7) where they want to drop their disc.
- The game checks for valid input and places the disc in the lowest available position in the chosen column.
- The game checks for win conditions after each move.

Win conditions include four consecutive discs in a horizontal, vertical, or diagonal line.

- The first player to form a horizontal, vertical, or diagonal line of four discs wins.

The game records the high scores.

- Players can choose to restart or exit the game after it ends.

## Libraries Used

### Standard Libraries in C

- **stdio.h**: Standard Input/Output Library

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

  Explanation:
  The `stdio.h` library provides essential functions for input and output operations, which are crucial for interacting with the players in the game. `printf()` allows us to display messages and the game board to the console, while `scanf()` lets us capture user inputs for their moves.

- **stdlib.h**: Standard Library

  ```c
  #include <stdlib.h>

  void exitGame() {
      printf("Exiting game.\n");
      exit(0);
  }
  ```

  Explanation:
  The `stdlib.h` library includes functions for memory allocation, process control, conversions, and others. In our game, `exit()` is used to exit the program gracefully when the player chooses to quit. This is important for handling user-initiated exits and ensuring the program terminates cleanly.

- **math.h**: Mathematics Library

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

  Explanation:
  The `math.h` library provides mathematical functions. In our Connect 4 game, the `pow()` function is used to calculate powers, which is part of the logic for checking win conditions. Specifically, `pow(-1, counter)` is used in the `scoreCheck` function to alternate between 1 and -1. This alternation helps in checking diagonal win conditions in both directions.

### GTK+ Library

- **gtk/gtk.h**: GTK+ for GUI

  ```c
  #include <gtk/gtk.h>

  GtkWidget *board_buttons[num_rows][num_cols];
  GtkWidget *current_player_label;

  void create_game_board(GtkWidget *grid) {
      for (int i = 0; i < num_rows; ++i) {
          for (int j = 0; j < num_cols; ++j) {
              board_buttons[i][j] = gtk_button_new_with_label(".");
              gtk_grid_attach(GTK_GRID(grid), board_buttons[i][j], j, i, 1, 1);
              g_signal_connect(board_buttons[i][j], "clicked", G_CALLBACK(on_board_button_clicked), GINT_TO_POINTER(j + 1));
              apply_css(board_buttons[i][j], "empty");
          }
      }
      update_board_display();
  }
  ```

  Explanation:
  The `gtk/gtk.h` library is used to create a graphical user interface (GUI) for the game. In the Connect 4 game, GTK+ is used to create the game board, handle button clicks, and update the display. The `create_game_board` function initializes the buttons on the grid and sets up the event handlers for player moves.

## Acknowledgements

This project is part of my ALX portfolio project. I am grateful for the support and feedback from peers and mentors throughout this journey.

## Updates and New Features

### Game Logic Improvements

1. **Column Full Check**:
   - The game now prevents players from selecting a column once all six slots in that column are filled. This ensures the integrity of the gameplay by disallowing invalid moves.

2. **Game Over Handling**:
   - The game stops accepting inputs after a player wins. Once a player forms a line of four discs, the game announces the winner and prevents any further moves until the game is restarted.

### Additional Changes

- **GTK+ Integration**:
  - The game now uses GTK+ for the graphical user interface (GUI). This enhances the user experience with a visually appealing and interactive interface.
  
- **New Files Added**:
  - `style.css`: CSS file for styling the GTK+ buttons.

---
