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
    printLeafOrderRec(bst);
    printLeafOrderIterative(bst);
    return 0;
}