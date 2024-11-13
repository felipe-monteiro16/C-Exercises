/*
Questão 16 pag 34
AEDS
INCOMPLETO
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define max 10

int main() {
    int matricula, matriculas[max], notas[max], nota, c, nmaior = 0;
    srand(time(NULL));
    
    
    for(c=0; c<max; ++c){
        nota = rand()%100;
        matricula = rand() %899999 + 100000;
        notas[c] = nota;
        matriculas[c] = matricula; 
    }
    for(c=0; c<max; ++c){
        if (notas[c] > notas[nmaior]){
            nmaior = c;
        }
    }
    for(c=0; c<max; ++c){
        printf("%d ", notas[c]);
    }
    printf("%d %d", matriculas[nmaior], notas[nmaior]);
    
    return 0;
}
