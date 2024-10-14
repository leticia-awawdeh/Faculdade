#include <stdio.h>

int main(){
  int vet[18], matrix[3][6];

  printf("Digite os valores para o vetor: \n");
  for(int i = 0; i < 18; i++){
    printf("posição do vetor %d: ", i);
    scanf("%d", &vet[i]);

  }

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 6; j++){
        matrix[i][j] = vet[i * 6 + j];

    }
  }

  printf("A matriz gerada é: \n");
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 6; j++){
        printf("%d \t", matrix[i][j]);

    }
    printf("\n");
  }
    return 0;
}