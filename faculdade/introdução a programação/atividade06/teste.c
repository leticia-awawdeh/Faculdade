#include <stdio.h>

int main() {
    int numeros[8];
    int i, contador = 0;

    // Solicitar ao usuário para inserir os 8 números
    printf("Digite 8 números:\n");
    for (i = 0; i < 8; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Verificar quantos números são menores que 15
    for (i = 0; i < 8; i++) {
        if (numeros[i] < 15) {
            contador++;
        }
    }

    // Imprimir a quantidade de números menores que 15
    printf("Quantidade de números menores que 15: %d\n", contador);

    return 0;
}
