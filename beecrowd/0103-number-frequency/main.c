/******************************************************************************
                        1.3 - Number frequency
*******************************************************************************/

#include <stdio.h>

int main()
{
    // Get vector size
    int size, i, j, temp;
    scanf("%d", &size);
    
    // Get the vector
    int vet[size];
    for (i=0; i<size; i++)
        scanf("%d", &vet[i]);
    
    // Bubble Sort
    
    //printf("\n ------------------- BUBBLE SORT ---------------------\n");
    for (i=size; i>0; i--) {
        for (j=0; j<i-1; j++) {
            if (vet[j] > vet[j+1]) {
                temp = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = temp;
            }
        }
    }    
    
    /*
    // Show vector
    for (i = 0; i<size; i++)
        printf("%d ", vet[i]);
    printf("\n");
    */
    
    // Get Number frequency
    temp = 1;
    for (i = 0; i<size; i++) {
        if (i < size-1 && vet[i] == vet[i+1]) {
            temp++;
        } else {
            printf("%d aparece %d vez(es)\n", vet[i], temp);
            temp = 1;
        }
    }
    return 0;
}