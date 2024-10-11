#include <stdio.h>

int main() {
    int number1, number2, sum;

    do {
        printf("Digite o primeiro número: ");
            scanf("%d", &number1);
        
        printf("Digite o segundo número: ");
          scanf("%d", &number2);
        
        sum += number1 + number2;
        
        if (sum > 15) {
            printf("A soma dos números é maior que 15. Encerrando o programa.\n");
            break;

        } else {
            printf("A soma dos números é igual a %d, que é menor que 15. Digite novos números.\n", sum);

        }
    } while (1);

    return 0;
}
