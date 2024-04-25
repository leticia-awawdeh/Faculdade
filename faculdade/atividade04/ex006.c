#include <stdio.h>

int main(){
    int number1, number2, sum, result;

    printf("Digite um número: ");
        scanf("%d", &number1);

    printf("Digite um número: ");
        scanf("%d", &number2);

    //soma o número 1 e número 2 intoduzidos pelo usuário 
    sum = number1 + number2;

    //verifica o valor da soma dos números digitados pelo usuário
    if (sum > 20){
        result = sum + 8;
        printf("A soma dos números digitados é maior que 20, portanto o resultado é %d", result);

    } else if (sum <= 20){
        result = sum - 5;
        printf("A soma dos números digitados é menor ou igual a 20, portanto o resultado é %d", result);

    } else {
        printf("Números inválidos");
        
    }
    return 0;
}