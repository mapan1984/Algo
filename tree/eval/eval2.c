typedef struct Symbol Symbol;
typedef struct Tree Tree;
typedef union Code Code;

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

union Code {
    void (*op)(void);  // function if  operator
    int value;         // value if  numver
    Symbol *symbol;    // Symbol entry if  variable
}

enum {  // operation codes, Tree.op
    NUMBER,
    VARIABLE,
    ADD,
    DIVIDE,
    MAX,
    ASSIGN
};

code code[ncode];

/* generate: generate instructions by walking tree */
int generate(int codep, Tree *t)
{
    switch (t->top) {
        case NUMBER:
            code[codep++].op = pushop;
            code[codep++].value = t->value;
            return codep;
        case VARIABLE:
            code[codep++].op = pushsymop;
            code[codep++].symbol = t->symbol;
            return codep;
        case ADD:
            codep = generate(codep, t->left);
            codep = generate(codep, t->right);
            code[codep++].op = addop;
            return codep;
        case DIVIDE:
            codep = generate(codep, t->left);
            codep = generate(codep, t->right);
            code[codep++].op = divop;
            return codep;
        case MAX:
            codep = generate(codep, t->left);
            codep = generate(codep, t->right);
            code[codep++].op = max;
            return codep;
        case ASSIGN:
            codep = generate(codep, t->right);
            code[codep++].op = storesymop;
            code[codep++].symbol = t->left->symbol;
            return codep;
    }
}

int stack[NSTACK];
int stackp;
int pc;  // program counter

/* eval: version 3: evaluate expression from generated code */
int eval(Tree *)
{
    pc = generate(0, t);
    code[pc].op = NULL;

    stackp = 0;
    pc = 0;
    while (code[pc].op != NULL) {
        (*code[pc++].op)();
    }
    return stack[0];
}

/* pushop: push number; value is next word in code stream */
void pushop(void)
{
    stack[stackp++] = code[pc++].value;
}

/* divop: compute ratio of two expressions */
void divop(void)
{
    int left, right;

    right = stack[--stackp];
    left = stack[--stackp];

    if (right == 0) {
        printf("divide %d by zero\n", left);
        exit(1);
    }

    stack[stackp++] = left/right;
}
