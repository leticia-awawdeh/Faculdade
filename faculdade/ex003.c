#include <stdio.h>

int main(){
char option;
float result, number1, number2;

printf("multiplicação (*)\n");
printf("subtração (-)\n");
printf("multiplicação (+)\n");
printf("Selecione uma das operações acima: ");
    scanf("%s", &option);
printf("Digite o primeiro número: ");
    scanf("%f", &number1);
printf("Digite o segundo número: ");
    scanf("%f", &number2);


switch (option){
case '*':
    result = number1 * number2;
    printf("Resultado: %.2f X %.2f = %.2f", number1, number2, result);
    break;

case '-':
    result = number1 - number2;
    printf("Resultado: %.2f - %.2f = %.2f", number1, number2, result);
    break;

case '+':
    result = number1 + number2;
    printf("Resultado: %.2f + %.2f = %.2f", number1, number2, result);
    break;

default:
    printf("Operação inválida");
    break;
}

    return 0;
}