/******************************************************************************
Incompleto!! O desafio é para a pessoa me informar um valor e ser gerado
a matriz correspondente, exemplo: 
Digite um valor: 3
1 1 1 1 1 
1 2 2 2 1 
1 2 3 2 1
1 2 2 2 1
1 1 1 1 1

E assim com qualquer valor.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define max 30
void main()
{
    int num, cont, lista[max], c, d, i, j, a, cont1 = 0;
    printf("Digite um número para a matriz: ");
    scanf("%d", &num);
    
    cont = (2 * (num-1)) + 1;
    for(c=1; c<num+1; ++c){
        lista[c-1] = c;
    } 
    int tamanho = sizeof(lista) / sizeof(lista[0]);
    for(i=1; i<cont+1; ++i){ 
        for(j=1; j<cont+1; ++j){
            cont1=cont;
            for(d=0; d<tamanho; d++){
                if(i==lista[d] || i==cont1 || j==lista[d] || j==cont1){
                    a = lista[d];
                    break;
                } else {
                    cont1 = cont1-1;
                }
            }           
            printf("%d ", a);
        }
        printf("\n");
    }
}
