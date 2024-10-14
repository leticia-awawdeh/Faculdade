#include <stdio.h>

int verifyNumber(int number){
    if (number > 0){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int number;
    printf("Digite um número qualquer: ");
        scanf("%d", &number);

    int result = verifyNumber(number);
        if (result == 1){
            printf("O número é positivo");

        } else {
            printf("O número é negativo");
        }

    return 0;
}