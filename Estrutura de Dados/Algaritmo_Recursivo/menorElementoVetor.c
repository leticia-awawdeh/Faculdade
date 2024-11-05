#include <stdio.h>

//Atividade Realizada por Letícia Awawdeh

int menorElemento(int vetor[], int inicio, int fim) {
    
    if (inicio == fim) {
        return vetor[inicio];
    }

    int meio = (inicio + fim) / 2;

    int menorEsquerda = menorElemento(vetor, inicio, meio);

    int menorDireita = menorElemento(vetor, meio + 1, fim);

    return (menorEsquerda < menorDireita) ? menorEsquerda : menorDireita;
}

int main() {
    int vetor[] = {5, 8, 3, 9, 1, 7, 10, -2};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int menor = menorElemento(vetor, 0, tamanho - 1);

    printf("O menor elemento do vetor é: %d\n", menor);

    return 0;
}