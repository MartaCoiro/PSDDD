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
    printf("Printe Recursive : ");
    printListRecursive(list);
    printf("\nInserisci Itema da cercare : ");
    Item it=inputItem();
    int pos;
    if(searchItemRecursive(list,it,&pos))
        printf("La prima occorrenza dell'item si trova nella posizione %d e ce ne sono esattamente %d", pos,countNumItemRecursive(list,it));
    else printf("Elemento non trovato");
    return 0;
}