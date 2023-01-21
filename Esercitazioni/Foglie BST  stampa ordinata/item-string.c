#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

Item inputItem(){
    char *stringa=malloc(sizeof(char));
    printf("Inserisci stringa:\n");
    scanf("%s",stringa);
    return stringa;
}
void outputItem(Item item){
    char *stringa=item;
    printf("  %s  ",stringa);
}

int compareItem(Item a,Item b){
    char *str1=a;
    char *str2=b;
    return strcmp(str1,str2);
}