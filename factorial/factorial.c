#include <stdio.h>

/*
1 2 3 4 5
1 2 6 24 120
*/
int factorial(int n)
{
    if(n == 1){
        return 1;
    }else{
        return n * factorial(n-1);
    }
}

int main()
{
    int target;
    printf("input target: ");
    scanf("%d", &target);
    int m = factorial(target);
    printf("%d", m);
    return 0;
}
