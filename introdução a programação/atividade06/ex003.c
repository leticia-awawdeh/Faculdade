#include <stdio.h>

int main(){
    int number, factorial = 1;

    printf("Digite um número: ");
        scanf("%d", &number);

    printf("%d! = ", number);

    for (int i = number; i >= 1; --i) {
        factorial *= i;
        printf("%d", i);

        if (i > 1) {
            printf(" · ");
        }
    }

    printf(" = %d.\n", factorial);

    return 0;
}