#include <stdio.h>
#include <string.h>

#define MAX_SYMBOLS 100

struct SymbolEntry {
    char name[50];
    int value;
};


struct SymbolTable {
    struct SymbolEntry entries[MAX_SYMBOLS];
    int size;
};

void initSymbolTable(struct SymbolTable* table) {
    table->size = 0;
}

int insertSymbol(struct SymbolTable* table, const char* name, int value) {
    if (table->size >= MAX_SYMBOLS) {
        return 0; // Table is full
    }

    for (int i = 0; i < table->size; i++) {
        if (strcmp(name, table->entries[i].name) == 0) {
            table->entries[i].value = value;
            return 1; 
        }
    }
    strncpy(table->entries[table->size].name, name, sizeof(table->entries[table->size].name));
    table->entries[table->size].value = value;
    table->size++;
    return 1;
}

int lookupSymbol(struct SymbolTable* table, const char* name) {
    for (int i = 0; i < table->size; i++) {
        if (strcmp(name, table->entries[i].name) == 0) {
            return table->entries[i].value;
        }
    } 
    return -1;
}

int main() {
    struct SymbolTable symbolTable;
    initSymbolTable(&symbolTable);

    insertSymbol(&symbolTable, "variable1", 42);
    insertSymbol(&symbolTable, "variable2", 56);

    int value1 = lookupSymbol(&symbolTable, "variable1");
    int value2 = lookupSymbol(&symbolTable, "variable2");
    int value3 = lookupSymbol(&symbolTable, "variable3");

    printf("Value of variable1: %d\n", value1); // Output: 42
    printf("Value of variable2: %d\n", value2); // Output: 56
    printf("Value of variable3: %d\n", value3); // Output: -1 (not found)

    return 0;
}
