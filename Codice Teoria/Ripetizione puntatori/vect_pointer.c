#include <stdio.h>
#include <string.h>

int main(){

    int i,g;
    char *giorni[7]={"lunedi","martedi","mercoledi","giovedi","venerdi","sabato","domenica"};
    printf("Quale carattere inserire ?(1-9) \n");
    scanf("%d",&i);
    for(g=0;g<7;g++){
        if(i<strlen(giorni[g])){
            printf("%c",giorni[g][i-1]); //stampa ogni carattere nella posizione [g][i-1] 
            
        }
        else printf("-");
    printf("\n");
    }

    return 0;
}