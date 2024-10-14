#include <stdio.h>

int main() {
    int array[10];
    int i, j;

    printf("Digite 10 valores inteiros:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &array[i]);
        
    }


    printf("Valores repetidos:\n");
    int foundRepeat = 0; 
    int alreadyPrinted[10] = {0}; 

    for (i = 0; i < 10; i++) {
        for (j = i + 1; j < 10; j++) {
            if (array[i] == array[j] && !alreadyPrinted[i]) {
                printf("%d ", array[i]);
                foundRepeat = 1;
                alreadyPrinted[i] = 1; 
            
                break; 
            }
        }
    }


    if (!foundRepeat) {
        printf("Nenhum valor repetido encontrado.");
    }

    return 0;
}
