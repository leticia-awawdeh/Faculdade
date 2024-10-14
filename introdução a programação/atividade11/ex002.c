#include <stdio.h>

int main(){
    int matrix[4][4];
    int multiplier;

    printf("Digite valores inteiros para a matriz: \n");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("Coloque um valor inteiro para a matriz[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Digite um número para multiplicar cada elemento da matriz: \n");
        scanf("%d", &multiplier);
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            matrix[i][j] *= multiplier;

        }
    }

    printf("A nova matriz é: \n");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d \t", matrix[i][j]);
        }
        printf("\n");
    }

    
    return 0;
}