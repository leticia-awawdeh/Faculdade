#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    
    
} Node;

Node* head = NULL; // Ponteiro para o início da lista

void imprimiLista(){
     Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}

void addLista(int value){

        Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main (){
    int option, value;
    char addMore;

    while (1) {
        printf("\n1. Imprimir lista\n");
        printf("2. Adicionar novo elemento na lista\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            imprimiLista();
            break;

        case 2:
            do {
                printf("Digite o valor a ser adicionado: ");
                scanf("%d", &value);
                addLista(value);
                printf("Deseja adicionar outro elemento? (s/n): ");
                scanf(" %c", &addMore);
            } while (addMore == 's' || addMore == 'S');
            break;

        case 3:
            printf("saindo...")
            exit(0);

        default:
            printf("Opção inválida\n");
            break;
        }
    }

    return 0;
}