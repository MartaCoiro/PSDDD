#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "bst.h"

int main(){
    BST bst= newBTS();
    char array[][10]={"a","z","n","p","u","g","k"};
    int i;
    Item item;
    for(i=0;i<sizeof(array)/sizeof(array[0]);i++){
        insertBST(&bst,&array[i][0]);
    }
    char* separator="-";
    printf("\nInserisci item \n");
    Item it=inputItem();
    char* outputRecursive=concatLessThenRecursive(bst,it,separator);
    printf("\n Ricorsione %s",outputRecursive);
    char* outputIterative=concatLessThenIterative(bst,it,separator);
    printf("\n Iterazione %s ",outputIterative);

    return 0;

}