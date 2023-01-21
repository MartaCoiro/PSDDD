#include <stdio.h>
#include "utils.h"
#include"item.h"

void inputArray (Item a[],int m){
	int i;
	for(i=0;i<m;i++)
        a[i]=inputItem();
		//scanf("%d",&a[i]);
}

void outputArray (Item a[],int m){
	int i;
	for(i=0;i<m;i++)
        outputItem(a[i]);
		//printf("%d ",a[i]);
}
/*
void insertSortedArray(int a[],int *n,int val){
  int i;
  for(i=*n;i>0;i--){
    if(val<a[i-1])
        a[i]=a[i-1];
    else
      break;
  }
  a[i]=val;
  *n+=1;
}


void insertionSort(int a[],int n){
  int i;
  for(i=1;i<n;)
    insertSortedArray(a,&i,a[i]);
}
*/
void bubbleSort(Item a[],int n){
  int i,j;
  for(i=1;i<n;i++)
    for(j=0;j<n-i;j++)
        if(compareItem(a[j],a[j+1])>0)
            //if(a[j]>a[j+1])
            swap(&a[j],&a[j+1]);
}
/*
int adaptiveBubbleSort(int a[],int n){
  int i,j,ordinato=0,count=0;
  for(i=1;i<n && !ordinato;i++){
    ordinato=1;
    for(j=0;j<n-i;j++){
      count++;
      if(a[j]>a[j+1]){
        swap(&a[j],&a[j+1]);
        ordinato=0;
      }
    }
  }
  return count;
}

int ricercaBin(int a[], int n, int el){
	int begin=0, center, end=n-1;
	while(end>=begin){
		center=(begin+end)/2;
		if(el==a[center])
			return center;
		else if(el<a[center])
			end=center-1;
		else if(el>a[center])
			begin=center+1;
	}
	return -1;
}
*/