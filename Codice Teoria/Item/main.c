#include<stdio.h>
#include<stdlib.h>
#include "array.h"
#include "item.h"
#define DIM 5

int main(){

printf("Inserire gli item\n");
 int n=5;
  Item a[DIM];
  inputArray(a,n);
  bubbleSort (a,n);
  outputArray (a,n);



    return 0;
}
