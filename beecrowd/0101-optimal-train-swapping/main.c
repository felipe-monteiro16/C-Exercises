/******************************************************************************
 OPTIMAL TRAIN SWAPPING
*******************************************************************************/

#include <stdio.h>

int main()
{
    int vet_size, swaps, i, vet[100], temp, temp_size, tests_num;
    
    // Get number of tests
    scanf("%d", &tests_num);
    
    while (tests_num > 0) {
        // Get Vector
        scanf("%d", &vet_size);
        temp_size = vet_size;
        
        for(i=0; i<vet_size; i++)
            scanf("%d", &vet[i]);
    
        // Order Vector
        swaps = 0;
        while (temp_size > 1) {
            for (i=0; i+1<temp_size; i++) {
                if (vet[i] > vet[i+1]) {
                    temp = vet[i+1];
                    vet[i+1] = vet[i];
                    vet[i] = temp;
                    swaps++;
                }
            }
            temp_size--;
        }
        /*
        // Print Vector
        for(i=0; i<vet_size; i++)
            printf("%d ", vet[i]);
        */
        printf("Optimal train swapping takes %d swaps.\n", swaps);
        tests_num--;
    }
    return 0;
}