#include <stdio.h>

int sumMatrix(int matrix[5][5]){
    int sum = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            sum += matrix[i][j];

        }
    }

    return sum;
}
int main(){
    int matrix[5][5];

    printf("Digite os valores para a matriz: \n");
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                printf("Matriz[%d][%d]: ", i + 1, j + 1);
                scanf("%d", &matrix[i][j]);
            }
        }

        int result = sumMatrix(matrix);

        printf("A soma dos elementos da matriz é igual a: %d\n", result);

    return 0;
}