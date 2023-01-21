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
    bs=buildTree(NULL,NULL,"s"); //s
    ba= buildTree(bd,bl,"a"); //a
    bc=buildTree(bp,bs,"c");
    bh=buildTree(ba,bc,"h");

    BTree th,ta,td,tl,to,tq,tc,tp,ts;
    to=buildTree(NULL,NULL,"o");
    tq=buildTree(NULL,NULL,"q");
    td=buildTree(NULL,NULL,"d");
    tl=buildTree(to,tq,"l");
    tp=buildTree(NULL,NULL,"p");
    ts=buildTree(NULL,NULL,"s"); //s
    ta= buildTree(td,tl,"a"); //a
    tc=buildTree(tp,ts,"c");
    th=buildTree(ta,tc,"j");

    printf("\nPre order: ");
    preOrder(bh);
    printf("\nPost Order: ");
    postOrder(bh);
    printf("\nIn order : ");
    inOrder(bh);
    if(isEqualsTreeRecursive(bh,th)){
      printf("\nRicorsione : Alberi uguali");
    }else{
      printf("\nNon uguali");
    }
    if(isEqualsTreeIterative(bh,th)){
      printf("\nIterazione : Alberi uguali");
    }else{
      printf("\nNon uguali");
    }
    printf("\nInserire Item ");
    Item it=inputItem();
    if(searchItemRecursive(bh,it)){
      printf("\nRicorsivo , item trovato");
    }else{
      printf("\nRicorsivo Item non trovato");
    }
    if(searchItemIterative(bh,it)){
      printf("\nIterativo , item trovato");
    }else{
      printf("\niterativo Item non trovato");
    }
    return 0;
}
