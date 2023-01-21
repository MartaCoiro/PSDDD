#include "item.h"
#include "utils.h"

void swap(Item *i1,Item *i2){
    Item  temp=*i1;
    *i1=*i2;
    *i2=temp;
}