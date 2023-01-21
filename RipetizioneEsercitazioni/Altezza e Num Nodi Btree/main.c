#include <stdio.h>
#include "BTree.h"
#include "item.h"


int main(){
  BTree bh,ba,bd,bl,bo,bq,bc,bp,bs;
  bo=buildTree(NULL,NULL,"o");
  bq=buildTree(NULL,NULL,"q");
  bd=buildTree(NULL,NULL,"d");
  bl=buildTree(bo,bq,"l");
  bp=buildTree(NULL,NULL,"p");
  bs=buildTree(NULL,NULL,"s");
  ba= buildTree(bd,bl,"a");
  bc=buildTree(bp,bs,"c");
  bh=buildTree(ba,bc,"h");

  printf("\nPre order: ");
  preOrder(bh);
  printf("\nPost Order: ");
  postOrder(bh);
  printf("\nIn order : ");
  inOrder(bh);
  printf("\nAltezza %d , nodi %d ",getAltezza(bh),getNumNodi(bh));
  return 0;

}
