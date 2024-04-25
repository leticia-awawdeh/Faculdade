#include <stdio.h>

int main (){
    int number, res3, res7;

    printf("digite um número inteiro: ");
        scanf("%d", &number);

    //calcula o resto da divisão por 3 e por 7
    res3 = number % 3;
    res7 = number % 7;

    //veifica se o número é divisível por 3 e por 7
    if (res3 == 0 && res7 == 0){
        printf("O seu número é divisível por 3 e por 7");

    } else {
        printf("O seu número não é divisível por 3 e por 7");
    }
    return 0;
}