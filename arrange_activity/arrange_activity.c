/*
    Greedy algorithm solution activity arrangements
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int start;
    int finish;
} Activity;

void swap_activity(Activity *m, Activity *n)
{
    Activity tmp = *m;
    *m = *n;
    *n = tmp;
}

void show_activity(Activity *array, int n)
{
    int i;
    for(i=0; i<n; i++){
        printf("activity id=%3d, start=%3d, finish=%3d\n",
                array[i].id, array[i].start, array[i].finish);
    }
}

void qsort_activity(Activity *array, int l, int u)
{
    if(l >= u){
        return;
    }
    swap_activity(array+l, array+rand()%(u-l+1)+l);
    Activity t = array[l];
    int i = l;
    int j = u + 1;
    for(;;){
        do{
            i++;
        }while(i <= u && array[i].finish < t.finish);
        do{
            j--;
        }while(array[j].finish > t.finish);
        if(i > j){
            break;
        }
        swap_activity(array+i, array+j);
    }
    swap_activity(array+l, array+j);
    qsort_activity(array, l, j-1);
    qsort_activity(array, j+1, u);
}

void arrange_activity(Activity *array, int *accept, int n)
{
    accept[0] = 1;
    int pre = 0;
    int next;
    for(next=1; next<n; next++){
        if(array[next].start >= array[pre].finish){
            accept[next] = 1;
            pre = next;
        }else{
            accept[next] = 0;
        }
    }
}

int main()
{
    int num_activity;
    printf("input the num of activity: ");
    scanf("%d", &num_activity);

    int *accept = (int*)malloc(num_activity*sizeof(int));
    Activity *array = (Activity*)malloc(num_activity*sizeof(Activity));

    int i;
    for(i=0; i<num_activity; i++){
        array[i].id = i;
        array[i].start = rand()%100;
        array[i].finish = array[i].start + rand()%100;
    }

    qsort_activity(array, 0, num_activity-1);
    puts("all activity sort results by finish time");
    show_activity(array, num_activity);
    puts("");

    arrange_activity(array, accept, num_activity);
    puts("the selected activity sequenc");
    for(i=0; i<num_activity; i++){
        if(accept[i] == 1){
            printf("activity id=%3d, start=%3d, finish=%3d\n",
                    array[i].id, array[i].start, array[i].finish);
        }
    }

    free(accept);
    free(array);
    return 0;
}
