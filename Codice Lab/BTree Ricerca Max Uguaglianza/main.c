#include <stdio.h>
#include "BTree.h"
#include "item.h"


int main(){
  BTree th, ta, tc, td, tl, tp, ts, to, tq;
	BTree t1, t2, t3, t4, t5, t6, t7, t8, t9;
	int arr1[20] = {1, 2, 4, 5, 20, 6, 4, 7, 3};
	int arr2[20] = {1, 2, 4, 5, 20, 6, 4, 7, 3};

	td = buildTree(NULL, NULL, &arr1[0]);
	to = buildTree(NULL, NULL, &arr1[1]);
	tq = buildTree(NULL, NULL, &arr1[2]);
	ts = buildTree(NULL, NULL, &arr1[3]);
	tp = buildTree(NULL, NULL, &arr1[4]);
	tl = buildTree(to, tq, &arr1[5]);
	ta = buildTree(td, tl, &arr1[6]);
	tc = buildTree(tp, ts, &arr1[7]);
	th = buildTree(ta, tc, &arr1[8]);

	t4 = buildTree(NULL, NULL, &arr2[0]);
	t8 = buildTree(NULL, NULL, &arr2[1]);
	t9 = buildTree(NULL, NULL, &arr2[2]);
	t7 = buildTree(NULL, NULL, &arr2[3]);
	t6 = buildTree(NULL, NULL, &arr2[4]);
	t5 = buildTree(t8, t9, &arr2[5]);
	t2 = buildTree(t4, t5, &arr2[6]);
	t3 = buildTree(t6, t7, &arr2[7]);
	t1 = buildTree(t2, t3, &arr2[8]);

  printf("Stampa Pre order Btree");
  preOrder(th);
  printf("\n--------------------------------------------------------------\n");
  preOrder(t1);
  printf("\nInserisci elemento da cercare : ");
  Item element=inputItem();
  if(ricercaItem(th,element))
    printf("\nElmento trovato\n");
  else printf("\nElemento non trovato\n");
  Item max=maxValueNode(th);
  printf("\nIl valore massimo dell'albero : \n");
  outputItem(max);
  if(isEqualsBTree(th,t1))
    printf("Sono uguali");
  else printf("Non sono uguali");

}
