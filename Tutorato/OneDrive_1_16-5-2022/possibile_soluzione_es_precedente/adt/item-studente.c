#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "item.h"
#include "data.h"
#include "studente.h"

#define CARD 100

Item inputItem(){
	 char *n=malloc(sizeof(char)*CARD);
    scanf("%s",n);
	 char *c=malloc(sizeof(char)*CARD);
    scanf("%s",c);
	 
	 int giorno,mese, anno;
	
	scanf("%d",&giorno);
	scanf("%d",&mese);
	scanf("%d",&anno);
	
	
	while(giorno<1 || giorno>30||mese >12||mese <1|| anno<1900 || anno >2021){
	
		printf("data non valida\ninserisci la data giorno mese anno\n");
		scanf("%d",&giorno);
		scanf("%d",&mese);
		scanf("%d",&anno);
		getchar();
	}

	

	Data data=createData(giorno,mese,anno);
	Item item=createStudente(n,c,data);
	return item;
}

void outputItem(Item item){
	return printStudente((Studente) item);
}

int cmpItem(Item item1, Item item2){
	return comparaStudente((Studente) item1, (Studente) item2);
}

int cmpRicerca(Item item, char *x){
	return ricerca((Studente) item,x);
}
