
#include "gtk-4.0/gtk/gtk.h"
#include "string.h"
#include "stdio.h"

static GtkWidget *window;
static GtkWidget *graph;

static gboolean update_cpu_usage(GtkWidget *widget) {
    FILE *fp;
    char buffer[128];
    double cpu_usage;

    // Open stat File and read from it
    fp = fopen("/proc/stat", "r");
    // if fp == NULL then print error message
    if (fp == NULL) {
        perror("Error: Failed to open stat file");
        return FALSE;
    }

    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    // Parse CPU usage data from the line
    unsigned long user, nice, system, idle;
    sscanf(buffer, "cpu %lu %lu %lu %lu", &user, &nice, &system, &idle);
}

int main(int argc, char *argv[]) {
    // Initialize GTK
    gtk_init(&argc, &argv);

    //Create GTK window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "CPU Usage Monitor");
    gtk_window_set_default_size(GTK_WINDOW(window), 650, 250);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);


    graph = gtk_progress_bar_new();
    gtk_container_add(GTK_CONTAINER(window), graph);

    // Timer to update the CPU usage after 1000
    g_timeout_add(1000, (GSourceFunc)update_cpu_usage, graph);

    //Show all widgets
    gtk_widget_show_all(window);

    //Start GTK main loop
    gtk_main();

    return 0;
}
