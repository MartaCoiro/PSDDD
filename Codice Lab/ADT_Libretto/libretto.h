#include "esame.h"
typedef struct libretto *Libretto;
#define MAX_EXAM 25

Libretto creaLibretto(const char* idStudent,const char* nome,const char* cognome);
int aggiungiEsame(const Libretto , const Esame);
Esame cercaEsame(const Libretto libretto, const char * corso);
int outputLibretto(const Libretto l);
int destroyLibretto(Libretto * libretto);