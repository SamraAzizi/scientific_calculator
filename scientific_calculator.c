#include <gtk/gtk.h>

double num1 = 0, num2 = 0, result = 0;
char operator = '\0';

void calculate() {
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0)
                result = num1 / num2;
            else
                g_print("Error: Division by zero\n");
            break;
        case '^':
            result = pow(num1, num2);
            break;
        default:
            break;
    }
}

void clear() {
    num1 = 0;
    num2 = 0;
    result = 0;
    operator = '\0';
}

void button_clicked(GtkWidget *widget, gpointer data) {
    char *label = gtk_button_get_label(GTK_BUTTON(widget));
    char *display_text = gtk_label_get_text(GTK_LABEL(data));
    char buffer[32];

    if (label[0] >= '0' && label[0] <= '9') {
        strcat(display_text, label);
    } else if (label[0] == 'C') {
        strcpy(display_text, "");
        clear();
    } else if (label[0] == '=') {
        num2 = atof(display_text);
        calculate();
        sprintf(buffer, "%.2f", result);
        strcpy(display_text, buffer);
        clear();
    } else {
        num1 = atof(display_text);
        operator = label[0];
        strcpy(display_text, "");
    }

    gtk_label_set_text(GTK_LABEL(data), display_text);
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *label;
    GtkWidget *buttons[16];
    char *button_labels[16] = {"7", "8", "9", "/", "4", "5", "6", "*", "1", "2", "3", "-", "C", "0", "=", "+"};

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Scientific Calculator");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 200, 250);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    label = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 4, 1);

    for (int i = 0; i < 16; i++) {
        buttons[i] = gtk_button_new_with_label(button_labels[i]);
        gtk_grid_attach(GTK_GRID(grid), buttons[i], i % 4, i / 4 + 1, 1, 1);
        g_signal_connect(buttons[i], "clicked", G_CALLBACK(button_clicked), label);
    }

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
