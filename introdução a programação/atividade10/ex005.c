#include <stdio.h>

int main() {
    int array[10], i, j, temp;

    
    printf("Digite os 10 valores do array:\n");
    for(i = 0; i < 10; i++) {
        scanf("%d", &array[i]);
    }

    
    for(i = 0; i < 9; i++) { 
        for(j = 0; j < 9 - i; j++) { 
            if(array[j] < array[j + 1]) { 
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

            }
        }
    }

    
    printf("\nVetor ordenado em ordem decrescente:\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
