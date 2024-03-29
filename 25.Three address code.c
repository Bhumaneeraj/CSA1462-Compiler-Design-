#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to generate three address code
void generateThreeAddressCode(char *expression) {
    char op;
    char result[10], arg1[10], arg2[10];
    int i = 0, j = 0;

    // Extracting the operands and operator from the expression
    while (expression[i] != '\0') {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            op = expression[i];
            arg1[j] = '\0';
            j = 0;
        } else {
            if (isalnum(expression[i])) {
                if (op == '\0') {
                    arg1[j++] = expression[i];
                } else {
                    arg2[j++] = expression[i];
                }
            }
        }
        i++;
    }
    arg2[j] = '\0';

    // Generating the three address code
    strcpy(result, "t1");
    printf("%s = %s %c %s\n", result, arg1, op, arg2);
}

int main() {
    char expression[100];

    // Taking input expression from the user
    printf("Enter the expression: ");
    fgets(expression, 100, stdin);

    // Removing the trailing newline character from fgets
    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }

    // Generating three address code for the expression
    generateThreeAddressCode(expression);

    return 0;
}
