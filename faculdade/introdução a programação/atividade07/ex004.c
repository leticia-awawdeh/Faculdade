#include <stdio.h>

int main() {
    int number;

    printf("Números ímpares entre 100 e 200:\n");

    for (number = 100; number <= 200; number++) {

        if (number % 2 != 0) {
            printf("%d - ", number);
        }
    }

    return 0;
}
