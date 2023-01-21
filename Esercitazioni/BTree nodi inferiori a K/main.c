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
  printf("\nVisita Pre Order : ");
  preOrder(bh);
  printf("\nVisita in order : ");
  inOrder(bh);

 printf("\nInserisci un carattere : ");
 Item item=inputItem();
 char *separator="-";
 char* str=concatNodeLessThen(bh,item,separator);
 printf("\nEcco l'output : %s ",str); 
 printf("\nOra inserisci l'input per la versione iterativa ");
 Item item2=inputItem();
 char* sep=",";
 char* str1=concatNodeLessThenIerativa(bh,item2,sep);
 printf("\nEcco l'output : %s",str1);

 return 0;

}
