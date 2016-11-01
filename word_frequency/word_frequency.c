#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node *nodeptr;
typedef struct node {
    char *word;
    int count;
    nodeptr next;
} node;

// 散列表大小
#define NHASH 29989
// 乘数
#define MULT 31

nodeptr bin[NHASH]; 

// 将单词映射为一个小于NHASH的正整数
unsigned int hash(char *p)
{
    unsigned int h = 0;
    for(; *p; p++){
        h = MULT * h + *p;
    }
    return h % NHASH;
}

/*
 * 增加单词的计数值
 * 如果散列表中没有这个单词，对单词进行初始化
 */
void incword(char *s)
{
    unsigned int h = hash(s);
    nodeptr p;
    for(p = bin[h]; p != NULL; p = p->next){
        if(strcmp(s, p->word) == 0){
            (p->count)++;
            return;
        }
    }
    p = (nodeptr)malloc(sizeof(node));
    p->count = 1;
    p->word = (char *)malloc(strlen(s)*sizeof(char)+1);
    strcpy(p->word, s);
    p->next = bin[h];
    bin[h] = p;
}

int main()
{
    int i;
    for(i=0; i<NHASH; i++){
        bin[i] = NULL;
    }
    char buf[20]; 
    while(scanf("%s", buf) != EOF){
        incword(buf);
    }
    nodeptr p;
    for(i=0; i<NHASH; i++){
        for(p=bin[i]; p != NULL; p=p->next){
            printf("%s : %d\n", p->word, p->count);
        }
    }
    return 0;
}
