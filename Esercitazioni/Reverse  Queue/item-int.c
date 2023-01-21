#include <stdio.h>
#include <stdlib.h>
#include "item.h"
Item inputItem(){
    //allocare spazio per un intero
    int *a=malloc(sizeof(int));
    scanf("%d",a);
    return a;
}
void outputItem(Item item){
    
    int *a=item;
    printf(" %d ",*a);

}
int compareItem(Item item1 ,Item item2){
    int *intero1=item1;
    int *intero2=item2;
    return *intero1-*intero2;

}