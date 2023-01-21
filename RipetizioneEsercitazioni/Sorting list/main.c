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
    printList(list);
    printf("\n");
    bubbleSort(list);
    printf("\nDopo il Sort : ");
    printList(list);
    return 0;
}