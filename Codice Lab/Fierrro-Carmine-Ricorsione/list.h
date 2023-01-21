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
//Funzioni Ricorsive
void printListRec(List);
Item searchListRec(List,Item,int *); // cerca un item in una lista
int countItemListRec(List,Item);//conta il numero di volte che appare un item in una lista
void destroyListRec(List); // dealloca tutti gli elementi di una lista