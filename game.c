#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "board.h"
#include "game.h"

/* Global variables for game state and scores */
int score_x = 0;
int score_o = 0;
int value;
int number;
char currentPlayer = 'X';
int game_over = 0; /* Initialize game_over */

/**
 * playerTurn - Handles the current player's move
 * @column: The column where the player wants to drop their piece
 *
 * This function checks if the move is valid. If the move is valid,
 * it updates the board with the current player's piece. The function
 * returns 1 for a valid move and 0 for an invalid move or if the game is over.
 *
 * Return: 1 if the move is valid, 0 otherwise.
 */
int playerTurn(int column)
{
    int i;

    if (game_over)
        return (0); /* Prevent moves if the game is over */

    if (column < 1 || column > num_cols || board[0][column - 1] != '.')
        return (0); /* Ignore invalid moves or if the column is full */

    for (i = num_rows - 1; i >= 0; i--)
    {
        if (board[i][column - 1] == '.')
        {
            board[i][column - 1] = currentPlayer;
            value = i;
            number = column;
            return (1); /* Valid move */
        }
    }
    return (0); /* Column is full */
}

/**
 * checkFour - Checks if four consecutive positions have the same player's piece
 * @a_1: Row index of the first position
 * @a_2: Column index of the first position
 * @b_1: Row index of the second position
 * @b_2: Column index of the second position
 * @c_1: Row index of the third position
 * @c_2: Column index of the third position
 * @d_1: Row index of the fourth position
 * @d_2: Column index of the fourth position
 *
 * This function checks if the four positions have the same player's piece
 * and are not empty. It returns the player's piece ('X' or 'O') if they match,
 * otherwise it returns 'a'.
 *
 * Return: 'X' or 'O' if there is a match, 'a' otherwise.
 */
char checkFour(int a_1, int a_2, int b_1, int b_2, int c_1, int c_2, int d_1, int d_2)
{
    if (board[a_1][a_2] == board[b_1][b_2] && board[b_1][b_2] == board[c_1][c_2] &&
        board[c_1][c_2] == board[d_1][d_2] && board[a_1][a_2] != '.')
    {
        return (board[a_1][a_2]);
    }
    return ('a');
}

/**
 * scoreCheck - Checks the board for any winning combinations
 *
 * This function checks horizontal, vertical, and diagonal lines for any
 * winning combinations of four consecutive pieces of the same player. If
 * a winning combination is found, it increments the respective player's score
 * and sets the game_over flag.
 */
void scoreCheck(void)
{
    int row, col;

    /* Check horizontal */
    for (row = 0; row < num_rows; ++row)
    {
        for (col = 0; col < num_cols - 3; ++col)
        {
            if (checkFour(row, col, row, col + 1, row, col + 2, row, col + 3) != 'a')
            {
                if (board[row][col] == 'X')
                    score_x += 1;
                if (board[row][col] == 'O')
                    score_o += 1;
            }
        }
    }

    /* Check vertical */
    for (col = 0; col < num_cols; ++col)
    {
        for (row = 0; row < num_rows - 3; ++row)
        {
            if (checkFour(row, col, row + 1, col, row + 2, col, row + 3, col) != 'a')
            {
                if (board[row][col] == 'X')
                    score_x += 1;
                if (board[row][col] == 'O')
                    score_o += 1;
            }
        }
    }

    /* Check diagonal (bottom-left to top-right) */
    for (row = 0; row < num_rows - 3; ++row)
    {
        for (col = 0; col < num_cols - 3; ++col)
        {
            if (checkFour(row, col, row + 1, col + 1, row + 2, col + 2, row + 3, col + 3) != 'a')
            {
                if (board[row][col] == 'X')
                    score_x += 1;
                if (board[row][col] == 'O')
                    score_o += 1;
            }
        }
    }

    /* Check diagonal (top-left to bottom-right) */
    for (row = 3; row < num_rows; ++row)
    {
        for (col = 0; col < num_cols - 3; ++col)
        {
            if (checkFour(row, col, row - 1, col + 1, row - 2, col + 2, row - 3, col + 3) != 'a')
            {
                if (board[row][col] == 'X')
                    score_x += 1;
                if (board[row][col] == 'O')
                    score_o += 1;
            }
        }
    }

    if (score_x > 0 || score_o > 0)
    {
        game_over = 1; /* Set game_over flag when a player wins */
    }
}

/**
 * restartOrExit - Placeholder function for restarting or exiting the game
 *
 * This function is intended to be called from the GTK+ interface to
 * restart the game or exit. The functionality is handled by GTK+ buttons,
 * so this function is currently not needed.
 */
void restartOrExit(void)
{
    /* This function can be called from the GTK+ interface to restart the game or exit */
    /* This code is no longer needed as restart and exit are handled by GTK+ buttons */
}