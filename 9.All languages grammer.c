#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool checkGrammar(const char *input);

int main() {
    char input[100];
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 
    if (checkGrammar(input)) {
        printf("The input string satisfies the grammar.\n");
    } else {
        printf("The input string does not satisfy the grammar.\n");
    }

    return 0;
}
bool checkGrammar(const char *input) {
    int i = 0;
    while (input[i] != '\0') {
        if (input[i] == 'a') {
            i++; 
        } else if (input[i] == 'b') {
            i++; 
        } else {
            return false; 
        }
    }
    if (i > 0 && (input[i - 1] == 'a' || input[i - 1] == 'b')) {
        return true;
    } else {
        return false;
    }
}
