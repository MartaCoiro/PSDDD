#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "catalogo.h"
#include "automobile.h"

struct catalogo
{
    char * nome;
    List automobile;
};

Catalogo creaCatalogo(char *nome){
    Catalogo catalogo=malloc(sizeof(struct catalogo));
    catalogo->nome=strdup(nome);
    catalogo->automobile=newList();
    return catalogo;
}
void aggiungiAuto(Catalogo catalogo,Auto a){
    addListTail(catalogo->automobile,a);
}
void removeAuto(Catalogo catalogo,Auto automobile){
    removeListItem(catalogo->automobile,automobile);
}
void ordinaPerDataProduzione(Catalogo catalogo){
    selectionSortList(catalogo->automobile);
}
int ricercaTarga(Catalogo catalogo,Auto automobile){
    int pos;
    searchListItem(catalogo->automobile,automobile,&pos);
    return pos;
}
void printCatalogo(Catalogo catalogo){
    printf("Cataglogo %s \n",catalogo->nome);
    printList(catalogo->automobile);
    printf("\n");
}

int sizeListCatalogo(Catalogo catalogo){
    return sizeList(catalogo->automobile);
}