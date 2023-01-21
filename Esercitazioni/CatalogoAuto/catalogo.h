#include "item.h"
#include "automobile.h"
 typedef struct catalogo *Catalogo;

Catalogo creaCatalogo(char *);
void removeAuto(Catalogo catalogo,Auto automobile);
void aggiungiAuto(Catalogo,Auto);
void ordinaPerDataProduzione(Catalogo catalogo);
int ricercaTarga(Catalogo catalogo,Auto automobile);
void printCatalogo(Catalogo catalogo);
int sizeListCatalogo(Catalogo);