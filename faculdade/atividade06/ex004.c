#include <stdio.h>

int main(){
    int number[8];
    int count = 0;

    printf("Digite 8 números: \n");

    for ( int i = 0; i <= 7; i++){
        printf("Número %d: ", i + 1);
        scanf("%d", &number[i]);
    }
    for ( int i = 0; i < 8; i++){
       if (number[i] < 15){
        count ++;
       }

    }
    printf("Quantidade de números menores que 15: %d\n", count);
    return 0;
}