#include <stdio.h>
#include "point.h"

int main(){

    Point p1,p2;
    float x,y,x1,y1,dist;
    printf("Inserire x \n");
    scanf("%f",&x);
    printf("Inserire y \n");
    scanf("%f",&y);
    p1=createPoint(x,y);
    printf("Inserire x \n");
    scanf("%f",&x1);
    printf("Inserire y \n");
    scanf("%f",&y1);
    p2=createPoint(x1,y1);
    dist=distanza(p1,p2);
    printf("La distanza tra i due punti = %.2f",dist);


    return 0;
}