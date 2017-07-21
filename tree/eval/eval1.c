typedef struct Symbol Symbol;
typedef struct Tree Tree;

struct Symbol {
    int value;
    char *name;
};

struct Tree {
    int op;  // operation code
    int value;  // value if numver
    Symbol *symbol;  // Symbol entry if variable
    Tree *left;
    Tree *right;
};

enum {  // operation codes, Tree.op
    NUMBER,
    VARIABLE,
    ADD,
    DIVIDE,
    MAX,
    ASSIGN
};

/* addop: return sum of two tree expressions */
int addop(Tree *t)
{
    return eval(t->left) + eval(t->right);
}

/* optab: operator function table */
int (*optab[])(Tree *) = {
    pushop,  // NUMBER
    pushsymop,  // VARIABLE
    addop,  // ADD
    divop,  // DIVIDE
    maxop,  // MAX
    assignop  // ASSIGN
}

/* eval: version 2: evaluate tree form operator table */
int eval(Tree *t)
{
    return (*optab[t->op])(t);
}
