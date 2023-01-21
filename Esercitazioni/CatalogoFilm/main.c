#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "film.h"
#include "videoteca.h"

int main(){
    char nome[30];
    char titolo[30];
    int pos;
    int i;
    printf("Inseris nome videoteca : ");
    scanf("%s",nome);
    Videoteca videoteca=creaVideoteca(nome);
    Film film;
    printf("\nInserisci i film  \n");
    for(i=0;i<3;i++){
        film=inputItem();
        aggiungiFilm(videoteca,film);
    }
    printf("\nEcco i film della tua videoteca\n");
    printVideoteca(videoteca);
    ordinaPerAnnoProduzione(videoteca);
    printf("\nPer data Produzione");
    printVideoteca(videoteca);
    printf("\nInserisci titolo da cercare : ");
    scanf("%s",titolo);
    Film f=creaFilm(titolo,NULL,0,0);
    //ricercaFilm(videoteca,f);
    printf("Il film ricercato è  in posizione %d ",ricercaFilm(videoteca,f));

    return 0;
}