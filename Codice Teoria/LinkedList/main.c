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
    //removeHead(list);
    /*
    printf("Dopo remove head , remove di ");
    outputItem(getHead(list));
    printf("\n");
    removeHead(list);
    printList(list);*/
    reverseList(list);
    printf("Reverse List  \n");
    printList(list);
    Item el;
    printf("\nInserisci elemento da eliminare\n");
    el=inputItem();
    removeListItem(list,el);
    printList(list);
    //outputItem(removeListItem(list,el));
    return 0;
}