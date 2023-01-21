#include <stdio.h>
#include "array.h"


#define DIM 10


int main(){

	int arr[DIM];
    int n = 5;
    int cont,ele;

    inputArray(arr, n);
	printf("Inserisci elemento da cercare\n");
	scanf("%d",&ele);
	
	printf("%d",searchBin(arr,n,ele));
	
    //cont = adaptiveBubbleSort(arr, n);

    //printf ("numero di confronti bubbleSort -> %d\n", cont);

    //adaptiveBubbleSort(arr, n);
	//printArray(arr,n);

    return 0;
}