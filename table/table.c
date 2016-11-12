#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int *base;
} Table;

#define ELEMENT(Table, r, c) (*(Table.base + (r)*Table.col + (c)))
 
void init_table(Table *t, int row, int col)
{
    t->row = row;
    t->col = col;
    t->base = (int *)malloc(sizeof(int)*row*col);
    if (t->base == NULL){
        printf("init table falue failed");
    }
}

int main()
{
    int i, j;
    int row=3, col=4;
    Table t;
    init_table(&t, row, col);
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
           ELEMENT(t, i, j) = i;
        }
    }
    
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            printf("%d", ELEMENT(t, i, j));
        }
        printf("\n");
    }

    return 0;
}
