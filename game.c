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

void playerTurn(int column) {
    if (game_over) return; // Prevent moves if the game is over

    if (column < 1 || column > num_cols || board[0][column - 1] != '.') {
        return; // Ignore invalid moves or if the column is full
    }

    for (int i = num_rows - 1; i >= 0; i--) {
        if (board[i][column - 1] == '.') {
            board[i][column - 1] = currentPlayer;
            value = i;
            number = column;
            break;
        }
    }
}

char checkFour(int a_1, int a_2, int b_1, int b_2, int c_1, int c_2, int d_1, int d_2) {
    if (board[a_1][a_2] == board[b_1][b_2] && board[b_1][b_2] == board[c_1][c_2] && board[c_1][c_2] == board[d_1][d_2] && board[a_1][a_2] != '.') {
        return board[a_1][a_2];
    }
    return 'a';
}

void scoreCheck() {
    int i = 1, j = 1, counter = 0, a, c = 1, b = -1;
    for (a = 0; a < 4; a++) {
        i = -i;
        j = j * pow(-1, counter);
        counter++;
        if (num_rows > value + i * 3 && value + i * 3 >= 0 && num_cols > number - 1 + j * 3 && number - 1 + j * 3 >= 0) {
            if ('X' == checkFour(value, number - 1, value + i, number - 1 + j, value + i * 2, number - 1 + j * 2, value + i * 3, number - 1 + j * 3)) score_x += 1;
            if ('O' == checkFour(value, number - 1, value + i, number - 1 + j, value + i * 2, number - 1 + j * 2, value + i * 3, number - 1 + j * 3)) score_o += 1;
        }
        if ('X' == checkFour(value, number - 1, value + j, number - 1 + i, value - j, number - 1 - i, value - 2 * j, number - 1 - 2 * i)) score_x += 1;
        if ('O' == checkFour(value, number - 1, value + j, number - 1 + i, value - j, number - 1 - i, value - 2 * j, number - 1 - 2 * i)) score_o += 1;
    }
    for (a = 0; a < 2; a++) {
        c = -c;
        b *= -1;
        if (num_rows > value + 3 * c && value + 3 * c >= 0) {
            if ('X' == checkFour(value, number - 1, value + c, number - 1, value + 2 * c, number - 1, value + 3 * c, number - 1)) score_x += 1;
            if ('O' == checkFour(value, number - 1, value + c, number - 1, value + 2 * c, number - 1, value + 3 * c, number - 1)) score_o += 1;
        }
        if (num_cols > number - 1 + 3 * c && number - 1 + 3 * c >= 0) {
            if ('X' == checkFour(value, number - 1, value, number - 1 + c, value, number - 1 + 2 * c, value, number - 1 + 3 * c)) score_x += 1;
            if ('O' == checkFour(value, number - 1, value, number - 1 + c, value, number - 1 + 2 * c, value, number - 1 + 3 * c)) score_o += 1;
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