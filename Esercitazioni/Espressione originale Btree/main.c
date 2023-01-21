#include <stdio.h>
#include "BTree.h"
#include "item.h"


int main(){
  BTree th, ta, tc, td, tl, tp, ts, to, tq;
	to=buildTree(NULL, NULL, "11");
	tq=buildTree(NULL, NULL, "14");
	td=buildTree(to, tq, "+");
	ts=buildTree(NULL, NULL, "2");
	tp=buildTree(NULL, NULL, "6");
	tl=buildTree(NULL, NULL, "1");
	ta=buildTree(td, tl, "-");
	tc=buildTree(tp, ts, "*");
	th=buildTree(ta, tc, "/");
    printf("Versione ricorsiva : \n");
    printEspressioneOriginaleRecursive(th);
    return 0;

}
