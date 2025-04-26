/* symbol_table.c */
#include <string.h>
#include <stdio.h>
#include "symtable.h"

Sym symtab[SYMTAB_SIZE];
int symi = 0;

void insertSymbol(const char *n, const char *t) {
    strcpy(symtab[symi].name, n);
    strcpy(symtab[symi].type, t);
    symtab[symi].init = 0;
    symi++;
}

int lookupSymbol(const char *n) {
    for (int i = 0; i < symi; i++)
        if (strcmp(symtab[i].name, n) == 0)
            return i;
    return -1;
}

void updateSymbol(const char *n, int v) {
    int idx = lookupSymbol(n);
    if (idx >= 0) {
        symtab[idx].val  = v;
        symtab[idx].init = 1;
    }
}

void printSymbolTable(void) {
    printf("\n--- Symbol Table ---\n");
    printf("Name\tType\tValue\tInit\n");
    for (int i = 0; i < symi; i++) {
        printf("%s\t%s\t%d\t%d\n",
               symtab[i].name,
               symtab[i].type,
               symtab[i].val,
               symtab[i].init);
    }
}
