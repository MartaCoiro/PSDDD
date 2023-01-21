#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "item.h"
#define MAX 100
Item inputItem(){
    //allocare spazio per un ARRAY DI 100 CARATTERI
    char *a=malloc(sizeof(char)*MAX);
    scanf("%s",a);
    return a;
}
void outputItem(Item item){
    char *stringa=item;
    printf(" %s\n",stringa);

}
int compareItem(Item item1 ,Item item2){
    char *stringa1=item1;
    char *stringa2=item2;
    return strcmp(stringa1,stringa2);

}

char* toString(Item item){
    char* str=item;
    return str;
}