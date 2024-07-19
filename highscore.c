#include <stdio.h>
#include "highscore.h"

void High_Score() {
    int scores[100] = {0}, i, counter = -1, j = 0, temp = 0;
    FILE *file = fopen("High_scores.txt", "r");
    for (i = 0; i < 20; i++) {
        fscanf(file, "%d", &scores[i]);
        if (scores[i] != 0) counter++;
    }
    fclose(file);
    if (score_x > score_o) scores[counter + 1] = score_x;
    else scores[counter + 1] = score_o;
    for (i = 0; i < Highscore; i++) {
        for (j = 0; j < Highscore; j++) {
            if (scores[j] < scores[i]) {
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }
    file = fopen("High_scores.txt", "w");
    for (i = 0; i < Highscore; i++) {
        fprintf(file, "%d  ", scores[i]);
    }
    fclose(file);
}

void displayHighScores() {
    int scores[Highscore] = {0}, i;
    FILE *file = fopen("High_scores.txt", "r");
    if (file == NULL) {
        printf("No high scores available.\n");
        return;
    }
    for (i = 0; i < Highscore; i++) {
        fscanf(file, "%d", &scores[i]);
    }
    fclose(file);

    printf("\n=== High Scores ===\n");
    for (i = 0; i < Highscore && scores[i] != 0; i++) {
        printf("%d. %d\n", i + 1, scores[i]);
    }
}
