#include <stdio.h>
#include "automobile.h"
#include "catalogo.h"
#include "list.h"
#include "item.h"

int main(){
    int i;
    char targa[25];
    char nomeCatalogo[20];
    Catalogo catalogo;
    Auto automobile;
    printf("Inserisci nome catalogo\n");
    scanf("%s",nomeCatalogo);
    catalogo=creaCatalogo(nomeCatalogo);
    printf("Inserisci auto\n");
    for(i=0;i<2;i++){
        printf("\nDati Auto\n");
        automobile=inputItem();
        aggiungiAuto(catalogo,automobile);
    }
    printf("Ecco il tuo catalogo : \n");
    printCatalogo(catalogo);
    //ordinaPerDataProduzione(catalogo);
    //printCatalogo(catalogo);
    
    printf("\nInserisci targa da cercare\n");
    scanf("%s",targa);
    Auto autoTarga=creaAuto(targa,0,"",0);
    
        printf("Targa trovata in posizione %d", ricercaTarga(catalogo,autoTarga));
    
    
    printf("\nInserisci targa da eliminare\n");
    scanf("%s",targa);
    Auto autoDelete=creaAuto(targa,0,"",0);
    removeAuto(catalogo,autoDelete);
    printf("Dopo la delete della targa %s la size vale %d \n",targa,sizeListCatalogo(catalogo));
    printCatalogo(catalogo);
    
    return 0;
}