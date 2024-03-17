#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0)
        return a / b;
    else {
        printf("Error: Division by zero\n");
        exit(1);
    }
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

int main() {
    int choice;
    double num1, num2, result;

    printf("Simple Scientific Calculator\n");
    printf("----------------------------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    switch (choice) {
        case 1:
            result = add(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 4:
            result = divide(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 5:
            result = power(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}
