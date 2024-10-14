#include <stdio.h>

int main(){
    int matrix[5][5];
    int sumDiagonal = 0;

    printf("Digite os valores para a matriz: \n");
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                printf("matriz [%d][%d]: ", i, j);
                scanf("%d", &matrix[i][j]);

            }
        }

    for (int i = 0; i < 5; i++){
        sumDiagonal += matrix[i][i];

    }

    printf("A soma da diagonal principal é %d\n", sumDiagonal);
    return 0;
}