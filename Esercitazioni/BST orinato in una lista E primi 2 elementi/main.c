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
    printf("In Order : ");
   inOrder(bst);
   printf("\nPre Order : ");
   preOrder(bst);
   printf("__________________");
   List l=listaOrdinata(bst);
   printList(l);
   Item* element=primiDueElementi(bst);
   printf("\nI minori sono : ");
   outputItem(element[0]);
   printf(" ");
   outputItem(element[1]);
   List listaOrdinata=listaOrdinataIterativa(bst);
   printf("\nLista ordinata tramite BST iterativo : ");
   printList(listaOrdinata);

   return 0;
}