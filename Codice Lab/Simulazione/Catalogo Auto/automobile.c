#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "automobile.h"

struct automobile{
    char* targa;
    int annoImmatricolazione;
    char* modello;
    int annoProduzione;
};

Automobile creaAutomobile(char* targa,int annoImmatricolazione,char* modello,int annoProduzione){
    Automobile automobile=malloc(sizeof(struct automobile));
    automobile->targa=strdup(targa);
    automobile->annoImmatricolazione=annoImmatricolazione;
    automobile->modello=strdup(modello);
    automobile->annoProduzione=annoProduzione;
    return automobile;
}

char* getTarga(Automobile automobile){
    char* targa=malloc(sizeof(char) * (strlen(automobile->targa)+1));
    strcpy(targa,automobile->targa);
    return targa;
}
int getAnnoImmatricolazione(Automobile automobile){
    int immatricolazione=automobile->annoImmatricolazione;
    return immatricolazione;
}
char* getModello(Automobile automobile){
    char* modello=malloc(sizeof(char) * (strlen(automobile->modello)+1));
    strcpy(modello,automobile->modello);
    return modello;
}
int getAnnoProduzione(Automobile automobile){
    int annoProduzione=automobile->annoProduzione;
    return annoProduzione;
}