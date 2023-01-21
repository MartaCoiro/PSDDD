#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromaIterativa(char parola[]){
    int i,j;
    for ( i = 0,j=strlen(parola)-1; i < j; i++,j--)
    {
        if(parola[i]!=parola[j]){
            return 0;
        }
    }
    return 1;
}

int palindromaTail1(char parola[],int i,int j){
    if(i<j){
        if(parola[i]!=parola[j])
            return 0;
        return palindromaTail1(parola,i+1,j-1);
    }
    return 1;
}
int palindromaTail(char parola[]){
    return palindromaTail1(parola,0,strlen(parola)-1);
}

int palindromaRicorsiva(char parola[],int len){
     if(len<=1)
        return 1;
    if(parola[0]!=parola[len-1])
        return 0;
    return palindromaRicorsiva1(parola+1, len-2);
}
int main(int argc,char  *argv[]){
    if(argc!=2){
        fprintf(stderr,"Inserire una parola \n");
        return 0;
    }
    if(palindromaIterativa(argv[1])){
        printf("Palindroma");
    }else{
        printf("Non palindroma");
    }
      if(palindromaTail(argv[1])){
        printf("\nPalindroma Tail");
    }else{
        printf("\nNon palindroma Tail");
    }
   
    return 0;

}