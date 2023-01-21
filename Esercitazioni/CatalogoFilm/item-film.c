#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "film.h"
#define MAX 40

Item inputItem(){
    char titolo[MAX];
    char regista[MAX];
    int durata;
    int annoProduzione;
    printf("Inserisci titolo film : ");
    scanf("%s",titolo);
    printf("\nInserisci regista : ");
    scanf("%s",regista);
    printf("\nInserisci durata film : ");
    scanf("%d",&durata);
    printf("\nInserisci anno produzione : ");
    scanf("%d",&annoProduzione);
    return creaFilm(titolo,regista,durata,annoProduzione);
}

void outputItem(Item item){
    Film film=item;
    printf(" Film : %s %s %d %d",getTitolo(film),getRegista(film),getDurata(film),getAnnoProduzione(film));
}

int compareItem(Item item1,Item item2){
    Film f1=item1;
    Film f2=item2;
    return strcmp(getTitolo(f1),getTitolo(f2));
}
int compareAnnoProduzione(Item item1 ,Item item2){
    Film f1=item1;
    Film f2=item2;
    return getAnnoProduzione(f1) - getAnnoProduzione(f2);
}