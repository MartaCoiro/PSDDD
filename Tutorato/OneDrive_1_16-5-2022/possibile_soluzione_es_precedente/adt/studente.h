typedef struct studente *Studente;
typedef struct data *Data;

Studente createStudente(char *, char *, Data);
void printStudente(Studente );
int comparaStudente( Studente , Studente );
int ricerca(Studente , char *);
Data getData(Studente);
