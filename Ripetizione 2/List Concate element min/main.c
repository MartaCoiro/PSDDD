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
    printf("\nL'elemento minimo : ");
    outputItem(getMin(list));
    printf("\nL'elelemnto massimo : ");
    outputItem(getMax(list));
    printf("\nInserire un item ");
    Item it=inputItem();
    printf("\nConcatenazione itertiva : ");
    char* str=concateItemLessThenRecursive(list,it);
    printf("%s",str);
    char* str1=concateItemLessThenRecursive(list,it);
    printf("\nConcatenzione Iterativa : "),
    printf("%s",str1);
    return 0;
}