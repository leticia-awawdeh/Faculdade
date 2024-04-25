#include <stdio.h>

int main() {
    int n = 8, number1 = 0, number2 = 1, next;

    printf("Os %d primeiros termos da sequência de Fibonacci são:\n", n);
    printf("%d - %d", number1, number2);

    for (int i = 2; i < n; i++) {
        next = number1 + number2;
        printf(" - %d", next);
        number1 = number2;
        number2 = next;
    }

    printf("\n");

    return 0;
}
