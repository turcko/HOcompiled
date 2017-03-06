#include <stdlib.h>
//#include "c-sum.h" Ya no es necesario

int sum_abs(int *in, int num) {
   int i,sum;

   for (i=0,sum=0; i < num; ++i) {
       sum += abs(in[i]);
   }
   return sum;
}

void sum_abs_(int *in, int *num, int *sum)
{
   *sum = sum_abs(in, *num);
}