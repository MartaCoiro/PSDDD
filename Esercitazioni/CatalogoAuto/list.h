#include "item.h"
 typedef struct list *List;

 List newList(); // restituisce una lista vuota appena creata
 int isEmpt(List);
 void addHead(List,Item);
 Item removeHead(List);
 Item getHead(List);
 int sizeList(List);
 void printList(List);
Item searchListItem(List, Item , int *);
Item removeListItem(List, Item);
Item remvoceListItemPos(List, int);
int addListItem(List, Item,int);
int addListTail(List,Item);
void reverseList(List);
List cloneList(List);
void selectionSortList(List);