#include <stdio.h>
#include <stdlib.h>


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

/* eval: version 1: evaluate tree expression */
int eval(Tree *t)
{
    int left, right;

    switch (t->op) {
        case NUMBER:
            return t->value;
        case VARIABLE:
            return t->symbol->value;
        case ADD:
            return eval(t->left) + eval(t->right);
        case DIVIDE:
            left = eval(t->left);
            right = eval(t->right);
            if (right == 0) {
                printf("divide %d by zero", left);
                exit(1);
            }
            return left/right;
        case MAX:
            left = eval(t->left);
            right = eval(t->right);
            return left > right ? left : right;
        case ASSIGN:
            t->left->symbol->value = eval(t->right);
            return t->left->symbol->value;
        default:
            printf("op not found");
            exit(2);
    }
}
