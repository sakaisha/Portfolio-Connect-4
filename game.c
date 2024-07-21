#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "board.h"
#include "game.h"

int score_x = 0;
int score_o = 0;
int value;
int number;
char currentPlayer = 'X';
int game_over = 0; // Initialize game_over

int playerTurn(int column) {
    if (game_over) return 0; // Prevent moves if the game is over

    if (column < 1 || column > num_cols || board[0][column - 1] != '.') {
        return 0; // Ignore invalid moves or if the column is full
    }

    for (int i = num_rows - 1; i >= 0; i--) {
        if (board[i][column - 1] == '.') {
            board[i][column - 1] = currentPlayer;
            value = i;
            number = column;
            return 1; // Valid move
        }
    }
    return 0; // Column is full
}

char checkFour(int a_1, int a_2, int b_1, int b_2, int c_1, int c_2, int d_1, int d_2) {
    if (board[a_1][a_2] == board[b_1][b_2] && board[b_1][b_2] == board[c_1][c_2] && board[c_1][c_2] == board[d_1][d_2] && board[a_1][a_2] != '.') {
        return board[a_1][a_2];
    }
    return 'a';
}

void scoreCheck() {
    // Check horizontal
    for (int row = 0; row < num_rows; ++row) {
        for (int col = 0; col < num_cols - 3; ++col) {
            if (checkFour(row, col, row, col + 1, row, col + 2, row, col + 3) != 'a') {
                if (board[row][col] == 'X') score_x += 1;
                if (board[row][col] == 'O') score_o += 1;
            }
        }
    }

    // Check vertical
    for (int col = 0; col < num_cols; ++col) {
        for (int row = 0; row < num_rows - 3; ++row) {
            if (checkFour(row, col, row + 1, col, row + 2, col, row + 3, col) != 'a') {
                if (board[row][col] == 'X') score_x += 1;
                if (board[row][col] == 'O') score_o += 1;
            }
        }
    }

    // Check diagonal (bottom-left to top-right)
    for (int row = 0; row < num_rows - 3; ++row) {
        for (int col = 0; col < num_cols - 3; ++col) {
            if (checkFour(row, col, row + 1, col + 1, row + 2, col + 2, row + 3, col + 3) != 'a') {
                if (board[row][col] == 'X') score_x += 1;
                if (board[row][col] == 'O') score_o += 1;
            }
        }
    }

    // Check diagonal (top-left to bottom-right)
    for (int row = 3; row < num_rows; ++row) {
        for (int col = 0; col < num_cols - 3; ++col) {
            if (checkFour(row, col, row - 1, col + 1, row - 2, col + 2, row - 3, col + 3) != 'a') {
                if (board[row][col] == 'X') score_x += 1;
                if (board[row][col] == 'O') score_o += 1;
            }
        }
    }

    if (score_x > 0 || score_o > 0) {
        game_over = 1; // Set game_over flag when a player wins
    }
}

void restartOrExit() {
    // This function can be called from the GTK+ interface to restart the game or exit
    // This code is no longer needed as restart and exit are handled by GTK+ buttons
}