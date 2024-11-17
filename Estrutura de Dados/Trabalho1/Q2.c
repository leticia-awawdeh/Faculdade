#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 100
#define MAX_NOME 100

typedef struct {
    char nome[MAX_NOME];
    char problema[MAX_NOME];
} Cliente;

typedef struct Node {
    Cliente dados;
    struct Node* proximo;
} No;
typedef No *Pno;

typedef struct {
    No* cabeca;
    No* cauda;
    int tamanho;
} FilaDinamica;
typedef FilaDinamica *PFD;

PFD criarFila() {
    PFD novo = (PFD) malloc(sizeof(FilaDinamica));
    novo->cabeca = NULL;
    novo->cauda = NULL;
    return novo;
}

No* criarNo(Cliente dados) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    novo->dados = dados;
    novo->proximo = NULL;
    return novo;
}

Pno adiciona(PFD fila, const char* nome, const char* problema){
    if (fila == NULL) return NULL;

    Cliente cliente;
    strncpy(cliente.nome, nome, MAX_NOME);
    strncpy(cliente.problema, problema, MAX_NOME);

    Pno novo = (Pno) malloc(sizeof(No));
    novo->dados = cliente;
    novo->proximo = NULL;

    if (fila->cabeca == NULL) fila->cabeca = novo; 
    else fila->cauda->proximo = novo; 
    
    fila->cauda = novo; 
    fila->tamanho++;
    return fila->cauda; 
}

Pno remover (PFD fila, Cliente *c) {
	if (fila == NULL) return NULL; 

    Pno lixo = fila->cabeca; 
    if (fila->cabeca == NULL) return NULL; 
    
    *c = lixo->dados; 
    if (fila->cabeca == fila->cauda) fila->cauda = NULL; 
    fila->cabeca = lixo->proximo; 
	
	free(lixo); 
	return fila->cabeca; 
}

void exibirFila(Pno cabeca) {
    Pno aux;
    int i = 1; 
	for (aux = cabeca; aux != NULL; aux = aux->proximo) 
        printf("%d. Nome: %s, Problema: %s\n",i++, aux->dados.nome, aux->dados.problema); 
	printf("\n");
}

void liberarMemoria(FilaDinamica* fila){
    while (fila->cabeca) {
        No* removido = fila->cabeca;
        fila->cabeca = fila->cabeca->proximo;
        free(removido);
    }
}

int main() {
    int opcao;
    Cliente cliente;
    PFD fila = criarFila();
    
    do{
        printf("\nMenu de Controle de Chamadas do Call Center\n");
        printf("1. Registrar nova chamada\n");
        printf("2. Atender chamada\n");
        printf("3. Exibir fila de chamadas\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                char nome[MAX_NOME], problema[MAX_NOME];
                printf("\nNome do cliente: ");
                scanf("%s", &nome);
                printf("Descrição do problema: ");
                scanf("%s", &problema);
                
                adiciona(fila, nome, problema);
                printf("Chamada de %s registrada.\n", nome);
                break;
            case 2:
                remover(fila, &cliente);
                printf("\nA chamada de %s foi atendida\n", cliente.nome);
                break;

            case 3:
                exibirFila(fila->cabeca);
                break;
            case 4:
                printf("Agradecemos a preferência! Volte sempre!\nSaindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 4);
    
    liberarMemoria(fila);
    
    return 0;
}

