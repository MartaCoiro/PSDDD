#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"

int main(){

    List list= newList();
    printf("Inserisci valori\n");
    Item item;
    int i;
    for(i=0;i<5;i++){
        item=inputItem();
        //addHead(list,item);
        addListTail(list,item);
    }
    printList(list);
    printf("\nInserire item : ");
    Item it=inputItem();
    char* out=concateLessThenRecursive(list,it);
    printf("%s",out);
    printf("\n");
    char* outIter=concateLessThenIterative(list,it);
    printf("%s",outIter);
    Item* items=dueMinimo(list);
    printf("\nI minori sono : ");
    outputItem(items[0]);
    outputItem(items[1]);
    return 0;
    
}