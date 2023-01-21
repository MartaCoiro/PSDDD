#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
#define MAX 30
struct studente
{
    char nome[20];
    char cognome[20];
    int matricola;
};

Item inputItem(){
    Studente studente=malloc(sizeof(struct studente));
    printf("Inserisci nome studente\n");
    scanf("%s",studente->nome);
    printf("Inserisci cognome studente\n");
    scanf("%s",studente->cognome);
    printf("Inserisci matricola\n");
    scanf("%d",&studente->matricola);
    return studente;
}

void outputItem(Item item){
    Studente studente=item;
    printf("nome %s  cognome %s matricola %d ",studente->nome,studente->cognome,studente->matricola);
}

int compareItem(Item a,Item b){
    Studente s1=a;
    Studente s2=b;
    return strcmp(s1->nome,s2->nome);
}