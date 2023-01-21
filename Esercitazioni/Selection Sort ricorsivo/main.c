#include <stdio.h>
#include "array.h"


#define DIM 10


int main(){

	int arr[DIM];
    int n = 5;
    int cont,ele;

    inputArray(arr, n);
    printf("ok");
	selectionSortRicorsivo(arr,n);
    printf("\nDopo il selection sort ");
    outputArray(arr,n);
	
    //cont = adaptiveBubbleSort(arr, n);

    //printf ("numero di confronti bubbleSort -> %d\n", cont);

    //adaptiveBubbleSort(arr, n);
	//printArray(arr,n);

    return 0;
}