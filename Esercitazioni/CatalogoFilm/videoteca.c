#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "film.h"
#include "list.h"
#include "item.h"
#include "videoteca.h"

struct videoteca
{
    char *nome;
    List film;
};

Videoteca creaVideoteca(char *nome){
    Videoteca videoteca=malloc(sizeof(struct videoteca));
    videoteca->nome=strdup(nome);
    videoteca->film=newList();
    return videoteca;
}
void aggiungiFilm(Videoteca v,Film f){
    addListTail(v->film,f);
}
void removeFilm(Videoteca v,Film f){
    removeListItem(v->film,f);
}
void ordinaPerAnnoProduzione(Videoteca videoteca){
    selectionSortList(videoteca->film);
}

int ricercaFilm(Videoteca v,Film f){
    int pos;
     searchListItem(v->film,f,&pos);
     return pos;
}

void printVideoteca(Videoteca v){
    printList(v->film);
    printf("\n");
}