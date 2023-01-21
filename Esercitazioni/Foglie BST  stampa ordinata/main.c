#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "bst.h"
#include "list.h"

int main(){
    BST bst= newBST();
    int array[]={20,10,30,5,15,25,40,3,6,35};
    int i;
    Item item;
    for(i=0;i<sizeof(array)/sizeof(int);i++){
        insertBST(&bst,&array[i]);
    }
    printf("\nIn order :");
    inOrder(bst);
    printf("\nLeaf  ricorsivo : ");
    printLeafOrder(bst);
    printf("\nVersione Iterativa : ");
    printLeafOrderIterative(bst);
    return 0;
}