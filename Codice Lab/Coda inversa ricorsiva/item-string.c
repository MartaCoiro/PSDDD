#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

#define MAX 100

Item inputItem(){
    char *stringa=malloc(sizeof(char)*MAX);
    //printf("Inserisci stringa\n");
    scanf("%s",stringa);
    return stringa;
}

void outputItem(Item item){
    char *stringa=item;
    scanf("  %s  ",stringa);
}
int compareItem(Item i1,Item i2){
    char *str1=i1;
    char *str2=i2;
    return strcmp(str1,str2);
}