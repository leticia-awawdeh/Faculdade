#include <stdio.h>

int main(){
    float matrix[4][3];

    printf("Coloque valores positivos e negativos para a matriz: \n");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            printf("Introduza o valor para a matriz [%d][%d]: ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }

    float sumPositives = 0.0;
    float sumNegatives = 0.0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            if(matrix[i][j] > 0){
                sumPositives += matrix[i][j];
            } else if (matrix[i][j] < 0){
                sumNegatives += matrix[i][j];
            }
            
        }
    }

    printf("A soma de números positivos é de %.2f\n", sumPositives);
    printf("A soma de números negativos é de %.2f\n", sumNegatives);

    return 0;
}