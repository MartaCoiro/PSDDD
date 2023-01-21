#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "array.h"
#include "utils.h"

void inputArray(Item *array,int n){
    int i;
    for(i=0;i<n;i++){
        array[i]=inputItem();
    }
}

void outputArray(Item *array,int n){
    int i;
    for(i=0;i<n;i++){
        outputItem(array[i]);
    }
    printf("\n");
}

int bubbleSort(Item *array,int n){
    int i,j;
    int count=0;
    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            count++;
            if(compareItem(array[j],array[j+1])>0){
                swap(&array[j],&array[j+1]);
            }
        }
    }
    return count;
}
int adaptiveBubbleSort(Item *a,int n){
    int i,j;
    int count=0;
    int ordinato=0;
    for(i=1;i<n && !ordinato;i++){
        ordinato=1;
        for(j=0;j<n-i;j++){
            count++;
            if(compareItem(a[j],a[j+1])){
                swap(&a[j],&a[j+1]);
                ordinato=0;
            }
        }
    }
    return count;
}
int minimo(Item *a,int n){
    int i;
    int min=0;
    for(i=1;i<n;i++){
        if(compareItem(a[min],a[i])>0){
            min=i;
        }
    }
    return min;
}
void selectionSort(Item *a,int n){
    int i,min;
    for(i=0;i<n-1;i++){
        min=minimo(a[i],n-i)+i;
        swap(a[i],a[min]);
    }
}
void selectionSortRicorsiva(Item *a,int n){
    if(n==1)  //caso base, array di un solo elemento
        return;
    int min;
    min=minimo(a+1,n-1)+1;
    if(compareItem(a[min],a[0])<0){
        swap(a[0],a[min]);
    }
    selectionSortRicorsiva(a+1,n-1);
}

void insertSortedArray(Item * a,Item val,int *n){
    int i;
    for(i=*n;i>0;i--){
        if(compareItem(val,a[i-1])<0){
            a[i]=a[i-1];
        }
        else
            break;;
    }
    a[i]=val;
    (*n)++;
}

void insertionSort(Item *a,int n){
    int i;
    for(i=1;i<n;){
        insertSortedArray(a,a[i],&i);
    }
}

void deletePos(Item *a, int *n, int pos){
   int i;
   for(i = pos; i<*n-1; i++)
      a[i]=a[i+1];
   (*n)--; 
}

int searchSort(Item *a,int n,Item ele){
	int i=0;
   while(i<n-1 &&(compareItem(a[i], ele) < 0))
	   i++;
   if(compareItem(a[i], ele) == 0)
      return  i;
   return -1;
}

int searchBinary(Item *a,int n,Item ele){
	int begin=0,end=n-1,center;
	while(end>=begin){
		center=(begin+end)/2;
      if(compareItem(a[center],ele ) == 0)  
			return center;
      else if (compareItem(ele,a[center]) < 0) 
			end=center-1;
		else if (compareItem(ele,a[center]) > 0) 
			begin=center+1;
	}
	return -1;
}

