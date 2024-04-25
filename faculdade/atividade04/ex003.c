#include <stdio.h>

int main(){
    int number;
    
    //lê o número introduzido pelo usuário
    printf("Digite um número: ");
        scanf("%d", &number);

    //verifica se o número é igual a 5, 200 ou 400 e se o número está entre 500 e 1000
    if (number == 5){
        printf("O seu número é igual a 5");

    } else if (number == 200){
        printf("O seu número é igual a 200");

    } else if (number == 400){
        printf("O seu número é igual a 400");

    } else if (number >= 500 && number <= 1000){
        printf("O seu número está entre 500 e 1000, seu número: %d", number);

    } else {
        printf("O seu número não enquadra nos escopos, seu número: %d", number);

    }
    
    return 0;
}