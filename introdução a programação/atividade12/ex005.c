#include <stdio.h>

void sortingCreasingVector(float array[], int size) {
    int i, j;
    float temp;

    for(i = 0; i < size - 1; i++) {
        for(j = 0; j < size - i - 1; j++) {
            
            if(array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    float numbers[5] = {3.7, 1.2, 4.6, 2.8, 5.1};
    int i;

    printf("vetor original: ");
    for(i = 0; i < 5; i++) {
        printf("%.1f ", numbers[i]);
    }

    sortingCreasingVector(numbers, 5);

    printf("\nVetor ordenado de forma crescente: ");
    for(i = 0; i < 5; i++) {
        printf("%.1f ", numbers[i]);
    }

    return 0;
}
