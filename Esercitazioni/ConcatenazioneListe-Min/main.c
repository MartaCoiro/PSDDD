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
   /* 
    Item itemMax=massimo(list);
    printf("\nIl massimo è : ");
    outputItem(itemMax);
    return 0;
    */
   Item* minimi=dueMinimo(list);
   printf("\nI valori minimi sono : ");
    outputItem(minimi[0]);
    outputItem(minimi[1]);
   /*
   printf("\nConcatenazione\n");
   char *str=concatena(list);
   printf("%s",str);
   */
    
}