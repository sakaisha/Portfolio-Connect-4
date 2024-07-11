#include <stdio.h>
#include "board.h"

char board[num_rows][num_cols];

void initializeBoard() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            board[i][j] = '.';
        }
    }
}

void displayBoard() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
