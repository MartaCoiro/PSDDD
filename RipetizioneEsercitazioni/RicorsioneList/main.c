#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(){

    List list= newList();
    int i,n;
    Item item;
    printf("Inserisci valori\n");
    for(i=0;i<5;i++){
        item=inputItem();
        //addHead(list,item);
        addListTail(list,item);
    }
    printf("------------------------\n");
    printList(list);
	printf("\nInserisci item da cercare : ");
	int pos;
	Item it=inputItem();
	Item val=searchListItemRecursive(list,it,&pos);
	if(val){
		printf("\nL'elemento si trova nella posizione : %d ",pos);
	}else{
		printf("\nElmento non trovato");
	}
    return 0;
}