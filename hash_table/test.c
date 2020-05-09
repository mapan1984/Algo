#include "symtab.h"

int main() {
    // a symbol table
    Nameval* symtab[NHASH];
    for (int i=0; i < NHASH; i++) {
        symtab[i] = NULL;
    }

    // printf("%lu\n", sizeof(Nameval *));

    Nameval *a = put(symtab, "hello", 4);
    printf("%p --> %s:%d\n", a, a->name, a->value);

    Nameval *b = get(symtab, "hello");
    printf("%p --> %s:%d\n", b, b->name, b->value);

    Nameval *c = put(symtab, "hello", 5);
    printf("%p --> %s:%d\n", c, c->name, c->value);

    Nameval *d = get(symtab, "hello");
    printf("%p --> %s:%d\n", d, d->name, d->value);

    Nameval *e = get(symtab, "world");
    if (e == NULL) {
        printf("'world' not found");
    }

    return 0;
}
