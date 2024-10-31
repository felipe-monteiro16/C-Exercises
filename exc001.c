#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 10


void main (){
    int nota[max], cont = 0, t, soma = 0; 
    float media;
    
    srand(time(NULL));
    for(t=0; t<max; ++t){
        nota[t] = rand()%10;
        printf("%d\n", nota[t]);
    }
    for(t=0; t<max; ++t){
        soma += nota[t];
        if (nota[t]<6){
            cont++;
        }
    }
    media = (float)soma/10;
    printf("A soma é %d, e A média é %.2f e a quantia de reprovados é %d", soma, media, cont);
    
}
