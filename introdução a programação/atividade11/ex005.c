#include <stdio.h>

int main(){
  int matrix[3][3];
  int sum[3] = {0, 0, 0};

  printf("Digite os valores para a matriz: \n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          printf("matriz [%d][%d]: ", i, j);
          scanf("%d", &matrix[i][j]);

        }
    }

    for(int j = 0; j < 3; j++){
      for(int i = 0; i < 3; i++){
        sum[j] += matrix[i][j];

      }
    }

    printf("Soma das colunas: \n");
    for(int j = 0; j < 3; j++){
      printf("Coluna %d: %d\n", j + 1, sum[j]);
    }

    return 0;
}