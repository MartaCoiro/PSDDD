#include "automobile.h"
typedef struct catalogo* Catalogo;

Catalogo creaCatalogo(char*);
void addAutomobile(Catalogo, Automobile);
void deleteAutomobile(Catalogo,Automobile);
void orderByAnnoProduzione(Catalogo);
int cercaTarga(Catalogo,Automobile);
void printCatalogo(Catalogo);
