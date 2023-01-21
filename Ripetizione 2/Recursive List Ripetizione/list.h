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

void printListRecursive(List);
Item searchItemRecursive(List,Item,int*);  //int* serve per la posizione dell'item
int countNumItemRecursive(List,Item);
void destroyListRecursive(List);

void printListRec(List);
Item searchItemListRec(List,Item,int*);
int countItemListRec(List,Item);



