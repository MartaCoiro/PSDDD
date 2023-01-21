#include <stdio.h>
#include "point.h"

int main(){

    Point p1,p2;
    float x,y,dist;
    printf("Inserire x \n");
    scanf("%f",&x);
    printf("Inserire y \n");
    scanf("%f",&y);
    p1=createPoint(x,y);
    printf("Inserire x \n");
    scanf("%f",&x);
    printf("Inserire y \n");
    scanf("%f",&y);
    p2=createPoint(x,y);
    dist=distanza(p1,p2);
    printf("La distanza tra i due punti = %d",dist);


    return 0;
}