typedef struct Nameval {
    char *name;
    int *value;
    struct Nameval *next;  // in chain
} Nameval;

#define NHASH 100
enum { MULTIPLIER = 31 };

Nameval symtab[NHASH];  // a symbol table

/* hash: compute hash value of string */
unsigned int hash(char *str)
{
    unsigned int h;
    unsigned char *P;
    h = 0;
    for(p = (unsigned char *)str; *p != '\0'; p++){
        h = MULTIPLIER * h + *p;
    }
    return h % NHASH;
}

/* lookup: find name in symtab, with optional create */
Nameval *lookup(char *name, int create, int value)
{
    int h;
    Nameval *sym;

    h = hash(name);
    for(sym = symtab[h]; sym != NULL; sym = sym->next){
        if(strcmp(name, sym->name) == 0){
            return sym;
        }
    }
    if(create){
        sym = (Nameval *)emalloc(sizeof(Nameval));
        sym->name = name;
        sym->value = value;
        sym-next = symtab[h];
        symtab[h] = sym;
    }
    return sym;
}
