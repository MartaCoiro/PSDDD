#include <stdio.h>
#include <stdlib.h>
int mcdIterativo(int a,int b){
    int r;
    //controllare r!=0 è superfluo
    while (b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int mcdRicorsivo(int a,int b){
    if(b==0){
        return a;
    }else{
        return mcdRicorsivo(b,a%b);
    }
}
int main(int argc,char const *argv[]){
    if(argc!=3){
        fprintf(stderr,"Inserire 2 valori interi \n");
        return 0;
    }
    int a,b;
    //argv[0] è il nom con cui invochiamo il programma , cioè main
    a=atoi(argv[1]);//converte stringhe in intero
    b=atoi(argv[2]);
    printf("MCV Iterativo di %d e %d = %d ",a,b,mcdIterativo(a,b));
    printf("MCV Ricorsivo  di %d e %d = %d ",a,b,mcdRicorsivo(a,b));
    return 0;

}