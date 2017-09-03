#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int row;
    int col;
    int *base;
} IntTable;
 
typedef struct {
    int row;
    int col;
    char *base;
} CharTable;

void init_int_table(IntTable *t, int row, int col)
{
    t->row = row;
    t->col = col;
    t->base = (int *)malloc(sizeof(int)*row*col);
    if (t->base == NULL){
        printf("init table falue failed");
    }
}

void init_char_table(CharTable *t, int row, int col)
{
    t->row = row;
    t->col = col;
    t->base = (char *)malloc(sizeof(char)*row*col);
    if (t->base == NULL){
        printf("init table falue failed");
    }
}

#define ELEMENT(table, r, c) (*(table->base + (r)*table->col + (c)))

int lcs_length(char *x, char *y, IntTable *c, CharTable *b)
{
    int i, j;
    int m = strlen(x);
    int n = strlen(y);
    //printf("m = %d, n = %d\n", m, n);
    
    // 在原字符串前加一个空白字符，让字符下标从1开始
    char *nx = (char *)malloc(sizeof(char) * (m+2));
    char *ny = (char *)malloc(sizeof(char) * (n+2));
    strcpy(nx, " ");
    strcat(nx, x);
    strcpy(ny, " ");
    strcat(ny, y);
    //printf("nx = \"%s\" \nny = \"%s\"\n", nx, ny);

    // 初始化table c， b
    init_int_table(c, m+1, n+1);
    init_char_table(b, m+1, n+1);

    // base solusion
    for(i=1; i<=m; i++){
        ELEMENT(c, i, 0) = 0;
    }
    for(j=0; j<=n; j++){
        ELEMENT(c, 0, j) = 0;
    }

    for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){
            if(nx[i] == ny[j]){
                ELEMENT(c, i, j) = ELEMENT(c, i-1, j-1) + 1;
                ELEMENT(b, i, j) = 'y';
            }else if(ELEMENT(c, i-1, j) >= ELEMENT(c, i, j-1)){
                ELEMENT(c, i, j) = ELEMENT(c, i-1, j);
                ELEMENT(b, i, j) = 'k';
            }else{
                ELEMENT(c, i, j) = ELEMENT(c, i, j-1);
                ELEMENT(b, i, j) = 'h';
            }
        }
    }

    /*
    for(i=0; i<=m; i++){
        for(j=0; j<=n; j++){
            if(i != 0 && j != 0){
                printf("[%d %c]", ELEMENT(c, i, j), ELEMENT(b, i, j));
            }else{
                printf("[%d  ]", ELEMENT(c, i, j));
            }
        }
        printf("\n");
    }
    */

    free(nx);
    free(ny);

    return ELEMENT(c, m, n);
}

void print_lcs(CharTable *b, char *x, int len_x, int len_y)
{
    if(len_x == 0 || len_y == 0){
        return;
    }
    if(ELEMENT(b, len_x, len_y) == 'y'){
        print_lcs(b, x, len_x-1, len_y-1);
        // 记得x下标从1开始，实际下标-1
        printf("%c", x[len_x-1]);
    }else if(ELEMENT(b, len_x, len_y) == 'k'){
        print_lcs(b, x, len_x-1, len_y);
    }else{
        print_lcs(b, x, len_x, len_y-1);
    }
}

int main()
{
    char *x = "cbdab";
    char *y = "dcba";
    int len_x = strlen(x);
    int len_y = strlen(y);
    IntTable c;
    CharTable b;

    int rs = lcs_length(x, y, &c, &b);
    printf("lcs_length = %d\n", rs);

    print_lcs(&b, x, len_x, len_y);

    // 测试时间
    int i;
    time_t start = time(NULL);
    for(i=0; i<10000; i++){
        lcs_length(x, y, &c, &b);
    }
    double space = difftime(time(NULL), start);
    printf("time = %f ms", space*0.001);

    return 0;
}

