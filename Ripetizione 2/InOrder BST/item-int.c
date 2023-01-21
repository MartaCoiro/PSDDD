#include <stdio.h>
#include <stdlib.h>
#include "item.h"

Item inputItem(){
    int *item=malloc(sizeof(int));
    printf("Inserisci un numero\n");
    scanf("%d",item);  //siccome è un puntatore , senza & già è l'indirizzo
    return item;
}

void outputItem(Item item){
    int * itemInt=item;
    printf(" %d ",*itemInt);
}
int compareItem(Item  item1,Item item2){
    int *num1=item1;
    int *num2=item2;
    return *num1-*num2;
}