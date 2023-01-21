#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "bst.h"

int main(){
    BST bst= newBTS();
    int array[]={20,10,30,5,15,25,40,3,6,35};
    int i;
    Item item;
    for(i=0;i<sizeof(array)/sizeof(int);i++){
        insertBST(&bst,&array[i]);
    }
    deleteBST(&bst,&array[1]);
    printf("Il minimo : ");
    outputItem(min(bst));
    printf("\nIl massimo : ");
    outputItem(max(bst));
    printf("\nInserisci un elemento da cercare : ");
     item=inputItem();
    if(search(bst,item)!=NULL)
        printf("Elemento trovato");
    else printf("Elemento trocato");
    return 0;
}