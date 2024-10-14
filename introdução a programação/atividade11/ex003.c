#include <stdio.h>

int main(){
    int matrix[5][5];
    int maxValue, maxColumn = 0, maxRow = 0;

    printf("Digite números inteiros para as seguintes matrizes: \n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("Coloque um número para a matriz[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);

        }
    }

    maxValue = matrix[0][0];

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(matrix[i][j] > maxValue){
            maxValue = matrix[i][j];
            maxRow = i;
            maxColumn = j;
            }
        }
    }

    printf("O valor máximo é %d, está localizado na linha %d e coluna %d\n", maxValue, maxRow, maxColumn);


    return 0;
}