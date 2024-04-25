#include <stdio.h>

int main(){
    int option;
    float result, number1, number2;

    printf("1. Média");
    printf("2. Diferença");
    printf("3. Produto");
    printf("4. Divisão");
    scanf("%d", &option);

    printf("Digite o primeiro número: ");
    scanf("%d", &number1);

    printf("Digite o segundo número: ");
    scanf("%d", &number2);

    switch (option)
    {
    case 1:
    result = (number1 + number2)/2;
    printf("Resultado: %.2f", result);
        break;
    case 2:
    result = (number1 - number2);
    printf("Resultado: %.2f", result);
        break;
    case 3:
    result = number1 * number2;
    printf("Resultado: %.2f", result);
        break;
    case 4:
    result = (number1 / number2);
    printf("Resultado: %.2f", result);
        break;
    
    default:
    printf("[ERROR]");
        break;
    }
    return 0;
}