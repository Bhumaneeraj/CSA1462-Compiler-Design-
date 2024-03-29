#include <stdio.h>
#include <ctype.h>
int expr(const char *input);
int term(const char *input);
int factor(const char *input);

int main() {
    char input[100];
    printf("Enter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    int result = expr(input);
    printf("Result: %d\n", result);

    return 0;
}
int expr(const char *input) {
    int result = term(input); 
    while (*input == '+' || *input == '-') {
        char op = *input;
        input++;
        int term_value = term(input);
        if (op == '+') {
            result += term_value;
        } else {
            result -= term_value;
        }
    }

    return result;
}
int term(const char *input) {
    int result = factor(input); 
    while (*input == '*' || *input == '/') {
        char op = *input;
        input++;
        int factor_value = factor(input);
        if (op == '*') {
            result *= factor_value;
        } else {
            if (factor_value != 0) {
                result /= factor_value;
            } else {
                printf("Error: Division by zero\n");
                return 0;
            }
        }
    }

    return result;
}
int factor(const char *input) {
    int result;
    if (isdigit(*input)) {
        sscanf(input, "%d", &result);
        while (isdigit(*input)) {
            input++;
        }
    } else if (*input == '(') { 
        input++; 
        result = expr(input);
        if (*input == ')') {
            input++; 
        } else {
            printf("Error: Missing closing parenthesis\n");
            return 0;
        }
    } else {
        printf("Error: Invalid input\n");
        return 0;
    }

    return result;
}
