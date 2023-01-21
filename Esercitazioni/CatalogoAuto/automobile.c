#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "automobile.h"
#include "item.h"

struct automobile
{
    char *targa;
    int annoImmatricolazione;
    char *modello;
    int annoProduzione;
};

Auto creaAuto(char *targa,int annoImmatricolazione,char *modello,int annoProduzione){
    Auto automobile=malloc(sizeof(struct automobile));
    automobile->targa=strdup(targa);
    automobile->annoImmatricolazione=annoImmatricolazione;
    automobile->modello=strdup(modello);
    automobile->annoProduzione=annoProduzione;
    return automobile;
}

char * getTarga(Auto a){
    char *targa=malloc(sizeof(char)*(1+strlen(a->targa)));
    strcpy(targa,a->targa);
    return targa;
}
int getImmatricolazione(Auto a){
    return a->annoImmatricolazione;
}
 char * getModello(Auto a){
     char *modello=malloc(sizeof(char)*(1+strlen(a->modello)));
     strcpy(modello,a->modello);
     return modello;
 }
 int getProduzione(Auto a){
     return a->annoProduzione;
 }