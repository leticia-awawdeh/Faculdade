#include <stdio.h>

int main() {
    double salary, instalment, maxLimit;

    //lê o salário bruto introduzido pelo usuário
    printf("Digite o salário bruto: ");
    scanf("%lf", &salary);

    //lê o valor da prestação que o usuário introduziu
    printf("Digite o valor da prestação: ");
    scanf("%lf", &instalment);

    //calcula o limite máximo da prestação
    maxLimit = salary * 0.30;

    //verifica se a prestação é menor ou igual ao limite máximo
    if (instalment <= maxLimit) {
        printf("Empréstimo concedido");

    } else {
        printf("O empréstimo não concedido");

    }

    return 0;
}
