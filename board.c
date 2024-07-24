#include <stdio.h>
#include "board.h"

/* Global variable declaration for the game board */
char board[num_rows][num_cols];

/**
 * initializeBoard - Initializes the game board with empty spaces
 *
 * This function iterates through each row and column of the board
 * and sets each position to '.' indicating an empty space.
 */
void initializeBoard(void)
{
    int i, j;

    for (i = 0; i < num_rows; i++)
    {
        for (j = 0; j < num_cols; j++)
        {
            board[i][j] = '.';
        }
    }
}

/**
 * displayBoard - Displays the game board on the console
 *
 * This function iterates through each row and column of the board
 * and prints the current state of each position. A space is printed
 * between each column element and a newline after each row.
 */
void displayBoard(void)
{
    int i, j;

    for (i = 0; i < num_rows; i++)
    {
        for (j = 0; j < num_cols; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}