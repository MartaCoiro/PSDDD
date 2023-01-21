#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esame.h"
#include "libretto.h"

struct libretto
{
    char nome[25];
    char cognome[25];
    char idStudente[25];
    Esame esame[MAX_EXAM];
    size_t numEsami;
};

Libretto creaLibretto(const char *id,const char*nome,const char*cognome ){
    Libretto libretto=malloc(sizeof *libretto);
    strcpy(libretto->idStudente,id);
    strcpy(libretto->nome,nome);
    strcpy(libretto->cognome,cognome);
    strcpy(libretto->idStudente,id);
    libretto->numEsami=0;
    return libretto;
}

int aggiungiEsame(const Libretto libretto,const Esame esame){
    char * temp=getNome(esame);
    Esame exam=cercaEsame(libretto,temp);
    free(temp);
    if(exam!=NULL){
        free(exam);
        return 0;
    }
    libretto->esame[libretto->numEsami]=clona(esame);
    libretto->numEsami++;
    return 1;
}

Esame cercaEsame( const Libretto libretto, const char* corso){
    int trovato=0,i=0;
    char *temp;
    while (i<libretto->numEsami && !trovato)
    {
        temp=getNome(libretto->esame[i]);
        if(strcmp(corso,temp)==0){
            free(temp);
            trovato=1;
        }
        else{
            free(temp);
            i++;
        }
        return (trovato==1)? clona(libretto->esame[i]) : NULL;
    }
}
int outputLibretto(const Libretto l){
    if(l!=NULL){
        printf("Nome %s\n",l->nome);
        printf("Cognome %s \n",l->cognome);
        printf("ID Studente %S",l->idStudente);
        int size=l->numEsami;
        printf("Esami : \n");
        int i;
        for(i=0;i<size;i++){
            outputEsame(l->esame[i]);
        }
        return 1;
    }
    return 0;
}

int destroyLibretto(Libretto *libretto){
    if(*libretto!=NULL){
        int size=(*libretto)->numEsami;
        int i;
        for(i=0;i<size;i++){
            free((*libretto)->esame[i]);
            free(*libretto);
            *libretto=NULL;
            return 1;
        }
    }
    return 0;
}