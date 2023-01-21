#include <stdio.h>
#include "array.h"


#define DIM 10


int main(){

	
    int a[DIM];
    inputArray(a,DIM);
    mergeSort(a,DIM);
    outputArray(a,DIM);

    return 0;
}