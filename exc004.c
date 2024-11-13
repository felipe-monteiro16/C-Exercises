/*
Questão 16 pag 34
AEDS - Guimarães /Lages
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define max 20

int main() {
    int matricula, matriculas[max], notas[max], nota, c, nmaior = 0,
    nmaior2 = 0;
    srand(time(NULL));
    
    
    for(c=0; c<max; ++c){ // GERANDO NOTAS E MATRÍCULAS
        nota = rand()%100;
        matricula = rand() %899999 + 100000;
        notas[c] = nota;
        matriculas[c] = matricula; 
    }
    for(c=0; c<max; ++c){ // DESCOBRINDO MAIOR NOTA
        if (notas[c] > notas[nmaior]){
            nmaior = c;
        }
    }
    for(c=0; c<max; ++c){ // DESCOBRINDO SEGUNDA MAIOR NOTA
        if (notas[c] > notas[nmaior2] && notas[c] < notas[nmaior]){
            nmaior2 = c;
        }
    }
    printf("As notas foram: ");
    for(c=0; c<max; ++c){
        printf("%d ", notas[c]);
    }
    printf("\nA maior nota foi %d, do N° de Matrícula %d",  notas[nmaior], matriculas[nmaior]);
    printf("\nE a 2° maior nota foi: %d, do N° de matrícula: %d", notas[nmaior2], matriculas[nmaior2]);
    
    return 0;
}
