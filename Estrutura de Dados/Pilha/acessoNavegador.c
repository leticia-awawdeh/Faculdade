#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

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

void push(Pilha *p, char *value) {
    if (isFull(p)) {
        printf("Erro: a pilha está cheia.\n");
    } else {
        strcpy(p->itens[++(p->topo)], value);
        printf("Acessado o site: %s\n", value);
    }
}

/*Estava ocorrendo erro por conta do tipo da função, no exemplo estava como int*/
char* pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: a pilha está vazia!\n");
        return NULL;
    } else {
        char *value = p->itens[(p->topo)--];
        printf("Voltando para o site: %s\n", value);
        return value;
    }
}

/*Estava ocorrendo erro por conta do tipo da função, no exemplo estava como int*/
char* peek(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: a pilha está vazia!\n");
        return NULL;
    } else {
        return p->itens[p->topo];
    }
}

int main() {
    Pilha historico;
    inicio(&historico);

    push(&historico, "github.com");
    push(&historico, "google.com");
    push(&historico, "wikipedia.org");

    
    pop(&historico);
    pop(&historico);

    return 0;
}
