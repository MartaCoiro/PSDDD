#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#define MAX 20

Item inputItem(){
    char * val=malloc(MAX*sizeof(char));
    printf("Immetti valore \n");
    scanf("%s",val);
    return val;
}

void outpuItem(Item item){
    char *val=item;
    printf(" %s ",val);
}

int compareItem(Item item1,Item item2){
    char  *val1=item1;
    char *val2=item2;
    return strcmp(item1,item2);
}