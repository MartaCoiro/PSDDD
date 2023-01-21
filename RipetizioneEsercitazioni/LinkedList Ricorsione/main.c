#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(){

    List list= newList();
    int i,n;
    Item item;
    printf("Inserisci valori\n");
    for(i=0;i<5;i++){
        item=inputItem();
        //addHead(list,item);
        addListTail(list,item);
    }
    printf("------------------------\n");
    printListRecursive(list);
    printf("\nInserisci Item da cercare : ");
    Item it=inputItem();
    int pos;
    if(searchItemRecursive(list,it,&pos)){
        printf("\nElemento trovato alla posizione %d ",pos);
        printf("\nE questo elemento appare %d volte ",countItemRecursive(list,it));
    }
    else printf("\nElemento non trovato");
    
    return 0;
}