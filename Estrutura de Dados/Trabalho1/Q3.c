#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

typedef struct {
    char itens[MAX][50];
    int topo;
} Pilha;

void inicio(Pilha *p) {
    p->topo = -1;
}

int isEmpty(Pilha *p) {
    return p->topo == -1;
}

int isFull(Pilha *p) {
    return p->topo == MAX - 1;
}

void push(Pilha *p, char *action) {
    if (isFull(p)) {
        printf("\nErro: muitas ações realizadas.\n");
    } else {
        strcpy(p->itens[++(p->topo)], action);
        printf("\nAção %s registrada com sucesso!\n", action);
    }
}

char* pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: a pilha está vazia!\n");
        return NULL;
    } else {
        char *action = p->itens[(p->topo)--];
        printf("\nÚltima ação %s foi desfeita\n", action);
        return action;
    }
}

char* peek(Pilha *p) {
    if (isEmpty(p)) {
        printf("\nErro: a pilha está vazia!\n");
        return NULL;
    } else {
        return p->itens[p->topo];
    }
}

void exibir(Pilha *p) {
    if (isEmpty(p)) {
        printf("\nNenhuma ação realizada.\n");
    } else {
        printf("\nAções realizadas:\n");
        
        for (int i = 0; i <= p->topo; i++) {
            printf("%d. %s\n", i + 1, p->itens[i]); 
        }
    }
}

int main() {
    Pilha acao;
    inicio(&acao);
    int option;
    char action[50];

    do {
        printf("\nMenu de Controle de Ações no Editor de Texto\n");
        printf("1. Registrar nova ação\n");
        printf("2. Desfazer última ação\n");
        printf("3. Exibir ações realizadas\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("\nInforme a ação a ser realizada: ");
            scanf("%s", action);
            push(&acao, action);
            break;
        case 2:
            pop(&acao);
            break;
        case 3:
            exibir(&acao);
            break;
        case 4:
            printf("Saindo...\n");
            break;
        default:
            printf("[ERROR]\n");
            break;
        }
    } while (option != 4);

    return 0;
}
