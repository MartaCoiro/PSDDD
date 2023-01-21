typedef struct esame * Esame;
#define NULLEXAM NULL

Esame nuovoEsame(const char *nome,const char *data,int voto);
char* getNome(const Esame esame);
Esame inputEsame();
void outputEsame(const Esame esame);
Esame clona(const Esame esame);
int setCorso(const Esame esame, const char* corso);
