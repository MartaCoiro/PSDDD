#include <stdio.h>

struct Persona
{
    int eta;
    char nome[30];

};

int main(){

    struct Persona persona={15,"Luca"};
    printf("Il nome è %s",persona.nome);


    return 0;
}