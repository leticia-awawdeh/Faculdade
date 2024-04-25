#include <stdio.h>

int main(){
    int number;

    printf("Digite um número: ");
        scanf("%d", &number);

    //verifica se o número introduzido pelo usuário é positivo, negativo ou nulo
    if (number > 0){
        printf("O número digitado é positivo");

    }else if (number < 0){
        printf("O número digitado é negativo");
        
    } else {
        printf("O número digitado é nulo");

    }
    
    return 0;
}