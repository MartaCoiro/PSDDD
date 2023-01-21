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


void merge(int *a1,int *a2,int n1,int n2,int *a){
    int i,j,k; // i scorre a1, j scorre a2, e k scorre a
    int b[n1+n2]; //array di appoggio

    for(i=0,j=0,k=0;i<n1 && j<n2;k++){
        if(a1[i]<=a2[j]){
            b[k]=a1[i++];
        }
        else{ 
            b[k]=a2[j++];
        }
    }
    for(;i<n1;i++,k++)
        b[k]=a1[i];
     for(;j<n2;j++,k++)
        b[k]=a2[j];
    for(k=0;k<n1+n2;k++)
        a[k]=b[k];
}

void mergeSort(int *a,int n){
    if(n>1){
        mergeSort(a,n/2); //prima parte dell'array
        mergeSort(a+n/2,n-n/2); //seconda parte dell'array
        merge(a,a+n/2,n/2,n-n/2,a);
    }
}