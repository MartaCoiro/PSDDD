#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "film.h"

struct film{
    char *titolo;
    char *regista;
    int durata;
    int annoProduzione;
};

Film creaFilm(char *titolo,char *regista,int durata,int annoProduzione){
    Film film=malloc(sizeof(struct film));
    film->titolo=strdup(titolo);
    film->regista=strdup(regista);
    film->durata=durata;
    film->annoProduzione=annoProduzione;
    return film;
}

char * getTitolo(Film film){
    char *titolo=malloc(sizeof(char)*(1+strlen(film->titolo)));
    strcpy(titolo,film->titolo);
    return titolo;
}
char * getRegista(Film film){
    char *regista=malloc(sizeof(char)*(1+strlen(film->regista)));
    strcpy(regista,film->regista);
    return regista;
}

int getDurata(Film film){
    return film->durata;
}
int getAnnoProduzione(Film film){
    return film->annoProduzione;
}