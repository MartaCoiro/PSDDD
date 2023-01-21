#include "item.h"

typedef struct classe *Classe;

Classe createClasse(int, char, char*);
void addStudente(Classe,Item);
Item searchStudente(Classe,char *);
void printClasse(Classe );
Item deleteStudente(Classe , Item );
void ordinaClasse(Classe );
