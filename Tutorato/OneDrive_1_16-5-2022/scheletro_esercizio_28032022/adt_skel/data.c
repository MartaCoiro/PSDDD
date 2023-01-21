#include <stdio.h>
#include <stdlib.h>
#include "data.h"


struct data{
	int giorno;
	int mese;
	int anno;
};

Data createData(int giorno, int mese, int anno){
	Data d=malloc(sizeof(struct data));
	d->giorno=giorno;
	d->mese=mese;
	d->anno=anno;
	
	return d;
}

int getGiorno(Data d){
	return d->giorno;
}

int getMese(Data d){
	return d->mese;
}

int getAnno(Data d){
	return d->anno;
}


