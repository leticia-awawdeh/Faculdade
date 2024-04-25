#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //garante que os números sejam diferentes em cada rodada
    srand(time(NULL));

    //escolhe um número aleatório ente 1 e 100
    int secretNumber = rand() % 100 + 1;

    int guess, attempts = 0;
    int giveUp = 0;

    //loop até o jogador acertar o número
    do {
        printf("Digite um palpite entre 1 e 100, ou 0 para desistir: ");
        scanf("%d", &guess);

        if (guess == 0) {
            giveUp = 1;
            printf("Você desistiu.\n");
        } else {
            attempts++;
            if (guess < secretNumber) {
                printf("Muito baixo!\n");
            } else if (guess > secretNumber) {
                printf("Muito alto!\n");
            } else {
                printf("Correto! O número era %d.\n", secretNumber);
            }
        }
    } while (!giveUp && guess != secretNumber);

    if (!giveUp) {
        printf("Parabéns! Você adivinhou o número em %d tentativas.\n", attempts);
    }

    return 0;
}
