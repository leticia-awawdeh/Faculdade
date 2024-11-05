#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX 5

typedef struct {
    char itens[MAX][50];  
    int inicio;
    int fim;
    int quantidade;  
} Fila;

void inicializarFila(Fila* fila) {
    fila->inicio = -1;
    fila->fim = -1;
    fila->quantidade = 0;
}

int estaCheia(Fila* fila) {
    return fila->quantidade == MAX;
}

int estaVazia(Fila* fila) {
    return fila->quantidade == 0;
}

void enfileirar(Fila* fila, char nome[]) {
    if (estaCheia(fila)) {
        printf("Fila cheia!\n");
        return;
    }

    if (fila->inicio == -1) { 
        fila->inicio = 0;
    }

    fila->fim = (fila->fim + 1) % MAX;  
    strcpy(fila->itens[fila->fim], nome);  

    fila->quantidade++;
    printf("\nPaciente %s adicionado à fila.\n", nome);
}

void exibirFila(Fila* fila) {
    if (estaVazia(fila)) {
        printf("\nA fila está vazia.\n");
        return;
    }

    printf("Fila de pacientes:\n");
    int i;
    for (i = fila->inicio; i != fila->fim; i = (i + 1) % MAX) {
        printf("%s\n", fila->itens[i]);
    }
    printf("%s\n", fila->itens[fila->fim]);  
}


void desenfileirar(Fila* fila) {
    if (estaVazia(fila)) {
        printf("\nFila vazia!\n");
        return;
    }

    printf("\nPaciente %s foi atendido e removido da fila.\n", fila->itens[fila->inicio]);

    fila->inicio = (fila->inicio + 1) % MAX;  
    fila->quantidade--;

    if (estaVazia(fila)) {
        fila->inicio = -1;
        fila->fim = -1;
    }
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    int option;
    char nomePaciente[50];

    do {
        printf("\n======MENU======\n");
        printf("1. Adicionar paciente\n");
        printf("2. Chamar paciente para atendimento\n");
        printf("3. Exibir fila de pacientes\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nDigite o nome do paciente: ");
                scanf("%s", nomePaciente);
                enfileirar(&fila, nomePaciente);
                break;

            case 2:
                desenfileirar(&fila);
                break;

            case 3:
                exibirFila(&fila);
                break;

            case 0:
                printf("\nSaindo...\n");
                break;

            default:
                printf("[ERRO] Opção inválida.\n");
                break;
        }
    } while (option != 0);

    return 0;
}
