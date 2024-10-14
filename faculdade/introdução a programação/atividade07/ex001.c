#include <stdio.h>

int main() {
    float number1, number2, number3, sum = 0;

    while (sum < 50) {
        printf("Digite o primeiro número: ");
        scanf("%f", &number1);
        
        printf("Digite o segundo número: ");
        scanf("%f", &number2);
        
        printf("Digite o terceiro número: ");
        scanf("%f", &number3);
        
        sum += number1 + number2 + number3;
        
        if (sum > 50) {
            printf("A soma dos números é maior que 50.\n");
            break;
            
        } else {
            printf("A soma dos números é  igual a %.2f, que é menor que 50. Digite novos números.\n", sum);

        }
    }

    return 0;
}
