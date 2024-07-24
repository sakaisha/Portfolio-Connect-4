#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <gtk/gtk.h>  // Include GTK headers

#define Highscore 10

extern int score_x;
extern int score_o;

typedef struct {
    char player;
    int score;
} HighScoreEntry;

extern HighScoreEntry scores[Highscore]; // Declare scores as extern

void High_Score();
void display_high_scores(GtkWidget *widget, gpointer data);

#endif