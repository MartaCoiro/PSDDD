#include <stdio.h>
#include <stdlib.h>
#include "item.h"

Item inputItem(){
    int *a=malloc(sizeof(int));
    printf("Immetti valore\n");
    scanf("%d",a);
    return a;
}
void outputItem(Item item){
    int *a=item;
    printf(" %d ",*a);
}

int compareItem(Item item1,Item item2){
    int *num1=item1;
    int *num2=item2;
    return *num1-*num2;
}