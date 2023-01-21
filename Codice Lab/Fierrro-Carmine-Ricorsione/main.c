#include <stdio.h>
#include "item.h"
#include "list.h"

int main(){
    Item item;
    int pos;
    List list= newList();
    int i;
    for(i=0;i<6;i++){
        item=inputItem();
        addListTail(list,item);
    }
    printf("Ecco il contenuto della lista : \n");
    printf("[  ");
    printList(list);
    printf("  ]\n");
    printf("Inserisci valore da cercare\n");
    Item value=inputItem();
    value=searchListRec(list,value,&pos);
    printf("L'item ");
    outputItem(value);
    printf(" si trova nella posizione %d ",pos);
    printf("Inserisci il valore \n");
    Item itemOccorenze=inputItem();
    int occorrenze=countItemListRec(list,itemOccorenze);
    printf("Ci sono esattamete %d occorrenze di ",occorrenze);
    outputItem(itemOccorenze);
    printf("\nLista dopo la destroy \n");
    destroyListRec(list);
    printf("[  ");
    printList(list);
    printf("  ]\n");



    return 0;
}