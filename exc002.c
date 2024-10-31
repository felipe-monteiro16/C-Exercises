#include <stdio.h>
#include <stdlib.h>

#define nLin 2
#define nCol 3
void main () {
    int mat [nLin] [nCol], count, i, j;
    count = 1;
    for (i=0; i<nLin; i++){
        for (j=0; j<nCol; j++){
            mat[i] [j] = count++;
            printf("%d: [%d, %d]\n", mat[i] [j], i, j);
        }   
    }
    
}
