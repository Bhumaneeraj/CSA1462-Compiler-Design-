#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SYMBOLS 100
typedef struct {
    char name[20];
    int address;
} SymbolEntry;
typedef struct {
    SymbolEntry entries[MAX_SYMBOLS];
    int count;
} SymbolTable;
void initialize_table(SymbolTable *table);
void insert_symbol(SymbolTable *table, const char *name, int address);
int find_symbol(SymbolTable *table, const char *name);
void display_table(SymbolTable *table);

int main() {
    SymbolTable table;
    initialize_table(&table);

    insert_symbol(&table, "var1", 100);
    insert_symbol(&table, "var2", 200);
    insert_symbol(&table, "var3", 300);

    printf("Symbol table after insertions:\n");
    display_table(&table);

    int address = find_symbol(&table, "var2");
    if (address != -1) {
        printf("Address of var2: %d\n", address);
    } else {
        printf("Symbol not found.\n");
    }

    return 0;
}
void initialize_table(SymbolTable *table) {
    table->count = 0;
}
void insert_symbol(SymbolTable *table, const char *name, int address) {
    if (table->count < MAX_SYMBOLS) {
        strcpy(table->entries[table->count].name, name);
        table->entries[table->count].address = address;
        table->count++;
    } else {
        printf("Symbol table is full. Cannot insert more symbols.\n");
    }
}
int find_symbol(SymbolTable *table, const char *name) {
    for (int i = 0; i < table->count; i++) {
        if (strcmp(table->entries[i].name, name) == 0) {
            return table->entries[i].address;
        }
    }
    return -1; 
}
void display_table(SymbolTable *table) {
    printf("Name\tAddress\n");
    for (int i = 0; i < table->count; i++) {
        printf("%s\t%d\n", table->entries[i].name, table->entries[i].address);
    }
}
