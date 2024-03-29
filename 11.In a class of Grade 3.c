#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
double evaluate_expression(const char *expression);
double evaluate_term(const char **expression);
double evaluate_factor(const char **expression);
double evaluate_number(const char **expression);

int main() {
    char expression[100];
    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0';
    double result = evaluate_expression(expression);
    printf("Result: %.2f\n", result);

    return 0;
}
double evaluate_expression(const char *expression) {
    return evaluate_term(&expression);
}
double evaluate_term(const char **expression) {
    double result = evaluate_factor(expression);

    while (**expression == '*' || **expression == '/') {
        char op = **expression;
        (*expression)++; 
        double next_factor = evaluate_factor(expression);

        if (op == '*') {
            result *= next_factor;
        } else {
            if (next_factor != 0) {
                result /= next_factor;
            } else {
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    return result;
}
double evaluate_factor(const char **expression) {
    double result;

    if (isdigit(**expression)) {
        result = evaluate_number(expression);
    } else if (**expression == '(') {
        (*expression)++; 
        result = evaluate_expression(*expression);
        while (**expression != ')') {
            (*expression)++;
        }
        (*expression)++;
    } else {
        printf("Error: Invalid expression\n");
        exit(EXIT_FAILURE);
    }

    return result;
}
double evaluate_number(const char **expression) {
    double result = 0;
    while (isdigit(**expression)) {
        result = result * 10 + (**expression - '0');
        (*expression)++;
    }
    if (**expression == '.') {
        (*expression)++; 

        double fraction = 0.1;
        while (isdigit(**expression)) {
            result += fraction * (**expression - '0');
            fraction *= 0.1;
            (*expression)++;
        }
    }

    return result;
}
