#include <stdio.h>
int sumNumbers(int a, int b){
    int sum = 0;

    for(int i = a; i <= b; i++){
        sum += i;
    }
    return sum;
}

int main(){
    int number1, number2;
    printf("Digite o primeiro número positivo: ");
        scanf("%d", &number1);

    printf("Digite o segundo número positivo: ");
        scanf("%d", &number2);

    if(number1 > number2){
        int temp = number1;
        number1 = number2;
        number2 = temp;
    }

    if (number1 <= 0 || number2 <= 0){
            printf("Os dois números têm que ser positivos!");
    }

    int result = sumNumbers(number1, number2);

    printf("A soma dos números %d e %d é igual a: %d\n", number1,number2, result);

    return 0;
}