#include "binary_search.h"

// 从filename指定的文件(文件内容见bs-1与bs-2)中读取数据存入数组a
int getnum(char const *filename, Array *a)
{
    FILE *fd = fopen(filename, "r");
    if(fd == NULL){
        perror("can not open file");
        exit(EXIT_FAILURE);
    }

    int l = '0' - 48; // 单个数字上界
    int u = '9' - 48; // 单个数字下界

    char c = fgetc(fd);
    int i;
    for(i=0; c != EOF; i++){ // 到文件尾退出
        int sum = 0;
        int sum_is_vaild = flase;
        int d = c - 48;
        while(l <= d && d <= u){ // 忽略不是数字的字符
            sum_is_vaild = true;
            sum = sum*10 + d; 
            c = fgetc(fd);
            d = c - 48;
        } 
        c = fgetc(fd);
        if(sum_is_vaild){
            //printf("%d\n", sum);
            array_append(a, sum);
        }
    }

    fclose(fd);
    printf("read num is done.\n");
    return 0;
}
