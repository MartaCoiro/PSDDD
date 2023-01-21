#include <stdio.h>
#include "vettore.h"
#define MAX 5

int main(){

    int a[MAX]; 
    printf("Inserisci 5 numeri\n");
    inputArray(a,MAX);
    outputArray(a,MAX);
    
    return 0;
}