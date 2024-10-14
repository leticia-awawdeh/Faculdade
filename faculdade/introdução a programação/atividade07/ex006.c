#include <stdio.h>

int main() {
    int number, evenCount = 0, oddCount = 0, evenSum = 0, oddSum = 0;
    float oddAverage;


    for (int i = 1; i <= 10; i++) {
        printf("Digite o número inteiro (%d): ", i);
            scanf("%d", &number);

        if (number % 2 == 0) {
            evenCount++;
            evenSum += number;

        } else {
            oddCount++;
            oddSum += number;

        }
    }


    if (oddCount != 0) {
        oddAverage = (float)oddSum / oddCount;

    } else {
        oddAverage = 0;

    }

    printf("Quantidade de números pares: %d\n", evenCount);
    printf("Quantidade de números ímpares: %d\n", oddCount);
    printf("Soma dos números pares: %d\n", evenSum);
    printf("Média dos números ímpares: %.2f\n", oddAverage);

    return 0;
}
