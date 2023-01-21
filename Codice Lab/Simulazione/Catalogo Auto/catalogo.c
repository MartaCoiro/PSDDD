#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"
#include "list.h"

struct catalogo{
    char* nomeCatalogo;
    List automobile;
};

Catalogo creaCatalogo(char* nome){
    Catalogo catalogo=malloc(sizeof(struct catalogo));
    catalogo->nomeCatalogo=strdup(nome);
    catalogo->automobile=newList();
    return catalogo;
}
void addAutomobile(Catalogo catalogo, Automobile automobile){
    addListTail(catalogo->automobile,automobile);
}
void deleteAutomobile(Catalogo catalogo,Automobile automobile){
    //outputItem(getTarga(automobile));
    removeListItem(catalogo->automobile,automobile);
}
void orderByAnnoProduzione(Catalogo catalogo){
    printf("Sono nella funzione");
    selectionSort(catalogo->automobile);
}
int cercaTarga(Catalogo catalogo,Automobile automobile){
    int pos;
    searchList(catalogo->automobile,automobile,&pos);
    return pos;
}
void printCatalogo(Catalogo c){
    /*
    printf("Stampa catalogo : \n");
    printf("%s",c->nomeCatalogo);
    printf("\n");
    */
    printList(c->automobile);
    
}
