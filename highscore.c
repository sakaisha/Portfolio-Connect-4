#include <stdio.h>
#include "highscore.h"

void High_Score() {
    int scores[100] = {0}, i, counter = -1, j = 0, temp = 0;
    FILE *file = fopen("High_scores.text", "r");
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
    printf("HIGH SCORE LIST IS : ");
    file = fopen("High_scores.text", "w");
    for (i = 0; i < Highscore; i++) {
        printf("%d   ", scores[i]);
        fprintf(file, "%d  ", scores[i]);
    }
    fclose(file);
}
