#include <stdio.h>
#include "bst.h"
#include "item.h"


int main(){
  BST b = newBST();
  int array[] = {20,10,30,5,15,25,40,3,6,35,2,1};
  int i;
  Item item;
  for(i = 0;i< sizeof(array)/sizeof(int);i++){
    insertBST(&b,&array[i]);
  }
  printf("MIN = ");
  outputItem(min(b));
  printf("\nMAX = ");
  outputItem(max(b));
  printf("\n");

  preOrder(b);
  printf("\n");
  // printf("\nInserire un elemento da cercare: ");
  // item = inputItem();
  // if(search(b,item) != NULL)
  //   printf("\nELEMENTO PRESENTE");
  // else
  //   printf("\nELEMENTO NON PRESENTE");
  int k = 3;
  printf("E' %d bilanciato?: %s\n", k,is_k_balanced(b,k) ? "T" : "F");
  
  print_leaf_ordered(b);
  
  return 0;


}
