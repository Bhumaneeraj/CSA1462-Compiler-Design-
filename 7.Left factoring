#include <stdio.h>
#include <string.h>

int main() {
    int k, i, a = 0, count = 0, lim, back = 0;
    int array[20];
    char production[100];
    char s[20][20];
    
    printf("Enter Production: ");
    fgets(production, sizeof(production), stdin);
    production[strcspn(production, "\n")] = '\0';
    
    char f0 = production[0];
    char f1 = production[5];
    char sf0[2];
    char sf1[2];
    char alpha[2];
    char first[3];
    
    sf0[0] = f0;
    sf0[1] = '\0';
    sf1[0] = f1;
    sf1[1] = '\0';
    strcpy(alpha, sf1);
    strcat(sf1, sf0);
    strcpy(first, sf1);
    strcat(first, "'");
    
    char sf2[5];
    char sf3[10];
    
    strcpy(sf2, sf0);
    strcat(sf2, " -> ");
    strcpy(sf3, sf2);
    strcat(sf3, first);
    
    char str1[2] = "|";
    
    int n = strlen(production);
    for (i = 0; i < n; i++) {
        strcpy(s[i], "");
        s[i][0] = production[i];
        s[i][1] = '\0';
    }
    
    for (i = 0; i < n; i++) {
        if (strcmp(s[i], str1) == 0) {
            k = i;
            array[a] = k;
            a = a + 1;
            count = count + 1;
        }
    }
    
    for (a = 0; a < count; a++) {
        lim = array[a];
        lim = lim + 1;
        
        if (strcmp(s[lim], alpha) == 0) {
            
        } else {
            back = 1;
        }
    }
    
    char line2[10];
    char cmn[5];
    
    strcpy(line2, sf0);
    strcat(line2, "' -> ");
    strcpy(cmn, sf0);
    strcat(cmn, "'");
    
    char splt[100];
    char parts[2][100];
    char part1[100];
    char part2[100];
    char spltstr[100];
    char lnew[100];
    
    strcpy(splt, production);
    char *token = strtok(splt, "->");
    strcpy(part1, token);
    token = strtok(NULL, "->");
    strcpy(part2, token);
    strcpy(spltstr, part2);
    char *ptr = strstr(spltstr, alpha);
    while (ptr != NULL) {
        strcpy(ptr, ptr + strlen(alpha));
        ptr = strstr(spltstr, alpha);
    }
    strcpy(lnew, line2);
    strcat(lnew, spltstr);
    
    printf("Your answer is:\n");
    if (back == 0) {
        printf("%s\n", sf3);
        printf("%s\n", lnew);
    } else {
        printf("No left factoring available\n");
    }
    
    return 0;
}
