#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "bst.h"
#include "utils.h"

int main(){
    List l= newList();
    Item element;
    int i;
    printf("Inserisci gli elementi:\n ");
    for(i=0;i<5;i++){
        element=inputItem();
        addListTail(l,element);
    }
    printf("\nEcco la tua lista ");
    printList(l);
    printf("\nBubble sort : ");
    bubbleSortList(l);
    printList(l);
    adaptiveBubbleSortList(l);
    printf("\nBubble sort adattibo : ");
    printList(l);

    printf("\nBST ORDER ");
    treeSortList(l);
}