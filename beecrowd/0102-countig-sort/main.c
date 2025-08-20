#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

long long swap_count = 0;

// Função para trocar dois elementos e contar a troca
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swap_count++;
}

// Função de ordenação Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j;
    int last_percent = -1;

    for (i = 0; i < n - 1; i++) {
        int percent = (100 * i) / (n - 1);
        if (percent != last_percent) {
            printf("Progresso: %d%%\n", percent);
            last_percent = percent;
        }

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}


// Particionamento para QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// QuickSort recursivo
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int *arr = malloc(SIZE * sizeof(int));
    if (arr == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Gera os elementos aleatórios
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand();
    }

    // Mede o tempo de execução
    clock_t start = clock();
    // Quicksort
    quickSort(arr, 0, SIZE - 1);

    // Bubble Sort
    //bubbleSort(arr, SIZE);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Tempo de execução: %.2f segundos\n", time_taken);
    printf("Quantidade de trocas: %lld\n", swap_count);

    free(arr);
    return 0;
}
