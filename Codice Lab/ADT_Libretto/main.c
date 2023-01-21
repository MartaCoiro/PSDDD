#include <stdio.h>
#include <stdlib.h>
#include "esame.h"
#include "libretto.h"

int main(){
    Libretto libretto=creaLibretto("1234","Carmine","Fierro");
    Esame esame=inputEsame();
    aggiungiEsame(libretto,esame);
    outputEsame(esame);
}