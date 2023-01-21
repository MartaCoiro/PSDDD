#include "utils.h"
#include "item.h"

void swap(Item *a, Item *b){
   Item temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

Item modificaItem(Item *e){       
   Item item = inputItem();
   *e = item;
}
