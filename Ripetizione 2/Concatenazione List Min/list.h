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

Item minimo(List);
Item massimo(List);
Item dueMinimo(List);
char *concatena(List);
char* concateLessThenRecursive(List,Item);
char* concateLessThenIterative(List,Item);