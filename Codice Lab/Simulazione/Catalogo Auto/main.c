#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "automobile.h"
#include "catalogo.h"

int main(){
    int i;
    char nome[30];
    printf("Inserisci nome catalogo : ");
    scanf("%s",nome);
    Catalogo catalogo=creaCatalogo(nome);
    printf("Inserisci valori\n");

    for(i=0;i<2;i++){
        Automobile automobile=inputItem();
        addAutomobile(catalogo,automobile);
    }
    printf("Catalogo : \n");
    printCatalogo(catalogo);
    orderByAnnoProduzione(catalogo);
    printf("\nPer anno di produzione :\n");
    printCatalogo(catalogo);
    printf("\nInserisci  targa dell'auto da eliminare : ");
    char targa[30];
    scanf("%s",targa);
    Automobile automobile1=creaAutomobile(targa,0,"",0);
    printf("\nL'auto si trova nella posizione %d \n",cercaTarga(catalogo,automobile1));
    printf("\nDopo la delete\n");
    deleteAutomobile(catalogo,automobile1);
    printCatalogo(catalogo);
    
    return 0;
}