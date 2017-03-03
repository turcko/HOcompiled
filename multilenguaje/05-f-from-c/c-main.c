#include <stdio.h>
//#include "c-sum.h"
#define NUM 200

extern void sum_abs_(int* inp, int* num, int* asum);

int main(int argc, char **argv)
{
    int data[NUM], num, i;
    int res;

    num = NUM;
    for (i=0; i < num; i++) {
        data[i] = i - 100 + 1;  /* NOTE: difference in array numbering */  
    }

    sum_abs_(data, &num, &res);
    printf("sum=%d\n", res);
    return 0;
}
