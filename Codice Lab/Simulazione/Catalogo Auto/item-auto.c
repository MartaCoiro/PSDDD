#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "automobile.h"
#include "item.h"
#define MAX 30

Item inputItem(){
    char targa[MAX];
    int annoImmatricolazione;
    char modello[MAX];
    int annoProduzione;
    printf("\nInserisci targa : ");
    scanf("%s",targa);
    printf("\nInserisci anno di immatricolazione : ");
    scanf("%d",&annoImmatricolazione);
    printf("\nInserisci modello : ");
    scanf("%s",modello);
    printf("\nInserisci anno di produzione : ");
    scanf("%d",&annoProduzione);
    return creaAutomobile(targa,annoImmatricolazione,modello,annoProduzione);
}
void outputItem(Item a){
    Automobile automobile=a;
    printf("\nInfo auto : %s  %d %s %d \n",getTarga(automobile),
    getAnnoImmatricolazione(automobile),getModello(automobile),getAnnoProduzione(automobile));
}

int compareItem(Item a,Item b){
    Automobile a1=a;
    Automobile a2=b;
    return getAnnoProduzione(a1)-getAnnoProduzione(a2);
}
int compareItemTarga(Item i1,Item i2){
    Automobile a1=i1;
    Automobile a2=i2;
    return strcmp(getTarga(a1),getTarga(a2));
}