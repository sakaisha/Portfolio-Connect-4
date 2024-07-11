# Connect 4 Game

This project is a Connect 4 game implemented in C, as part of my ALX portfolio project. I am humbly working on this project all alone, ensuring it meets all requirements and functionalities of the classic Connect 4 game.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Files](#files)
- [Setup](#setup)
- [Usage](#usage)
- [Gameplay](#gameplay)
- [Acknowledgements](#acknowledgements)

## Introduction

Connect 4 is a two-player connection game in which the players take turns dropping colored discs from the top into a seven-column, six-row vertically suspended grid. The pieces fall straight down, occupying the next available space within the column. The objective of the game is to be the first to form a horizontal, vertical, or diagonal line of four of one's own discs.

## Features

- Two-player gameplay
- Win detection for horizontal, vertical, and diagonal lines
- High score management
- Option to restart or exit the game

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
   gcc -o connect4 main.c board.c game.c highscore.c
   ```

## Usage

1. **Run the program**:
   ```sh
   ./connect4
   ```

## Gameplay

1. The game starts with an empty board.
2. Players take turns to drop their discs into one of the columns.
3. The game checks for win conditions after each move.
4. The first player to form a horizontal, vertical, or diagonal line of four discs wins.
5. The game records the high scores.
6. Players can choose to restart or exit the game after it ends.

## Acknowledgements

This project is part of my ALX portfolio project. I am grateful for the support and feedback from peers and mentors throughout this journey.

---

Feel free to customize the repository URL and any other details as needed.
