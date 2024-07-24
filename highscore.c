#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "highscore.h"
#include "game.h"

HighScoreEntry scores[Highscore];

void High_Score() {
    FILE *file;
    int i;

    // Initialize the scores array
    for (i = 0; i < Highscore; i++) {
        scores[i].player = '-';
        scores[i].score = 0;
    }

    // Read existing scores from the file
    file = fopen("High_scores.txt", "r");
    if (file != NULL) {
        for (i = 0; i < Highscore; i++) {
            fscanf(file, " %c %d", &scores[i].player, &scores[i].score);
        }
        fclose(file);
    }

    // Update the scores with the new score
    HighScoreEntry new_score;
    new_score.player = (score_x > score_o) ? 'X' : 'O';
    new_score.score = (score_x > score_o) ? score_x : score_o;

    // Insert the new score in the right position
    for (i = 0; i < Highscore; i++) {
        if (new_score.score > scores[i].score) {
            for (int j = Highscore - 1; j > i; j--) {
                scores[j] = scores[j - 1];
            }
            scores[i] = new_score;
            break;
        }
    }

    // Write updated scores to the file
    file = fopen("High_scores.txt", "w");
    if (file != NULL) {
        for (i = 0; i < Highscore; i++) {
            fprintf(file, "%c %d\n", scores[i].player, scores[i].score);
        }
        fclose(file);
    }
}

void display_high_scores(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog, *content_area, *label;
    GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;
    dialog = gtk_dialog_new_with_buttons("Score History",
                                         GTK_WINDOW(data),
                                         flags,
                                         ("_OK"),
                                         GTK_RESPONSE_NONE,
                                         NULL);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    GString *high_scores_text = g_string_new("\n=== Score History ===\n");

    for (int i = 0; i < Highscore; i++) {
        if (scores[i].player != '-') {
            g_string_append_printf(high_scores_text, "%d. Player %c: %d\n", i + 1, scores[i].player, scores[i].score);
        }
    }

    label = gtk_label_new(high_scores_text->str);
    g_string_free(high_scores_text, TRUE);
    gtk_container_add(GTK_CONTAINER(content_area), label);
    gtk_widget_show_all(dialog);

    g_signal_connect_swapped(dialog, "response", G_CALLBACK(gtk_widget_destroy), dialog);
}