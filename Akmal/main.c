#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "patient.h"

// Function to add patient to database
void add_patient_to_database() {
    // Implement logic to add patient to database
    printf("Adding patient to database...\n");
    return;
}

// Function to display patient information from database
void display_patient_info_from_database() {
    // Implement logic to display patient information from database
    printf("Displaying patient information...\n");
    return;
}

// Callback function for adding patient
void add_patient(GtkWidget *widget, gpointer data) {
    add_patient_to_database();
    GtkWidget *message = gtk_message_dialog_new(GTK_WINDOW(widget), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Patient added successfully");
    gtk_dialog_run(GTK_DIALOG(message));
    gtk_widget_destroy(message);
}

// Callback function for displaying patient information
void display_patient_info(GtkWidget *widget, gpointer data) {
    display_patient_info_from_database();
    GtkWidget *message = gtk_message_dialog_new(GTK_WINDOW(widget), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Patient information displayed successfully");
    gtk_dialog_run(GTK_DIALOG(message));
    gtk_widget_destroy(message);
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *add_button;
    GtkWidget *display_button;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Patient Management System");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    add_button = gtk_button_new_with_label("Add Patient");
    g_signal_connect(add_button, "clicked", G_CALLBACK(add_patient), NULL);
    gtk_grid_attach(GTK_GRID(grid), add_button, 0, 0, 1, 1);

    display_button = gtk_button_new_with_label("Display Patient Info");
    g_signal_connect(display_button, "clicked", G_CALLBACK(display_patient_info), NULL);
    gtk_grid_attach(GTK_GRID(grid), display_button, 1, 0, 1, 1);

    gtk_widget_show_all(window);

    gtk_main();

    return EXIT_SUCCESS;
}

