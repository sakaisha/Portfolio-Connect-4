#ifndef GAME_H
#define GAME_H

extern int score_x;
extern int score_o;
extern int value;
extern int number;

void playerTurn(char player);
char checkFour(int a_1, int a_2, int b_1, int b_2, int c_1, int c_2, int d_1, int d_2);
void scoreCheck();
void restartOrExit();

#endif // GAME_H
