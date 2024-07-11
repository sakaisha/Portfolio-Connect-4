#include <stdio.h>
#include "board.h"
#include "game.h"
#include "highscore.h"

int main() {
    initializeBoard();
    char currentPlayer = 'X';
    while (1) {
        displayBoard();
        playerTurn(currentPlayer);
        scoreCheck();
        if (score_x > 0 || score_o > 0) {
            displayBoard();
            printf("Player %c wins!\n", (score_x > score_o) ? 'X' : 'O');
            High_Score();
            restartOrExit();
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    return 0;
}
