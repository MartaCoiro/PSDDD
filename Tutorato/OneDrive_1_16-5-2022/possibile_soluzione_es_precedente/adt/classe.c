#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "classe.h"
#include "studente.h"
#include "item.h"


typedef struct classe {
	char sezione;
	int numero;
	char nome[20];
	
	List studenti;
}classe;

Classe createClasse(int numero, char sezione, char *nome){
	Classe c=malloc(sizeof(struct classe));

	c->numero=numero;
	c->sezione=sezione;
	strcpy(c->nome,nome);
	c->studenti=newList();

	return c;
}

char getNomeC(Classe c){
	return *c->nome;
}

char getSezione(Classe c){
	return c->sezione;
}

int getClasse(Classe c){
	return c->numero;
}

void addStudente(Classe c,Item x){
	 addListTail(c->studenti,x);
}

Item searchStudente(Classe c, char *x){
	return searchItem(c->studenti,x);
}

Item deleteStudente(Classe c, Item x){
	return removeListItem(c->studenti, x);
}

void printClasse(Classe c){
	printf("CLASSE: %d SEZIONE: %c ISTITUTO: %s\n",c->numero,c->sezione,c->nome);
	printList(c->studenti);
}
 
void ordinaClasse(Classe c){
	sortList(c->studenti);
}


