#include <stdio.h>
#include "highscore.h"

/**
 * High_Score - Updates and sorts the high scores
 *
 * This function reads the high scores from a file, updates the list with
 * the latest score, sorts the scores in descending order, and writes the
 * updated high scores back to the file.
 */
void High_Score(void)
{
    int scores[100] = {0};
    int i, counter = -1, j = 0, temp = 0;
    FILE *file;

    file = fopen("High_scores.txt", "r");
    if (file == NULL)
    {
        perror("Error opening high scores file");
        return;
    }

    for (i = 0; i < 20; i++)
    {
        fscanf(file, "%d", &scores[i]);
        if (scores[i] != 0)
            counter++;
    }
    fclose(file);

    if (score_x > score_o)
        scores[counter + 1] = score_x;
    else
        scores[counter + 1] = score_o;

    for (i = 0; i < Highscore; i++)
    {
        for (j = 0; j < Highscore; j++)
        {
            if (scores[j] < scores[i])
            {
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }

    file = fopen("High_scores.txt", "w");
    if (file == NULL)
    {
        perror("Error opening high scores file");
        return;
    }

    for (i = 0; i < Highscore; i++)
    {
        fprintf(file, "%d  ", scores[i]);
    }
    fclose(file);
}

/**
 * displayHighScores - Displays the high scores
 *
 * This function reads the high scores from a file and prints them to the console.
 * If the file cannot be opened, it prints an error message.
 */
void displayHighScores(void)
{
    int scores[Highscore] = {0};
    int i;
    FILE *file;

    file = fopen("High_scores.txt", "r");
    if (file == NULL)
    {
        printf("No high scores available.\n");
        return;
    }

    for (i = 0; i < Highscore; i++)
    {
        fscanf(file, "%d", &scores[i]);
    }
    fclose(file);

    printf("\n=== High Scores ===\n");
    for (i = 0; i < Highscore && scores[i] != 0; i++)
    {
        printf("%d. %d\n", i + 1, scores[i]);
    }
}