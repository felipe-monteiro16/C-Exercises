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
    int matricula, matriculas[max], notas[max], nota, c;
    srand(time(NULL));
    nota = rand()%100;
    matricula = rand() %89999 + 10000;
    for(c=0; c<max; ++c){
        notas[c] = nota;
        matriculas[c] = matricula; 
    }
    printf("%d %d", matricula, nota);
    
    return 0;
}
