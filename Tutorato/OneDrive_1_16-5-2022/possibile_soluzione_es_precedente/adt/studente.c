#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "data.h"
#include "studente.h"


typedef struct studente{
	char nome[20];
	char cognome[20];
	Data data;
}studente;

Studente createStudente(char *nome, char *cognome, Data data){
	Studente s=malloc(sizeof(struct studente));
	
	strcpy(s->nome,nome);
	strcpy(s->cognome,cognome);
	s->data=data;
	

	return s;
}

char *getNome(Studente s){
	char *nome=malloc(sizeof(char)* 20);
	strcpy(nome,s->nome);
	return nome;
}

char *getCognome(Studente s){
	char *cognome=malloc(sizeof(char)* 20);
	strcpy(cognome,s->cognome);
	return cognome;
}

Data getData(Studente s){
	return s->data;
}



void printStudente(Studente s){
	Data d=getData(s);
	printf("%s %s ", s->nome,s->cognome);
	printf("%d-%d-%d \n", getGiorno(d),getMese(d),getAnno(d));
}

int comparaNome(char *d1, char *d2){
	return strcmp(d1,d2);
}

int comparaStudente( Studente s1, Studente s2){
	

	int res=strcmp(s1->cognome,s2->cognome);
		if(res==0){
			res=comparaNome(s1->nome,s2->nome);
		}
			
		return res;
}

int ricerca(Studente s, char *x){
	char *cognome=getCognome(s);
	return strcmp(cognome,x);
}

