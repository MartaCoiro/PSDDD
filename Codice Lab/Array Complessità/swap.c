#include "utils.h"

void swap(Item *item1,Item *item2){
    Item temp=item1;
    *item1=item2;
    *item2=temp;
}