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

