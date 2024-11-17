#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[100];
    struct No* prox;
} No;

No* cabeca = NULL; 

void imprimirLista() {
    int i = 1;
    if (cabeca == NULL) {
        printf("Nenhum paciente aguardando atendimento.\n");
        return;
    }

    No* temp = cabeca;
    printf("Lista de pacientes:\n");
    while (temp != NULL) {
        printf("%d. %s \n",i++, temp->nome);
        temp = temp->prox;
    }
}

void adicionarPaciente(char* nome, int urgente) {
    No* novoNo = (No*)malloc(sizeof(No));
    strcpy(novoNo->nome, nome);
    novoNo->prox = NULL;

    if (urgente) {
        novoNo->prox = cabeca;
        cabeca = novoNo;
        printf("Paciente %s adicionado ao início da lista.\n", nome);
    } else {
        if (cabeca == NULL) {
            cabeca = novoNo;
        } else {
            No* temp = cabeca;
            while (temp->prox != NULL) {
                temp = temp->prox;
            }
            temp->prox = novoNo;
        }
        printf("Paciente %s adicionado ao final da lista.\n", nome);
    }
}

void atenderPaciente() {
    if (cabeca == NULL) {
        printf("Nenhum paciente na fila para atendimento.\n");
        return;
    }

    No* pacienteAtendido = cabeca;
    printf("Paciente %s foi atendido.\n", pacienteAtendido->nome);

    cabeca = cabeca->prox;
    free(pacienteAtendido);
}

int main() {
    int option;
    char nome[100], urgente;

    do{
        printf("\nMenu de Controle de Pacientes\n");
        printf("1. Adicionar paciente\n");
        printf("2. Atender paciente\n");
        printf("3. Exibir lista de pacientes\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("Nome do paciente: ");
            scanf(" %[^\n]", nome);
            printf("Caso urgente? (S/N): ");
            scanf(" %c", &urgente);
            adicionarPaciente(nome, (urgente == 'S' || urgente == 's'));
            break;

        case 2:
            atenderPaciente();
            break;

        case 3:
            imprimirLista();
            break;

        case 4:
            printf("Obrigado por utilizar o sistema de controle de pacientes\n");
            exit(0);

        default:
            printf("Opção inválida \n");
            break;
        }
    }while (option != 4);

    return 0;
}
