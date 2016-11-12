typedef struct Nameval {
    char *name;
    int value;
    Nameval *next;  /* in list */
} Nameval;

void eprintf(char *fmt, char *arg)
{
    printf(fmt, arg);
    exit(0);
}

void *emalloc(unsigned int size)
{
    void *p = malloc(size);
    if(p == NULL){
        eprintf("%s fail!", malloc);
    }
    return p;
}

/* newitem: create new item from name and value */
Nameval *newitem(char *name, int value)
{
    Nameval *newp;

    newp = (Nameval *)emalloc(sizeof(Nameval));
    newp->name = name;
    newp->value = value;
    newp->next = NULL;
    return newp;
}

/* addfront: add newp to front of listp */
Nameval *addfront(Nameval *listp, Nameval *newp)
{
    newp->next = listp;
    return newp;
}

/* addend: add newp to end fo listp */
Nameval *addend(Nameval *listp, Nameval *newp)
{
    Nameval *p;
    
    if(listp == NULL){
        return newp;
    }

    for(p = listp; p->next != NULL; p = p->next)
        ;
    
    p->next = newp;
    return listp;
}

/* lookup: sequential search for name in listp */
Nameval *lookup(Nameval *listp, char *name)
{
    for( ; listp != NULL; listp = listp->next){
        if(strcmp(name, listp->name) == 0){
            return listp;
        }
    }
    return NULL;
}

/* apply: execute fn for each element of listp */
void apply(Nameval *listp, void (*fn)(Nameval*, void*), void *arg)
{
    for( ; listp != NULL; listp = listp->next){
        (*fn)(listp, arg); // call the function
    }
}

/* printnv: print name and value using fromat in arg */
void printnv(Nameval *p, void *arg)
{
    char *fmt;
    fmt = (char *)arg;
    printf(fmt, p->name, p->value);
}

/* printlist: print all name and value of listp */
void printlist(Nameval *listp)
{
    apply(listp, printnv, "%s: %x\n");
}

/* delitem: delete first "name" from listp */
Nameval *delitem(Nameval *listp; char *name)
{
    Nameval *p;
    Nameval *prev = NULL;
    for(p = listp; p != NULL; p = p->next){
        if(strcmp(name, p->name) == 0){
            if(prev == NULL){
                listp = p->next;
            }else{
                prev->next = p->next
            }
            free(p);
            return listp;
        }
        prev = p;
    }
    eprintf("delitem: %s not in list", name); // print err adn exit
    return NULL; // can't get here
}

/* freeall: free all elements of listp */
void freeall(Nameval *listp)
{
    Nameval *next;
    for( ; listp != NULL; listp = next){
        next = listp->next;
        /* assumes name is freed elsewhere */
        free(listp);
    }
}
