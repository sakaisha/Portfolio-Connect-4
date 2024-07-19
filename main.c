#include <gtk/gtk.h>
#include "board.h"
#include "game.h"
#include "highscore.h"

GtkWidget *board_buttons[num_rows][num_cols];
GtkWidget *current_player_label;

void apply_css(GtkWidget *widget, const gchar *class_name) {
    GtkStyleContext *context;
    context = gtk_widget_get_style_context(widget);
    gtk_style_context_add_class(context, class_name);
}

void update_board_display() {
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            char label[2] = {board[i][j], '\0'};
            gtk_button_set_label(GTK_BUTTON(board_buttons[i][j]), label);
            if (board[i][j] == '.') {
                apply_css(board_buttons[i][j], "empty");
            } else if (board[i][j] == 'X') {
                apply_css(board_buttons[i][j], "player-x");
            } else if (board[i][j] == 'O') {
                apply_css(board_buttons[i][j], "player-o");
            }
        }
    }
}

void on_board_button_clicked(GtkWidget *widget, gpointer data) {
    if (game_over) return; // Prevent moves if the game is over

    int col = GPOINTER_TO_INT(data);
    playerTurn(col);
    scoreCheck();
    update_board_display();

    if (score_x > 0 || score_o > 0) {
        const char *winner = (score_x > score_o) ? "Player X wins!" : "Player O wins!";
        gtk_label_set_text(GTK_LABEL(current_player_label), winner);
        High_Score();
    } else {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        char label[10];
        snprintf(label, 10, "Player %c", currentPlayer);
        gtk_label_set_text(GTK_LABEL(current_player_label), label);
    }
}

void create_game_board(GtkWidget *grid) {
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            board_buttons[i][j] = gtk_button_new_with_label(".");
            gtk_grid_attach(GTK_GRID(grid), board_buttons[i][j], j, i, 1, 1);
            g_signal_connect(board_buttons[i][j], "clicked", G_CALLBACK(on_board_button_clicked), GINT_TO_POINTER(j + 1));
            apply_css(board_buttons[i][j], "empty");
        }
    }
    update_board_display();
}

void start_new_game(GtkWidget *widget, gpointer data) {
    GtkWidget *grid = GTK_WIDGET(data);
    initializeBoard();
    update_board_display();
    gtk_label_set_text(GTK_LABEL(current_player_label), "Player X");
    currentPlayer = 'X';
    score_x = 0;
    score_o = 0;
    game_over = 0; // Reset game_over flag
}

void display_high_scores(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog, *content_area, *label;
    GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;
    dialog = gtk_dialog_new_with_buttons("High Scores",
                                         GTK_WINDOW(data),
                                         flags,
                                         ("_OK"),
                                         GTK_RESPONSE_NONE,
                                         NULL);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    GString *high_scores_text = g_string_new("\n=== High Scores ===\n");
    int scores[Highscore] = {0}, i;
    FILE *file = fopen("High_scores.txt", "r");
    if (file == NULL) {
        g_string_append(high_scores_text, "No high scores available.\n");
    } else {
        for (i = 0; i < Highscore; i++) {
            fscanf(file, "%d", &scores[i]);
        }
        fclose(file);

        for (i = 0; i < Highscore && scores[i] != 0; i++) {
            g_string_append_printf(high_scores_text, "%d. %d\n", i + 1, scores[i]);
        }
    }

    label = gtk_label_new(high_scores_text->str);
    g_string_free(high_scores_text, TRUE);
    gtk_container_add(GTK_CONTAINER(content_area), label);
    gtk_widget_show_all(dialog);

    g_signal_connect_swapped(dialog, "response", G_CALLBACK(gtk_widget_destroy), dialog);
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *vbox;
    GtkWidget *start_button;
    GtkWidget *highscore_button;
    GtkWidget *exit_button;

    gtk_init(&argc, &argv);

    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, "style.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                              GTK_STYLE_PROVIDER(provider),
                                              GTK_STYLE_PROVIDER_PRIORITY_USER);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Connect 4");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    current_player_label = gtk_label_new("Player X");
    gtk_box_pack_start(GTK_BOX(vbox), current_player_label, FALSE, FALSE, 0);

    grid = gtk_grid_new();
    gtk_box_pack_start(GTK_BOX(vbox), grid, TRUE, TRUE, 0);

    create_game_board(grid);

    start_button = gtk_button_new_with_label("Start New Game");
    g_signal_connect(start_button, "clicked", G_CALLBACK(start_new_game), grid);
    gtk_box_pack_start(GTK_BOX(vbox), start_button, FALSE, FALSE, 0);

    highscore_button = gtk_button_new_with_label("View High Scores");
    g_signal_connect(highscore_button, "clicked", G_CALLBACK(display_high_scores), window);
    gtk_box_pack_start(GTK_BOX(vbox), highscore_button, FALSE, FALSE, 0);

    exit_button = gtk_button_new_with_label("Exit");
    g_signal_connect(exit_button, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), exit_button, FALSE, FALSE, 0);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}