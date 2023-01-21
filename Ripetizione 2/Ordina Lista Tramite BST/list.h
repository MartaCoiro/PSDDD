#include "item.h"
 typedef struct list *List;

 List newList(); // restituisce una lista vuota appena creata
 int isEmpt(List);
 void addHead(List,Item);
 Item removeHead(List);
 Item getHead(List);
 int sizeList(List);
 void printList(List);
Item searchList(List, Item , int *);
Item removeListItem(List, Item);
Item remvoceListItemPos(List, int);
int addListItem(List, Item,int);
int addListTail(List,Item);
void reverseList(List);
List cloneList(List);

//

struct node *minimo(struct node *p);
void selectionSortList(List list);
int bubbleSortList(List list);
int adaptiveBubbleSortList(List list);
int * concatenaListe(List,List); // concatenazione di due liste in un array
List concatenaListe2(List,List); // concatenazione di due liste in una lista


void treeSortList(List);