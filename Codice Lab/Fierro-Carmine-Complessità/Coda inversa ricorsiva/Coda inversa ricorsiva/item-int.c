#include <stdio.h>
#include <stdlib.h>
#include "item.h"

Item inputItem(){
    int *itemInt=malloc(sizeof(int));
    printf("Inserisci valore\n");
    scanf("%d",itemInt);
    return itemInt;
}
void outputItem(Item item){
    int *itemInt=item;
    printf("   %d   ",*itemInt);
}

int compareItem(Item item1,Item item2){
    int *num1=item1;
    int *num2=item2;
    return *num1-*num2;
}