#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "bst.h"

int main(){
    BST bst= newBTS();
    //int array[]={20,10,30,5,15,25,40,3,6,35};
    //char array[][9]={"a","b","t","z","s","e","l","h","n"};
    char array[][50]={"c", "i", "a", "o","b","d","m"};

    int i;
    Item item;
    for(i=0;i<sizeof(array)/sizeof(array[0]);i++){
        insertBST(&bst,&array[i][0]);
    }
    printf("\nIn order : ");
    inOrder(bst);
    printf("\nPre Order : ");
    preOrder(bst);
    printf("\nPost Order : ");
    postOrder(bst);
    printf("\n");
   
    
   printf("\nInserire item : ");
   Item item1=inputItem();
   char* sep="-";
   char* stringa=concatItemLessThenRic(bst,item1,sep);
   printf("\nLa stringa generata risulata essere : %s ",stringa);
   char* stringaIterativa=concatItemLessThenIterativa(bst,item1,sep);
   printf("\nString con funzione iterativa : %s",stringaIterativa);
   return 0;
}