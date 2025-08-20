/******************************************************************************
O desafio é para a pessoa me informar um valor e ser gerado
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

void main() {
    int num, cont, lista[max], c, d, i, j, a, cont1 = 0;
    printf("Digite um número para a matriz: ");
    scanf("%d", &num);
    cont = (2 * (num-1)) + 1; // DEFININDO ALTURA/LARGURA DA MATRIZ
    for(i=1; i<cont+1; ++i){         // LINHA DA MATRIZ
        for(j=1; j<cont+1; ++j){    // COLUNA DA MATRIZ
            cont1=cont;
            int cont2=1;
            for(d=0; d<num; d++){ // DEFININDO O VALOR A SER IMPRIMIDO
                if(i==cont2 || i==cont1 || j==cont2 || j==cont1){
                    a = cont2;
                    break;
                } else{
                    cont1 = cont1-1;
                    cont2 = cont2+1;
                }    
            }          
            printf("%d ", a);
        }
        printf("\n");
    }
}
/* 
Ali encima na parte "DEFININDO O VALOR A SER IMPRIMIDO"
tá meio difícil de entender mas vamo la:
Foi identificado um padrão nos valores a serem escritos
por exemplo no caso num=3, é digitado o número 1 quando
está na linha *1* ou coluna 1, ou na linha *5* ou coluna 5
pra digitar o número 2 não é muito diferente, linha 2
ou coluna 2, ou linha 4 ou coluna 4
Percebe-se que da mesma forma que o primeiro número aumenta
de 1 em 1, o outro reduz de 1 em 1, Nisso foi só criar um
um laço com a variável "cont2" que aumenta e a "cont1" que reduz
colocando dentro a estrutura condicional.*/
