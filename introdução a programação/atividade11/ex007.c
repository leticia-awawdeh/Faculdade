#include <stdio.h>

int main(){
    int matrix1[5][2], matrix2[5][2], matrixSum[5][2];

    printf("Digite os valores da primeira matriz: \n");
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 2; j++){
                printf("matriz [%d][%d]: ", i, j);
                scanf("%d", &matrix1[i][j]);

            }
        }

        printf("Digite os valores da segunda matriz: \n");
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 2; j++){
                    printf("Matriz[%d][%d]: ", i, j);
                    scanf("%d", &matrix2[i][j]);

                }
            }

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 2; j++){
                matrixSum[i][j] = matrix1[i][j] + matrix2[i][j];

            }
        }

        printf("O valor da soma das matrizes é: \n");
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 2; j++){
                    printf("%d \t", matrixSum[i][j]);
                }
                printf("\n");
            }

    return 0;
    
}