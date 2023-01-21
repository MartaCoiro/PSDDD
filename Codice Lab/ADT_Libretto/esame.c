#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esame.h"

struct esame
{
    char nomeCorso[25];
    char data[25];
    int voto;
};

Esame nuovoEsame(const char* nome,const char * data, int voto){
    Esame esame=malloc(sizeof *esame);
    if(esame!=NULL){
        strcpy(esame->nomeCorso,nome);
        strcpy(esame->data,data);
        esame->voto=voto;
        //strcpy(esame->voto,voto);
    }
    return esame;
}

char* getNome(const Esame esame){
    char * temp=malloc(strlen(esame->nomeCorso+1)*sizeof(char));
    if (temp!=NULL)
    {
        strcpy(temp,esame->nomeCorso);
    }
    return temp;
}
 Esame inputEsame(){
      char nomeCorso[20],data[20];
      int voto;
      printf("Inserisci nome corso : \n");
      scanf("%s",nomeCorso);
      printf("Inserisci data \n");
      scanf("%s",data);
      printf("Inserisci voto \n");
      scanf("%d",&voto);
      return nuovoEsame(nomeCorso,data,voto);
 }
 void outputEsame(const Esame e){
     printf("%s %s %d ",e->nomeCorso,e->data,e->voto);
 }
 Esame clona(const Esame e){
     Esame esame=malloc(sizeof *esame);
     *esame=*e;
     return esame;
 }

int setCorso(const Esame esame, const char *corso){
    if(esame!=NULL){
        strcpy(esame->nomeCorso,corso);
        return 1;
    }
    return 0;
}