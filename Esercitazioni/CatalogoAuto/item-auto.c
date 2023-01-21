#include <stdio.h>
#include <string.h>
#include "item.h"
#include "automobile.h"
#define MAX 25

Item inputItem(){
    char targa[MAX];
    int annoImmatricolazione;
    char modello[MAX];
    int annoProduzione;
    printf("Inserisci targa\n");
    scanf("%s",targa);
    printf("Insersici anno immatricolazione\n");
    scanf("%d",&annoImmatricolazione);
    printf("Inserisci mmodello\n");
    scanf("%s",&modello);
    printf("Inseirsci anno produzione\n");
    scanf("%d",&annoProduzione);
    Auto automobile=creaAuto(targa,annoImmatricolazione,modello,annoProduzione);
    return automobile;
}

void outputItem(Item item){
    Auto automobile=item;
    printf("%s   %d   %s  %d  \n",
    getTarga(automobile),getImmatricolazione(automobile),getModello(automobile),getProduzione(automobile));
}

int compareItem(Item i1,Item i2){
    Auto automobile1=i1;
    Auto automobile2=i2;
    return getProduzione(automobile1)-getProduzione(automobile2);
}

int compareItemTarga(Item item1, Item item2){
   Auto s1 = item1;
   Auto s2 = item2;
   return strcmp(getTarga(s1), getTarga(s2)); 
}
