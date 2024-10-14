#include <stdio.h>

int main(){
    int number;

    printf("Digite um número: ");
        scanf("%d", &number);

    //verifica se o número é maior que 20 e menor que 90
    if (number > 20 && number < 90){
        printf("O seu número está entre 20 e 90, seu número: %d", number);

    } else {
        //caso o número não maior que 20 e menor que 90
        printf("O seu número não se enquadra, seu número: %d", number);
        
    }

    return 0;
}