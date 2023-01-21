#include <stdio.h>
#include "array.h"
#include "item.h"

#define DIM 10


int main(){

	Item array[DIM];
   int n = 4;
   int pos;
   Item ele;

    inputArray(array, n);
    selectionSortRic(array, n);
    printArray(array,n);

   return 0;
}