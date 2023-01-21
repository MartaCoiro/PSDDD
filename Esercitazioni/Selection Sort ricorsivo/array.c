#include <stdio.h>
#include "utils.h"


void outputArray(int *a, int n){

    int i;
    for(i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}

// *n è il puntatore all'indice
//Questa funzione prende un array già ordinato e va ad inserire val al suo interno
void insertSortedArray(int *arr, int val, int *n){
    int i;
    for(i = *n; i > 0; i--)
        if(val < arr[i - 1])
            arr[i] = arr[i - 1];
        else
            break;
    
    arr[i] = val;
    (*n)++;

}


void insertionSort(int *arr, int n){
    int i;
    for(i = 1; i < n; )
        insertSortedArray(arr, arr[i], &i);
}



void inputArray(int *arr, const int n){

    int i;
    for(i = 0; i < n; i++)
        scanf("%d", arr + i);
    
}

int minimo(int *a,int n){

    int i, min = 0;
    for(i = 1; i < n; i++)
        if(a[min] > a[i])
            min = i;

    return min;
}

void selectionSortRicorsivo(int* a, int n){
    if(n==1) // caso base
        return ;
    int min=minimo(a,n);
    swap(a+0,a+min);
    selectionSortRicorsivo(a+1,n-1);
}


void selectionSort(int *a, int n){

    int i, min;
    for(i = 0; i < n - 1; i++){
        min = minimo(a + i, n - i) + i;
        swap(a + i, a + min);
    }
}

int bubbleSort (int *a, int n) {
    int i, j, cont = 0;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            cont++;
            if (a[j] > a[j + 1])
                //swap(a + j, a + j + 1);
                swap(&a[i],&a[j+1]);
        }
    }
    return cont;
}

int adaptiveBubbleSort (int *a, int n) {
    int i, j, sorted = 0, cont = 0;
    for (i = 1; i < n && sorted == 0; i++) {
        sorted = 1;
        for (j = 0; j < n - i; j++) {
            cont++;
            if (a[j] > a[j + 1]) {
                swap(a + j, a + j + 1);
                sorted = 0;
            }
        }
    }
    return cont;
}

void deletePos(int* a,int *n,int pos){
	int i=0;
	for(i=pos;i<*n-1;i++){
		//*(a+i)=*(a+i+1);
		a[i]=a[i+1];
	}
	(*n)--;
}

int searchSort(int *a,int n,int ele){
	int i=0;
	while(i<n-1 && a[i]<ele)
		i++;
	return (a[i]==ele ? i:-1);
}

int searchBin(int *a,int n,int ele){
	int begin=0,end=n-1,center;
	while(end>=begin){
		center=(begin+end)/2;
		if(a[center]==ele)
			return center;
		else if(ele<a[center])
			end=center-1;
		else if(ele>a[center])
			begin=center+1;
	}
	return -1;
}