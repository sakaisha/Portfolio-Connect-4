#include <gtk/gtk.h>
#include "board.h"
#include "game.h"
#include "highscore.h"

/* Global widget for the board buttons */
GtkWidget *board_buttons[num_rows][num_cols];

/* Widget to display the current player */
GtkWidget *current_player_label;

/* Function to apply CSS class to a widget */
void apply_css(GtkWidget *widget, const gchar *class_name) {
    GtkStyleContext *context;
    context = gtk_widget_get_style_context(widget);
    gtk_style_context_add_class(context, class_name);
}

/* Function to update the display of the game board */
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

/* Callback function for board button clicks */
void on_board_button_clicked(GtkWidget *widget, gpointer data) {
    if (game_over) return; // Prevent moves if the game is over

    int col = GPOINTER_TO_INT(data);
    if (playerTurn(col)) {
        scoreCheck();
        update_board_display();

        if (score_x > 0 || score_o > 0) {
            const char *winner = (score_x > score_o) ? "Player X wins!" : "Player O wins!";
            gtk_label_set_text(GTK_LABEL(current_player_label), winner);
            High_Score(); // Call to update high scores
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            char label[10];
            snprintf(label, 10, "Player %c", currentPlayer);
            gtk_label_set_text(GTK_LABEL(current_player_label), label);
        }
    }
}

/* Function to create the game board */
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

/* Function to start a new game */
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

/* Main function */
int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *vbox;
    GtkWidget *hbox;
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
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 350);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    current_player_label = gtk_label_new("Player X");
    gtk_box_pack_start(GTK_BOX(vbox), current_player_label, FALSE, FALSE, 0);

    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, TRUE);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

    grid = gtk_grid_new();
    gtk_box_pack_start(GTK_BOX(hbox), grid, TRUE, TRUE, 0);

    create_game_board(grid);

    start_button = gtk_button_new_with_label("Start New Game");
    g_signal_connect(start_button, "clicked", G_CALLBACK(start_new_game), grid);
    gtk_box_pack_start(GTK_BOX(vbox), start_button, FALSE, FALSE, 0);

    highscore_button = gtk_button_new_with_label("Score History");
    g_signal_connect(highscore_button, "clicked", G_CALLBACK(display_high_scores), window);
    gtk_box_pack_start(GTK_BOX(vbox), highscore_button, FALSE, FALSE, 0);

    exit_button = gtk_button_new_with_label("Exit");
    g_signal_connect(exit_button, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), exit_button, FALSE, FALSE, 0);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}