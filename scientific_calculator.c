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


