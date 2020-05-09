#include "symtab.h"

/* hash: compute hash value of string */
unsigned int hash(char *str)
{
    unsigned int h;
    unsigned char *p;
    h = 0;
    for(p = (unsigned char *)str; *p != '\0'; p++){
        h = MULTIPLIER * h + *p;
    }
    return h % NHASH;
}

Nameval *get(Nameval *symtab[], char *name) {
    int h = hash(name);
    Nameval *sym;
    for (sym = symtab[h]; sym != NULL; sym = sym->next) {
        if (strcmp(name, sym->name) == 0) {
            return sym;
        }
    }
    return NULL;
}

Nameval *put(Nameval *symtab[], char *name, int value) {
    int h = hash(name);

    Nameval *sym = get(symtab, name);
    if (sym == NULL) {
        sym = (Nameval *)malloc(sizeof(Nameval *));
        sym->name = name;
        sym->next = symtab[h];
        symtab[h] = sym;
    }

    sym->value = value;

    return sym;
}
