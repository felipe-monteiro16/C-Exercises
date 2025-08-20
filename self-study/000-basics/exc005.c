/*
Questão 18 pag 34
AEDS - Guimarães/ lages

Fazer o somatório: 
1/N + 2/N-1 + ... + N-1/2 + N/1
*/
#include <stdio.h>
#include <stdlib.h>

void main(){
    float num, c, s, di;
    printf("Digite um número Inteiro: ");
    scanf("%f", &num);
    float cont=num;
    for(c=1; c<=num; ++c){
        di = c/cont;
        s += di;
        printf("\n(%.0f / %.0f) = %.2f", c, cont, di);
        cont--;
    }
    printf("\n = %.3f ", s);
}
