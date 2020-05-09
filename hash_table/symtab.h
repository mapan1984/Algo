#ifndef SYMTAB_H_
#define SYMTAB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval {
    char *name;
    int value;
    struct Nameval *next;  // in chain
} Nameval;

#define NHASH 100

enum { MULTIPLIER = 31 };

unsigned int hash(char *str);

Nameval *get(Nameval *symtab[], char *name);
Nameval *put(Nameval *symtab[], char *name, int value);

#endif
